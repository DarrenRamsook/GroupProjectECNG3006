#include <p18f452.h>
#include <delays.h>
#include "xlcd.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "ow.h"
 
#pragma config WDT = OFF 
#pragma config LVP = OFF 
#define _XTAL_FREQ 4000000UL
 
unsigned char mbyte=0;
unsigned char lbyte=0;
unsigned char sign=0;

float tempfloat = 0;

unsigned int tempint = 0;
unsigned int tempfractint = 0;
 
void DelayFor18TCY(void){
    Delay10TCYx(2L);
}
 
void DelayPORXLCD(void){ 
    Delay1KTCYx(15L);
}
 
void DelayXLCD(void){   
    Delay1KTCYx(5L);
}
 
void reset(void){
    tempint = 0;
    tempfractint = 0.0;
}
 
void fractional(void){//remains with the fracitonal part alone
    unsigned char fract;
    unsigned char temp_fractional;
    unsigned char i = 0;
    unsigned char z = 1;
    fract = lbyte & 0x0F; 
    tempfloat = 0;
    while(i < 4)
    {
        temp_fractional = fract % 10;       
        tempfloat = (temp_fractional * (0.0625*z))+ tempfloat; //Converts binary to decimal
        z=z*2;
        fract = fract/10;               //last digit is truncated
        i++;
    }   
    tempfractint = tempfloat*1000;
    fract = 0;
}
 
void integeral(void){
    unsigned char temp_integeral = 0;
    unsigned char i = 0;
    unsigned char temp_int=0;
    
    temp_integeral = lbyte >>4;            
    temp_int = temp_integeral | temp_int;     // OR temp_int & temp_integral 
    temp_integeral = mbyte << 4;            
    temp_int = temp_integeral | temp_int;     //temp_int =  tempintegral
    if(sign>0){                    
       temp_int = temp_int ^ 0x7F;  // Toggle if negative
    }
    tempint = temp_int;
}
 
void display(void){
    
    char displayarr[15];
    sprintf(displayarr,"TEMP(C):%d.%d",tempint,tempfractint);
    while( BusyXLCD() );
    SetDDRamAddr( 0x00 );
    putsXLCD(displayarr);  
}

void main(void){
    int x;
    
    OpenXLCD( FOUR_BIT & LINES_5X7 );
    while( BusyXLCD() );
    WriteCmdXLCD( FOUR_BIT & LINES_5X7 );
    while( BusyXLCD() );
    while( BusyXLCD() );
    WriteCmdXLCD( SHIFT_DISP_LEFT );
    
    TRISEbits.RE2 = 0;          // Output for Transistor 
    PORTEbits.RE2 = 0;          
    
    while(1){
        
        ow_reset();
        ow_write_byte(0xCC);    
        ow_write_byte(0x44);    
        
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
    }
}