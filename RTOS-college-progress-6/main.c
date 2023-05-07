#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "DIO.h"
#include "bitwise_operation.h"
#include "types.h"
#include "functions.h"
#include <queue.h>
#include <semphr.h>
#include <stdio.h>

// Declare the handle to the queue
xQueueHandle xQueue;
xSemaphoreHandle xCountingSemaphore;
int ctr =0;
int arr[20]={0};

void botton1CheckTask(){
while(1){

if(DIO_ReadPin(&GPIO_PORTF_DATA_R,0) == 0){
ctr++;
xQueueSend(xQueue, &ctr, 0);
	
xSemaphoreGive(xCountingSemaphore);
}
}

}
void UartTask(){

int index =-1;
while(1){
	index++;

xSemaphoreTake(xCountingSemaphore,portMAX_DELAY);
xQueueReceive(xQueue,&arr[index] ,portMAX_DELAY);

}

}

int main(){
	xCountingSemaphore = xSemaphoreCreateCounting(20,0);
	DIO_init();
	xQueue = xQueueCreate(5 , sizeof(long));
	xTaskCreate(botton1CheckTask,"botton1CheckTask" , 240 , NULL , 1,NULL);
	xTaskCreate(UartTask,"UartTask" , 240 , NULL , 2,NULL);
	vTaskStartScheduler();
	
return 0;
}