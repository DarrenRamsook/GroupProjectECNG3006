#include<p18f452.h>
#include<timers.h>
#include<delays.h>
#include"xlcd.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include <pwm.h>



#pragma config  OSC=HS
#pragma config  LVP=OFF
#pragma config  WDT=OFF
#define XTAL_FREQ  4000000

/*
 * The counter will be incremented whenever the person's heart pulse breaks the IR light. This break causes a peak to the input of the pic. 
 * Timer 3 will be configured as a timer that overflows every 100ms. Every overflow will increment a counter. When the counter reaches 100; 
 * The value within Timer 1 will be the amount of Heart pulses within 10 seconds. This value will then be multiplied by 6 to give the heartrate per min.
 */


void DelayFor18TCY( void )
{

    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
    Delay10TCYx(1);
}

void DelayPORXLCD (void)
{
 Delay10KTCYx(6);
}

void DelayXLCD (void)
{
 Delay10KTCYx(2); 
}


void low_isr(void);
void high_isr(void);


/*Variables Declaration*/

int Reading=1;
int Timer1Count=0;    //# of times Timer1 Overflows
int BlockCounter=0;   //Cancel readings within 300ms
int RB6Counter=0;     // Amount of Rising edges on pin
int k = 0;

#pragma code low_vector=0x18
void interrupt_at_low_vector(void)
{
    _asm
    goto low_isr
    _endasm
}
#pragma code        

#pragma interruptlow low_isr
void low_isr(void)
{ 

    
}

#pragma code high_vector=0x08
void interrupt_at_high_vector(void)
{
    _asm
    goto high_isr
    _endasm
}
#pragma code

#pragma interrupt high_isr
void high_isr(void)
{
    
    INTCONbits.GIE=0;
    if(INTCONbits.INT0IF==1)              
    {
        if(Reading==1)
        {                                 
            RB6Counter++;
//            OpenPWM1(0x7E);
//            Delay10KTCYx(6);
//            ClosePWM1();
            PORTCbits.RC0=!PORTCbits.RC0; 
            Reading=0;
        }   
        INTCONbits.INT0IF=0;
    }
    if(PIR2bits.TMR3IF==1)              
    {
        PORTCbits.RC3=! PORTCbits.RC3;

        PIR2bits.TMR3IF=0;   
        WriteTimer3(52992);
        Timer1Count++;
        BlockCounter++;
    }
    INTCONbits.GIE=1;
}


int BPMfunction()
{
    int BPMfunctionvar = 0;
    BPMfunctionvar = RB6Counter*12;
    return BPMfunctionvar;
}

void speakeralert()
{   
    
    OpenPWM1(0x7E);
    Delay10KTCYx(3);
    ClosePWM1();
    Delay10KTCYx(2);

    
}

void main(void)
{
    char BeatsPMOut[3];
    int BeatsPerMin=0;
 
    
    //Timer Config
    OpenTimer3(TIMER_INT_ON & T3_16BIT_RW & T3_SOURCE_INT & T0_PS_1_8 &T3_SYNC_EXT_OFF);
    WriteTimer3(52992);
    RCONbits.IPEN = 1;  
    
    //LCD Config
    OpenXLCD( FOUR_BIT & LINES_5X7 );
    while( BusyXLCD() );
    WriteCmdXLCD( FOUR_BIT & LINES_5X7 );
    while( BusyXLCD() );
    WriteCmdXLCD( BLINK_ON );
    while( BusyXLCD() );
    WriteCmdXLCD( SHIFT_DISP_LEFT );
    
    // Pin config
    TRISCbits.RC2=0;
    TRISBbits.RB0=1;
    TRISCbits.RC0=0;
    PORTC=0x00;     
    INTCONbits.INT0IE=1;
    INTCON2bits.INTEDG0=1;
    
    //Speaker COnfig 
    TRISCbits.TRISC2 = 0;
    SetDCPWM1(60);
    OpenTimer2(TIMER_INT_OFF & T2_PS_1_16 & T2_POST_1_1);
    
    
    INTCONbits.GIE=1;
   
    while(1)
    {
        if(BlockCounter==3)
        {
            Reading=1;
            BlockCounter=0;
        }
        
        if(Timer1Count==50)//SHOULD BE 50
        {      
            PORTCbits.RC2=! PORTCbits.RC2;
            BeatsPerMin=BPMfunction();
            itoa(BeatsPerMin,BeatsPMOut);
            
            if(((BeatsPerMin < 40) || (BeatsPerMin >140)) ){
                speakeralert();
                speakeralert();
                speakeralert();
            }
            while(BusyXLCD());
            WriteCmdXLCD(0b00000001);

            while(BusyXLCD());
            SetDDRamAddr( 0x00 );
            putrsXLCD("BPM:");
            
            while(BusyXLCD());
            SetDDRamAddr( 0x40 );
            putsXLCD(BeatsPMOut);
            
            

            Timer1Count=0;
            RB6Counter=0;
            
        }
        
    }
}
