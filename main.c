#include <stdint.h>
#include "tm4c123gh6pm.h" 
#include "types.h"
#include "DIO.h"
#include "bitwise_operation.h"
#include "Systic_timer.h"

void fun1() {
    while (1) {
      DIO_WritePin(&GPIO_PORTF_DATA_R,1,0);
      
      DIO_WritePin(&GPIO_PORTF_DATA_R,1,1);
      
    }
}

uint32_t stack_BlueBlinky[40];
uint32_t *sp_BlueBlinky = &stack_BlueBlinky[40];

void fun2() {
    while (1) {
      DIO_WritePin(&GPIO_PORTF_DATA_R,2,0);
      
      DIO_WritePin(&GPIO_PORTF_DATA_R,2,1);
      
    }
}

void SysTick_handler(){
  
  int z = 1;
  
}

int main() {
 
  Systick_Init_int();
  DIO_init();
  fun1();
  fun2();
    return 0;
}