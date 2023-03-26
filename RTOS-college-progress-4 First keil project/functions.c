#include "DIO.h"
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"

void fun1() {
    
      for(;;){
      DIO_WritePin(&GPIO_PORTF_DATA_R,1,!DIO_ReadPin(&GPIO_PORTF_DATA_R,1));
      vTaskDelay(1000/portTICK_PERIOD_MS); // to get ticks 
      
		}
      
    
 }


void fun2() {
    for(;;){
      DIO_WritePin(&GPIO_PORTF_DATA_R,2,!DIO_ReadPin(&GPIO_PORTF_DATA_R,2));
      vTaskDelay(1000/portTICK_PERIOD_MS); // to get ticks 
      
		}

}
void fun3() {
    for(;;){
      DIO_WritePin(&GPIO_PORTF_DATA_R,3,!DIO_ReadPin(&GPIO_PORTF_DATA_R,3));
      vTaskDelay(1000/portTICK_PERIOD_MS); // to get ticks 
      
		}
    
}