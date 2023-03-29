#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "DIO.h"
#include "bitwise_operation.h"
#include "types.h"
#include "functions.h"

void vApplicationIdleHook(){

	DIO_WritePin(&GPIO_PORTF_DATA_R,3,0);

	DIO_WritePin(&GPIO_PORTF_DATA_R,1,0);
	
	DIO_WritePin(&GPIO_PORTF_DATA_R,2,1);
	
	

}

int main(){
	DIO_init();
	xTaskCreate(&fun1,"fun1",240,NULL,1,NULL);
	xTaskCreate(&fun2,"fun2",240,NULL,2,NULL);
	vTaskStartScheduler();
	
	
return 0;
}