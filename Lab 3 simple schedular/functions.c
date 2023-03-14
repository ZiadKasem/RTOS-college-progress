#include "Timer0.h"
#include "DIO.h"
//zz
void fun1() {
    
      TimerEnable(TIMER0_BASE,TIMER_A);
      
      DIO_WritePin(&GPIO_PORTF_DATA_R,1,0);
      while((TIMER0_RIS_R & 0x01) == 0);
      setBit(TIMER0_ICR_R,0);
      
      DIO_WritePin(&GPIO_PORTF_DATA_R,1,1);
      while((TIMER0_RIS_R & 0x01) == 0);
      setBit(TIMER0_ICR_R,0);
      
      DIO_WritePin(&GPIO_PORTF_DATA_R,1,0); // close it before we go
 
      
      TimerDisable(TIMER0_BASE,TIMER_A);
    
}


void fun2() {
    
      //TimerEnable(TIMER0_BASE,TIMER_A);
      
      
      
      
      //DIO_WritePin(&GPIO_PORTF_DATA_R,2,0);
      
      //while((TIMER0_RIS_R & 0x01) == 0);
      //setBit(TIMER0_ICR_R,0);
      
      
      DIO_WritePin(&GPIO_PORTF_DATA_R,2,1);
      
      
      //while((TIMER0_RIS_R & 0x01) == 0);
      //setBit(TIMER0_ICR_R,0);
    
}
void fun3() {
    
      //TimerEnable(TIMER0_BASE,TIMER_A);
      
      
      
      
      //DIO_WritePin(&GPIO_PORTF_DATA_R,3,0);
      
      //while((TIMER0_RIS_R & 0x01) == 0);
      //setBit(TIMER0_ICR_R,0);
      
      
      DIO_WritePin(&GPIO_PORTF_DATA_R,3,1);
      
      
      //while((TIMER0_RIS_R & 0x01) == 0);
      //setBit(TIMER0_ICR_R,0);
    
}