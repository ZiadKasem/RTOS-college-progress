#include "Timer0.h"
#include "DIO.h"
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
void fun3() {
    while (1) {
      TimerEnable(TIMER0_BASE,TIMER_A);
      
      
      
      
      DIO_WritePin(&GPIO_PORTF_DATA_R,3,0);
      
      while((TIMER0_RIS_R & 0x01) == 0);
      setBit(TIMER0_ICR_R,0);
      
      
      DIO_WritePin(&GPIO_PORTF_DATA_R,3,1);
      
      
      while((TIMER0_RIS_R & 0x01) == 0);
      setBit(TIMER0_ICR_R,0);
    }
}