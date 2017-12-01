#include <p18cxxx.h>
#include <pwm.h>
#include <timers.h>
#include <delays.h> 

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#define XTAL_FREQ  4000000
 
void main(void)
 
{
    TRISCbits.TRISC2 = 0;
    SetDCPWM1(30);
    OpenTimer2(TIMER_INT_OFF & T2_PS_1_16 & T2_POST_1_1);
    while(1)
    {
     
      OpenPWM1(0x7E);      
    }
    Sleep(); 
}