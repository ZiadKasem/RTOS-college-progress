#include <stdint.h>
#include "tm4c123gh6pm.h" 
#include "types.h"
#include "DIO.h"
#include "bitwise_operation.h"
#include "Systic_timer.h"
#include "Timer0.h"
#include "schedular.h"
#include "functions.h"
/*
Timer 1 sec
systic 0.1 sec
problems: entering the same function more than one time in the same ctr value
question do we have to read count flag in systic to clear ?
when i enabled the systic interupt if there is pending interupt, it will be exectuted ones enabled ?
Idea : can i make it wait at the end of schedular.c with the same time of systic so i can be sure that it will file each while itteration ?
*/
int ctr =0;
uint8 volatile systick_elapse = 0;

void SysTick_handler(){
  
  ctr++;
  systick_elapse = 1;

}

int main() {
    DIO_init();
    Systick_Init_int();
    TimerInit();
    createfun(&fun1,5);  //explain
    createfun(&fun2,10);
    createfun(&fun3,20);
    schedular();
    while(1){
    }
    return 0;
}


/*
need to disaple intruppt during scheduling 
need to add timer Done

*/