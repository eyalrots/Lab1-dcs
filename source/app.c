#include "../header/app.h"

volatile FSM_state_t state;
volatile SYS_mode_t lpm_mode;

void main(void)
{
  //INIT STATES:
  state = state0;
  lpm_mode = mode0;
  val1 = 0x00;
  val2 = 0x00;
  dir1 = 0x00;
  dir3 = 0xff;
  sysConfig();
  enable_interrupts();

  while(1){
    switch(state){
      case state0:
        clrLEDs();
        enterLPM(0x00);
        break;
      case state1:
        countLED();
        if (dir1 == 0x00)
          dir1 = 0x01;
        else
          dir1 = 0x00;
        state=state0;
        break;
      case state2:
        skipLED(val2);
        state=state0;
        break;
      case state3:
        wave();
        break;
      default:
        state=state0;
        break;
    }
  }
}

// // interrupt hundling
// //Port 2 interrupt service routine
// void __attribute__((interrupt(PORT2_VECTOR))) PBs_handler(void);

// volatile FSM_state_t state = state0;

// int main(void)
// {
//   volatile unsigned int i;
//   sysConfig();
//   state = state1;
//   while(1)
//   {
//     P1OUT ^= 0xff;                        // Toggle P1.0 using exclusive-OR

//     for (i=10000; i>0; i--);
//   }
// }
