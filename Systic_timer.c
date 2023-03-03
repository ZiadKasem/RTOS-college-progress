#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "types.h"
#include "tm4c123gh6pm.h"
#include "driverlib/systick.h"
#include "DIO.h"


/*void SysTick_Init(void){
    SysTickDisable(); 
    NVIC_ST_RELOAD_R = 16000000;   
    NVIC_ST_CTRL_R = 7;      
    SysTickEnable();
   __asm("CPSIE   I");
}*/
void Systick_Init_int()
{ 
  //NVIC_ST_CTRL_R = 0;   
  NVIC_ST_RELOAD_R = 16000000;  
  NVIC_ST_CTRL_R = 7;   
  
  
}