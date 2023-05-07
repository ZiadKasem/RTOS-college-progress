#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "DIO.h"
#include "bitwise_operation.h"
#include "types.h"
#include "functions.h"




int main(){
	DIO_init();
//	xTaskCreate(&fun1,"fun1",240,NULL,1,NULL);
//	xTaskCreate(&fun2,"fun2",240,NULL,2,NULL);
//	xTaskCreate(&fun3,"fun3",240,NULL,3,NULL);
//	vTaskStartScheduler();
//	for(;;);
	
	DIO_WritePin(&GPIO_PORTB_DATA_R,4,1);
	
return 0;
}