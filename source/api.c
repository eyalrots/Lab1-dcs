#include  "../header/api.h"    		// private library - API layer
//-------------------------------------------------------------
//   count up if dor==0 else down, start from start variable
//-------------------------------------------------------------

void countLED(){
	disable_interrupts();
	volatile unsigned int i;

	for (i=20; i > 0; i--){
		if (dir1 == 0x00){
			if (val1 == 0xff)
				val1 = 0x00;
			else
				val1++;
		}
		if (dir1 == 0x01){
			if (val1 == 0x00)
				val1 = 0xff;
			else
				val1--;
		}
		print2LEDs(val1);
		delay(60000);
	}
	enable_interrupts();
}
//--------------------------------------------------------------------
//            light up leds periodicaly for 7 seconds
//--------------------------------------------------------------------            
void skipLED(){
	disable_interrupts();
	volatile unsigned int i;
	for (i = 14; i > 0; i--){
		if (val2 == 0x00)
			val2 = 0x01;
		else
			val2 = val2 << 1;
		print2LEDs(val2);
		delay(60000);
	}
	enable_interrupts();
}
//--------------------------------------------------------------------
//     state 3: generate ones cycle of the wave - dependent on dir
//--------------------------------------------------------------------  

void wave(){
	volatile unsigned int i;
	if (dir3 == 0x00){
		for (i=3; i>0; i--){
			write2Wave(0x80);
			delay(3);
		}
		write2Wave(0x00);
		_no_operation();
		_no_operation();
		_no_operation();
	}
	else{
		write2Wave(0x80);
		delay(8);
		for (i=3; i>0; i--){
			write2Wave(0x00);
			delay(8);
		}
		
	}
}

 
  

