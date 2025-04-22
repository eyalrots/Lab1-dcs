#include  "../header/bsp4.h"    // private library - BSP layer
//-----------------------------------------------------------------------------  
//           GPIO congiguration
//-----------------------------------------------------------------------------

void GPIOconfig(void){
 // volatile unsigned int i; // in case of while loop usage
  
  WDTCTL = WDTHOLD | WDTPW;		// Stop WDT
   
  // LEDs 8-bit Array Port configuration
  LEDsArrPortSel &= ~0xFF;            // GPIO capability
  LEDsArrPortDir |= 0xFF;             // output dir
  LEDsArrPort = 0x00;				          // clear all LEDs
  
  // P2forWave(out) Setup
  P2WaveSel &= ~0x80;     // GPIO capability
  P2WaveDir |= 0x80;     // output direction
  
  // PushButtons Setup
  PBsArrPortSel &= ~0x0F;          // GPIO capability
  PBsArrPortDir &= ~0x0F;          // input direction
  PBsArrIntEdgeSel |= 0x03;  	     // pull-up mode
  PBsArrIntEdgeSel &= ~0x0C;         // pull-down mode
  PBsArrIntEn |= 0x07;
  PBsArrIntPend &= ~0x0F;            // clear pending interrupts 
  
  _BIS_SR(GIE);                     // enable interrupts globally
}                             
//------------------------------------------------------------------------------------- 
//            Timers congiguration 
//-------------------------------------------------------------------------------------
void TIMERconfig(void){
	
	//write here timers congiguration code
} 
//------------------------------------------------------------------------------------- 
//            ADC congiguration 
//-------------------------------------------------------------------------------------
void ADCconfig(void){
	
	//write here ADC congiguration code
}              

           
             

 
             
             
            
  

