#ifndef _bsp_H_
#define _bsp_H_

// #include  <msp430g25532.h>          // MSP430x2xx
#include  <msp430xG46x.h>  // MSP430x4xx

#define   debounceVal      250 //dont know
#define   LEDs_SHOW_RATE   0xFFFF  // 62_5ms

// LEDs abstraction
#define LEDsArrPort        P9OUT
#define LEDsArrPortDir     P9DIR
#define LEDsArrPortSel     P9SEL

// P2(out) abstraction
#define P2Out          P2OUT
#define P2Dir     	   P2DIR
#define P2Sel          P2SEL
#define P2Mask         0xf0

// PushButtons abstraction
#define PBsArrPort	       P2IN 
#define PBsArrIntPend	   P2IFG 
#define PBsArrIntEn	       P2IE
#define PBsArrIntEdgeSel   P2IES
#define PBsArrPortSel      P2SEL 
#define PBsArrPortDir      P2DIR 
#define PB0                0x01
#define PB1                0x02
#define PB2                0x04
#define PB3                0x08


extern void GPIOconfig(void);
extern void TIMERconfig(void); //no need for this assignment
extern void ADCconfig(void);   //no need for this assignment

typedef enum {
	state0,
	state1,
	state2,
	state3,
	state4
}FSM_state_t;

typedef enum {
	mode0,
	mode1,
	mode2,
	mode3,
	mode4
}SYS_mode_t;

#endif



