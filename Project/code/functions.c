#include "DIO.h"
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"

void fun1() {
    DIO_WritePin(&GPIO_PORTF_DATA_R,2,0);
		DIO_WritePin(&GPIO_PORTF_DATA_R,3,0);
      for(;;){
      DIO_WritePin(&GPIO_PORTF_DATA_R,1,1);
				for(int j =0; j<1000000;j++);
      vTaskDelay(1000/portTICK_PERIOD_MS); // to get ticks 
      
		}
      
    
 }


void fun2() {
	DIO_WritePin(&GPIO_PORTF_DATA_R,2,0);
	DIO_WritePin(&GPIO_PORTF_DATA_R,1,0);
    for(;;){
      DIO_WritePin(&GPIO_PORTF_DATA_R,3,1);
      vTaskDelay(1000/portTICK_PERIOD_MS); // to get ticks 
      
		}

}
