#include  "../header/bsp.h"    // private library - BSP layer
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
  P2Sel &= ~0xf0;     // GPIO capability
  P2Dir |= 0xf0;     // output direction
  
  // PushButtons Setup
  PBsArrPortSel &= ~0x0F;          // GPIO capability
  PBsArrPortDir &= ~0x0F;          // input direction
  PBsArrIntEdgeSel |= 0x03;  	     // pull-up mode
  PBsArrIntEdgeSel &= ~0x0C;         // pull-down mode
  PBsArrIntEn |= 0x0f;
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

           
             

 
             
             
            
  

