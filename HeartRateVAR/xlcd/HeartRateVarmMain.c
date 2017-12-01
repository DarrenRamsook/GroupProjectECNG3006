#include<p18f452.h>
#include<timers.h>
#include<delays.h>
#include"xlcd.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<capture.h>
#include<math.h>
#include<float.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#define _XTAL_FREQ 4000000UL

unsigned int rising = 0,i = 0,capture1 = 0,capture2 = 0, overflowamt = 0, spacing = 0,NNval = 0;
unsigned int previousval = 0, NN50val = 0, finish = 0;
float HRV = 0.0;

#pragma code high_vector=0x08
void interrupt_at_high_vector(void)
{
  _asm  _endasm
}
 
#pragma code


#pragma interrupt high_isr
void high_isr(void){
    float isrtemp = 0;
    if(PIR1bits.CCP1IF == 1){
       PIR1bits.CCP1IF = 0;
       if(rising == 0){
           if (i ==0){
               capture1 = ReadCapture1();
           }
           else{
               capture2 = ReadCapture1();
           }
          if((rising = 1) & (i ==0)){
               capture2 = ReadCapture1();
           }
           rising++;
           if((i ==0)|(rising ==1)){
               i =1;
               spacing = 65536*overflowamt+capture2-capture1;
               NNval++;
               previousval = capture2;
               capture1 = previousval;
               isrtemp = (float)spacing / (float)1000;
               if((float)isrtemp > (float)50){
                   NN50val++;
               }
               rising = 0;
               if(NNval >10){
                   HRV = (float)NN50val/(float)10;
                   HRV = HRV*100;
                   finish = 1;
                   CloseCapture1();
                   CloseTimer1();
               }
           }
       }
       
       
    }
    if(PIR1bits.TMR1IF =1){
        PIR1bits.TMR1IF = 0;
        overflowamt++;
    }
}

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


void set_val(void){
    int integer=0,decimal=0;
    char y[16];
    integer = HRV;
    decimal = (HRV - integer)*10000;
    sprintf(y,"HRV: %d%",integer);
    while( BusyXLCD() );
    SetDDRamAddr( 0x00 );
    putsXLCD(y);
    Delay10KTCYx(0x26);
}



void main(){
    
    RCONbits.IPEN =   1;           
    PIR1bits.CCP1IF = 0;             
    IPR1bits.CCP1IP = 1;            
    IPR1bits.TMR1IP = 1;             
    PIE1bits.TMR1IE = 1;             
    PIR1bits.TMR1IF=0;                              
    TRISCbits.RC1 = 1; 
    
    OpenTimer1(TIMER_INT_ON & T1_16BIT_RW & T1_PS_1_1 & T1_OSC1EN_OFF & T1_SYNC_EXT_OFF & T1_SOURCE_INT & T1_SOURCE_CCP ); 
    OpenCapture1(CAPTURE_INT_ON & C1_EVERY_RISE_EDGE);    

    OpenXLCD( FOUR_BIT & LINES_5X7 );
    while( BusyXLCD() );
    WriteCmdXLCD( FOUR_BIT & LINES_5X7 );
    while( BusyXLCD() );
    WriteCmdXLCD( SHIFT_DISP_LEFT );
    
    while(1){
       if(finish==1){
          set_val();
       }  
    }   
}