///////////////////////////////////////////////////////////////////
//Student ID No.:814007815
//Date: 28/10/2017
///////////////////////////////////////////////////////////////////
#include    "includes.h"
#include    <timers.h>
#include    <xlcd.h>
#include    <delays.h>
#include    <string.h>
#include    <float.h>
#include    <stdlib.h>
#include    "ow.h"
#include    <stdio.h>

//Temp Variables
unsigned char mbyte=0;
unsigned char lbyte=0;
unsigned char sign=0;

float tempfloat = 0;

unsigned int tempint = 0;
unsigned int tempfractint = 0;
 

//HR Variables
int Reading=1;
int Timer1Count=0;    //# of times Timer1 Overflows
int BlockCounter=0;   //Cancel readings within 300ms
int RB6Counter=0;     // Amount of Rising edges on pin


unsigned char stopped = 0;

INT8U err;
OS_EVENT *TaskSem;
OS_EVENT *CountSem;


/* Write the appropriate code to set configuration bits:
* - set HS oscillator
* - disable watchdog timer
* - disable low voltage programming
*/
/* Set configuration bits for use with PICKIT3 */
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

/* Write LCD delay functions */
// functions required for XLCD
// min of 18 Tcy
void DelayFor18TCY(void)
{
    Delay10TCYx(2L);
}

// min of 15ms
void DelayPORXLCD(void)
{
    Delay1KTCYx(15L);
}

// min of 5ms
void DelayXLCD(void)
{
    Delay1KTCYx(5L);
}

void appISR(void){
    
   INTCONbits.GIE=0;
    if(INTCONbits.INT0IF==1)              
    {
        if(Reading==1)
        {                                 
            RB6Counter++;
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
    
    
    OSSemPost(TaskSem);

    
}


//HR functions
int BPMfunction()
{
    int BPMfunctionvar = 0;
    BPMfunctionvar = RB6Counter*12;
    return BPMfunctionvar;
}


//Temp Functions
void reset(void){
    tempint = 0;
    tempfractint = 0.0;
}
 
void fractional(void){
    unsigned char fract;
    unsigned char temp_fractional;
    unsigned char i = 0;
    unsigned char z = 1;
    fract = lbyte & 0x0F;             //remain only with the fraction
    while(i < 4)
    {
        temp_fractional = fract % 10;       
        tempfloat = (temp_fractional * (0.0625*z))+ tempfloat; //Converts binary to decimal
        z=z*2;
        fract = fract/10;               //last digit is truncated
        i++;
    }   
    tempfractint = tempfloat*1000;
    tempfractint = tempfractint/100;
}
 
void integeral(void){
    unsigned char temp_integeral = 0;
    unsigned char i = 0;
    unsigned char temp_int=0;
    
    temp_integeral = lbyte >>4;             //Shift bit7:bit4 down 4 places to the right.
    temp_int = temp_integeral | temp_int;     //Bitwise OR temp with int_temp, therefore int_temp = temp
    temp_integeral = mbyte << 4;            //Shift least significant 3 bits(bit10:bit8) up 4 places to the left to prepare for bitwise OR to combine bit11:bit8 and bit7:bit4.
    temp_int = temp_integeral | temp_int;     //Bitwise OR temp with int_temp,therefor int_temp = temp
    if(sign>0){                    //Check if number is negative
       temp_int = temp_int ^ 0x7F; //Toggle bits if negative
    }
    tempint = temp_int;
}
 
void display(void){
    
    char displayarr[15];
    sprintf(displayarr,"TEMP(C):%d.%d",tempint,tempfractint);
    while(BusyXLCD() );
    SetDDRamAddr( 0x00 );
    putsXLCD(displayarr);  
}


/* Write the appropriate code to do the following:
* define the stack sizes for task1 and task2 in app_cfg.h file
* use the defines to assign stack sizes here.
*/
OS_STK TaskAStk[TaskAStkSize];
OS_STK TaskBStk[TaskBStkSize];

/* Write the appropriate code to do the following:
* Configure PORTB pin 1 as an output
* TaskA will loop until the global variable stopped is set.
* Within the loop -- print string "Task 1 rocks! \n" to LCD top row
* -- toggle PORTB pin 1
* -- delay for 1 second using OSTimeDlyHMSM( )
* TaskA will delete itself if the loop is exited.
*/
void TaskA(void *pdata)
{
     int x;
    TRISBbits.TRISB3 = 0;  //Configure PORTB pin 1 as an output

  
     while(1){
        OSSemPend(TaskSem, 0, &err);
        ow_reset();
        ow_write_byte(0xCC);    
        ow_write_byte(0x44);    
        PORTBbits.RB3 = !PORTBbits.RB3;

        PORTEbits.RE2 = 1;        //Transistor switched on
        
         for( x = 1; x<=8;x++)  // Conversion time
         { 
           Delay1KTCYx(100);
         }
        
        PORTEbits.RE2 = 0;       //Turn off transistor
        
        ow_reset();
        ow_write_byte(0xCC);
        ow_write_byte(0xBE);    
        lbyte = ow_read_byte();
        mbyte = ow_read_byte();
        
        fractional();
        integeral();
        display();
        reset();
        OSSemPost(TaskSem);
        OSTimeDlyHMSM ( 0, 0, 1, 0);
    }
    
    
    OSTaskDel(OS_PRIO_SELF); // TaskA will delete itself if the loop is exited.
    

}

/* Write the appropriate code to do the following:
* Configure PORTB pin 2 as an output
* TaskB will loop until the global variable stopped is set.
* Within the loop -- print string "Task 2 rules?\n" to LCD bottom row
* -- toggle PORTB pin 2
* -- delay of 200 ticks using OSTimeDly( )
* TaskB will delete itself if the loop is exited.
*/
void TaskB(void *pdata)
{
    char BeatsPMOut[3];
    int BeatsPerMin=0;
   TRISBbits.TRISB4 = 0;
   while(1)
    {       
       OSSemPend(TaskSem, 0, &err);
       OSSemPend(CountSem, 0 , &err);
        PORTBbits.RB4 = !PORTBbits.RB4;

        if(BlockCounter==3)
        {
            Reading=1;
            BlockCounter=0;
        }
        
        if(Timer1Count==50)
        {      
            PORTCbits.RC2=! PORTCbits.RC2;
            BeatsPerMin=BPMfunction();
            itoa(BeatsPerMin,BeatsPMOut);

            while(BusyXLCD());
            //WriteCmdXLCD(0b00000001);


            while(BusyXLCD());
            SetDDRamAddr( 0x40 );
            putrsXLCD("BPM:");
            
            while(BusyXLCD());
            SetDDRamAddr( 0x45 );
            putsXLCD(BeatsPMOut);

            Timer1Count=0;
            RB6Counter=0;
            
            OSTimeDlyHMSM ( 0, 0, 1, 0);
            
            
            
        }
        
    }
    
    OSTaskDel(OS_PRIO_SELF); // TaskB will delete itself if the loop is exited.
    
}



void main (void)
{
    char BeatsPMOut[3];
    int BeatsPerMin=0;
    // Write the appropriate code to disable all interrupts
    INTCONbits.GIEH = 0;
    
    TRISEbits.RE2 = 0;          // Output for Transistor 
    PORTEbits.RE2 = 0;  
    // Pin config
    TRISCbits.RC2=0;
    TRISBbits.RB0=1;
    TRISCbits.RC0=0;
    PORTC=0x00;     
    INTCONbits.INT0IE=1;
    INTCON2bits.INTEDG0=1;
    
    
    INTCONbits.GIE=1;
   
    
    // Write the appropriate code to initialise uC/OS II kernel
    OSInit();
    /* Write the appropriate code to enable timer0,
    * using 16 bit mode on internal clk source and pre-scalar of 1.
    */
    OpenTimer0(TIMER_INT_ON & T0_16BIT & T0_SOURCE_INT & T0_PS_1_1);
    /* Write the appropriate code to set timer0 registers
    * such that timer0 expires at 10ms using 4 Mhz oscillator.
    * Do the same in vectors.c in CPUlowInterruptHook( ).
    */
    WriteTimer0(4377);
    
    
   OpenTimer3(TIMER_INT_ON & T3_16BIT_RW & T3_SOURCE_INT & T0_PS_1_8 &T3_SYNC_EXT_OFF);
    WriteTimer3(52992);
    RCONbits.IPEN = 1; 
    
    /* Write the appropriate code to define the priorities for taskA
    * and taskB in app_cfg.h. Use these defines to assign priorities
    * when creating taskA and taskB with OSTaskCreate( )
    */
    //OSTaskCreate(LCDTask, (void *)0, &LCDTaskStk[0], 1);
    OSTaskCreate(TaskA, (void *)0, &TaskAStk[0], TaskAPrio); //Creating TaskA Task
    OSTaskCreate(TaskB, (void *)0, &TaskBStk[0], TaskBPrio); //Creating TaskB Task
    TaskSem = OSSemCreate(1);
    CountSem = OSSemCreate(0);
    // Initialize the LCD display
    OpenXLCD(FOUR_BIT & LINES_5X7);
    while(BusyXLCD());
    WriteCmdXLCD(DON & CURSOR_OFF & BLINK_OFF); // display on
    while(BusyXLCD());
    WriteCmdXLCD(0b00000001); // display clear
    while(BusyXLCD());
    WriteCmdXLCD(ENTRY_CURSOR_INC & ENTRY_DISPLAY_NO_SHIFT); // entrymode
    // Write the appropriate code to start uC/OS II kernel
    OSStart();
}
