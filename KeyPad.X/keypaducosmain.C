///////////////////////////////////////////////////////////////////
//Student ID No.:814007815
//Date: 28/10/2017
///////////////////////////////////////////////////////////////////
#include    "includes.h"
#include    <timers.h>
#include    <xlcd.h>
#include    <delays.h>
#include    <string.h>
#include    <stdlib.h>

//static char taskA_welcome[17L]="Task 1 rocks! \n";
//static char taskB_welcome[17L]="Task 2 rules?";
unsigned char stopped = 0;

INT8U err;
OS_EVENT *LCDSem;
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

void keypadinput(void){
    if (!PORTDbits.RD3 && !PORTCbits.RC4 && !PORTCbits.RC5  && !PORTCbits.RC6)
    {
        while(BusyXLCD());
        SetDDRamAddr(0x00);
        Delay1KTCYx(20);
        putrsXLCD("1");
    }
    if (PORTDbits.RD3 && !PORTCbits.RC4 && !PORTCbits.RC5  && !PORTCbits.RC6)
    {
        while(BusyXLCD());
        SetDDRamAddr(0x00);
        Delay1KTCYx(20);
        putrsXLCD("2");
    }
    if (!PORTDbits.RD3 && PORTCbits.RC4 && !PORTCbits.RC5  && !PORTCbits.RC6)
    {
        while(BusyXLCD());
        SetDDRamAddr(0x00);
        Delay1KTCYx(20);
        putrsXLCD("3");
    }
    if (PORTDbits.RD3 && !PORTCbits.RC4 && PORTCbits.RC5  && !PORTCbits.RC6)
    {
        while(BusyXLCD());
        SetDDRamAddr(0x00);
        Delay1KTCYx(20);
        putrsXLCD("A");
    }
    if (!PORTDbits.RD3 && !PORTCbits.RC4 && PORTCbits.RC5  && !PORTCbits.RC6)
    {
        while(BusyXLCD());
        SetDDRamAddr(0x00);
        Delay1KTCYx(20);
        putrsXLCD("4");
    }
    if (PORTDbits.RD3 && !PORTCbits.RC4 && PORTCbits.RC5  && !PORTCbits.RC6)
    {
        while(BusyXLCD());
        SetDDRamAddr(0x00);
        Delay1KTCYx(20);
        putrsXLCD("5");
    }
    if (!PORTDbits.RD3 && PORTCbits.RC4 && PORTCbits.RC5  && !PORTCbits.RC6)
    {
        while(BusyXLCD());
        SetDDRamAddr(0x00);
        Delay1KTCYx(20);
        putrsXLCD("6");
    }
    if (PORTDbits.RD3 && PORTCbits.RC4 && PORTCbits.RC5  && !PORTCbits.RC6)
    {
        while(BusyXLCD());
        SetDDRamAddr(0x00);
        Delay1KTCYx(20);
        putrsXLCD("B");
    }
    if (!PORTDbits.RD3 && !PORTCbits.RC4 && !PORTCbits.RC5  && PORTCbits.RC6)
    {
        while(BusyXLCD());
        SetDDRamAddr(0x00);
        Delay1KTCYx(20);
        putrsXLCD("7");
    }
    if (PORTDbits.RD3 && !PORTCbits.RC4 && !PORTCbits.RC5  && PORTCbits.RC6)
    {
        while(BusyXLCD());
        SetDDRamAddr(0x00);
        Delay1KTCYx(20);
        putrsXLCD("8");
    }
    if (!PORTDbits.RD3 && PORTCbits.RC4 && !PORTCbits.RC5  && PORTCbits.RC6)
    {
        while(BusyXLCD());
        SetDDRamAddr(0x00);
        Delay1KTCYx(20);
        putrsXLCD("9");
    }
    if (PORTDbits.RD3 && PORTCbits.RC4 && !PORTCbits.RC5  && PORTCbits.RC6)
    {
        while(BusyXLCD());
        SetDDRamAddr(0x00);
        Delay1KTCYx(20);
        putrsXLCD("C");
    }
    if (!PORTDbits.RD3 && !PORTCbits.RC4 && PORTCbits.RC5  && PORTCbits.RC6)
    {
        while(BusyXLCD());
        SetDDRamAddr(0x00);
        Delay1KTCYx(20);
        putrsXLCD("0");
    }
    if (PORTDbits.RD3 && !PORTCbits.RC4 && PORTCbits.RC5  && PORTCbits.RC6)
    {
        while(BusyXLCD());
        SetDDRamAddr(0x00);
        Delay1KTCYx(20);
        putrsXLCD("F");
    }
    if (!PORTDbits.RD3 && PORTCbits.RC4 && PORTCbits.RC5  && PORTCbits.RC6)
    {
        while(BusyXLCD());
        SetDDRamAddr(0x00);
        Delay1KTCYx(20);
        putrsXLCD("E");
    }
    if (PORTDbits.RD3 && PORTCbits.RC4 && PORTCbits.RC5  && PORTCbits.RC6)
    {
        while(BusyXLCD());
        SetDDRamAddr(0x00);
        Delay1KTCYx(20);
        putrsXLCD("D");
    }
    
}


void appISR(void){
    
     if(INTCON3bits.INT1IF){
        INTCON3bits.INT1IF = 0;
		keypadinput();
        OSSemPost(LCDSem);

	}
}

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

/* Write the appropriate code to do the following:
* define the stack sizes for task1 and task2 in app_cfg.h file
* use the defines to assign stack sizes here.
*/
OS_STK TaskAStk[TaskAStkSize];
//OS_STK TaskBStk[TaskBStkSize];

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
    //TRISBbits.TRISB1 = 0;  //Configure PORTB pin 1 as an output
    // task loop - TaskA will loop until the global variable stopped is set.
    while (stopped == 0)
    {
        OSSemPend(LCDSem, 0, &err);
        while(BusyXLCD());              // Wait if LCD busy
      //  SetDDRamAddr(0x0);                // Set Display data ram address to 0
       // putsXLCD(taskA_welcome);
      //  PORTBbits.RB1 = !PORTBbits.RB1;
        //https://doc.micrium.com/display/osiidoc/Time+Management
       OSTimeDlyHMSM ( 0, 0, 1, 0); //-- delay for 1 second using OSTimeDlyHMSM( )
        WriteCmdXLCD(0b00000001);
        OSSemPost(LCDSem);

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

//void TaskB(void *pdata)
//{
//
//    TRISBbits.TRISB2 = 0;  //Configure PORTB pin 2 as an output
//    // task loop - TaskB will loop until the global variable stopped is set.
//    while (stopped == 0)
//    {
//        OSSemPend(LCDSem, 0, &err);
//        while(BusyXLCD());              // Wait if LCD busy
//        SetDDRamAddr(0x11);                // Set Display data ram address to 0
//        putsXLCD(taskB_welcome);
//        PORTBbits.RB2 = !PORTBbits.RB2;//-- toggle PORTB pin 2
//        //https://doc.micrium.com/display/osiidoc/Time+Management
//        
//        
//        OSSemPend(CountSem, 0, &err);
//        //OSTimeDly(200); //-- delay of 200 ticks using OSTimeDly( )
//        WriteCmdXLCD(0b00000001);
//        OSSemPost(LCDSem);
//
//
//    }
//    OSTaskDel(OS_PRIO_SELF); // TaskB will delete itself if the loop is exited.
//    
//}



void main (void)
{
    // Write the appropriate code to disable all interrupts
    INTCONbits.GIEH = 0;
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
    
    OpenTimer1(TIMER_INT_ON & T1_16BIT_RW & T1_SOURCE_INT & T1_PS_1_4 & T1_OSC1EN_ON & T1_SYNC_EXT_OFF);
    WriteTimer1(0x3BE0);
    /* Write the appropriate code to define the priorities for taskA
    * and taskB in app_cfg.h. Use these defines to assign priorities
    * when creating taskA and taskB with OSTaskCreate( )
    */
    //OSTaskCreate(LCDTask, (void *)0, &LCDTaskStk[0], 1);
    OSTaskCreate(TaskA, (void *)0, &TaskAStk[0], TaskAPrio); //Creating TaskA Task
   // OSTaskCreate(TaskB, (void *)0, &TaskBStk[0], TaskBPrio); //Creating TaskB Task
    LCDSem = OSSemCreate(1);
    
    INTCONbits.GIEH = 1;
    INTCON3bits.INT1IE = 1;
    INTCON3bits.INT1IF = 0;
    TRISBbits.TRISB1 = 1;
    TRISDbits.RD3 = 1;
    TRISCbits.RC4 = 1;
    TRISCbits.RC5 = 1;
    TRISCbits.RC6 = 1;
    
  //  CountSem = OSSemCreate(0);
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