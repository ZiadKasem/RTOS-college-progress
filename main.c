#include <stdint.h>
#include "tm4c123gh6pm.h" 
#include "types.h"
#include "DIO.h"
#include "bitwise_operation.h"
#include "Systic_timer.h"
#include "Timer0.h"
#include "schedular.h"
#include "functions.h"

int ctr =0;

void SysTick_handler(){
  
  ctr++;
  
}

int main() {
    DIO_init();
    Systick_Init_int();
    createfun(&fun1,5);  //explain
    createfun(&fun2,10);
    createfun(&fun3,20);
    schedular();
    while(1){
    }
    return 0;
}