#include <stdint.h>
#include "tm4c123gh6pm.h" 
#include "types.h"
#include "DIO.h"
#include "bitwise_operation.h"
#include "Systic_timer.h"
#include "Timer0.h"


uint32_t stack_RedBlinky[40];
uint32_t *sp_RedBlinky = &stack_RedBlinky[40];
void fun1() {
    while (1) {
      TimerEnable(TIMER0_BASE,TIMER_A);
      DIO_WritePin(&GPIO_PORTF_DATA_R,1,0);
      while((TIMER0_RIS_R & 0x01) == 0);
      setBit(TIMER0_ICR_R,0);
      DIO_WritePin(&GPIO_PORTF_DATA_R,1,1);
      while((TIMER0_RIS_R & 0x01) == 0);
      setBit(TIMER0_ICR_R,0);
    }
}


uint32_t stack_BlueBlinky[40];
uint32_t *sp_BlueBlinky = &stack_BlueBlinky[40];
void fun2() {
    while (1) {
      TimerEnable(TIMER0_BASE,TIMER_A);
      DIO_WritePin(&GPIO_PORTF_DATA_R,2,0);   
      while((TIMER0_RIS_R & 0x01) == 0);
      setBit(TIMER0_ICR_R,0);
      DIO_WritePin(&GPIO_PORTF_DATA_R,2,1);
      while((TIMER0_RIS_R & 0x01) == 0);
      setBit(TIMER0_ICR_R,0);
    }
}

void SysTick_handler(){
  
  int z = 1;
  
}

int main() {
  
  
  DIO_init();
  TimerInit();
  Systick_Init_int();
  /* fabricate Cortex-M ISR stack frame for fun1 */
    *(--sp_RedBlinky) = (1U << 24);  /* xPSR */
    *(--sp_RedBlinky) = (uint32)&fun1; /* PC */
    *(--sp_RedBlinky) = 0x000000099; /* LR  */
    *(--sp_RedBlinky) = 0x000000099; /* R12 */
    *(--sp_RedBlinky) = 0x000000099; /* R3  */
    *(--sp_RedBlinky) = 0x000000099; /* R2  */
    *(--sp_RedBlinky) = 0x000000099; /* R1  */
    *(--sp_RedBlinky) = 0x000000099; /* R0  */
    

    /* fabricate Cortex-M ISR stack frame for fun2 */
    *(--sp_BlueBlinky) = (1U << 24);  /* xPSR */
    *(--sp_BlueBlinky) = (uint32)&fun2; /* PC */
    *(--sp_BlueBlinky) = 0x000000088; /* LR  */
    *(--sp_BlueBlinky) = 0x000000088; /* R12 */
    *(--sp_BlueBlinky) = 0x000000088; /* R3  */
    *(--sp_BlueBlinky) = 0x000000088; /* R2  */
    *(--sp_BlueBlinky) = 0x000000088; /* R1  */
    *(--sp_BlueBlinky) = 0x000000088; /* R0  */
  
   

    while (1) {
    }

    return 0;
}