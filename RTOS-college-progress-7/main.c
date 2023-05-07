#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "DIO.h"
#include <stdint.h>
#include "FreeRTOSConfig.h"
#include "types.h"

#define mainSW_INTURRUPT_ID ((IRQn_Type)0)
#define mainSW_INTURRUPT_PortF ((IRQn_Type)30)

xSemaphoreHandle xCountingSemaphore;
QueueHandle_t uCountingQueue;
uint8_t arr[20]={};
int index = 0;
xSemaphoreHandle xMutex;



void PortF_Init(void) {
    SYSCTL_RCGCGPIO_R |= 0x20; // Enable clock for PortF
    GPIO_PORTF_DIR_R |= 0x02; // Set PF1 as output (red LED)
	  GPIO_PORTF_DEN_R |= 0x02; // Enable digital function for PF1
    GPIO_PORTF_PUR_R |= 0x10; // Enable pull-up for PF4 (SW1)
}



static void vTask1(void *pvParameters){
	xSemaphoreTake( xMutex, portMAX_DELAY );
	{
		for(int i = 0 ; i <10; i++){
			xQueueSendToBack(uCountingQueue,&i +1, 0);
		}
	}
	xSemaphoreGive( xMutex );
	//vTaskDelay( 500 / portTICK_RATE_MS);

}

void vTask2(){
	xSemaphoreTake( xCountingSemaphore, 0 );
	xSemaphoreTake( xCountingSemaphore, portMAX_DELAY );
	xSemaphoreTake( xMutex, portMAX_DELAY );
	{
		for(int i = 0 ; i <10; i++){
			xQueueSendToBack(uCountingQueue,&i +10 , 0);
		}
	}
	xSemaphoreGive( xMutex );
}

void GPIOF_Handler(){
	portBASE_TYPE xHigherPriorityTaskWoken = pdFALSE;
	// Clear the interrupt flag for the pin
    GPIO_PORTF_ICR_R |= (1 << 4);
	 xSemaphoreGiveFromISR( xCountingSemaphore,&xHigherPriorityTaskWoken );
    portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );

}

void ButtonInit(void)
{
    SYSCTL->RCGCGPIO |= (1<<5);   /* Set bit5 of RCGCGPIO to enable clock to PORTF*/
    
	 /* PORTF0 has special function, need to unlock to modify */
    GPIOF->LOCK = 0x4C4F434B;   /* unlock commit register */
    GPIOF->CR = 0x01;           /* make PORTF0 configurable */
    GPIOF->LOCK = 0;            /* lock commit register */


    /*Initialize PF3 as a digital output, PF0 and PF4 as digital input pins */
	
    GPIOF->DIR &= ~(1<<4)|~(1<<0);  /* Set PF4 and PF0 as a digital input pins */
    GPIOF->DEN |= (1<<4)|(1<<3)|(1<<0);             /* make PORTF4-0 digital pins */
    GPIOF->PUR |= (1<<4)|(1<<0);             /* enable pull up for PORTF4, 0 */
    
    /* configure PORTF4, 0 for falling edge trigger interrupt */
    GPIOF->IS  &= ~(1<<4)|~(1<<0);        /* make bit 4, 0 edge sensitive */
    GPIOF->IBE &=~(1<<4)|~(1<<0);         /* trigger is controlled by IEV */
    GPIOF->IEV &= ~(1<<4)|~(1<<0);        /* falling edge trigger */
    GPIOF->ICR |= (1<<4)|(1<<0);          /* clear any prior interrupt */
    GPIOF->IM  |= (1<<4)|(1<<0);          /* unmask interrupt */
    
    /* enable interrupt in NVIC and set priority to 3 */
    NVIC->IP[30] = 3 << 5;     /* set interrupt priority to 3 */
    NVIC->ISER[0] |= (1<<30);  /* enable IRQ30 (D30 of ISER[0]) */

    // Enable interrupts globally
    __asm("cpsie i");

}




int main( void )
{
	ButtonInit();
	NVIC_SetPriority(mainSW_INTURRUPT_PortF,5);
	uCountingQueue = xQueueCreate(10, sizeof(uint8_t));    
	vSemaphoreCreateBinary( xCountingSemaphore );
	xMutex = xSemaphoreCreateMutex();
	
	PortF_Init();

	/* Check the semaphore was created successfully. */
	if( xMutex != NULL )
	{

        xTaskCreate( vTask1, "Task1", 240, NULL, 1, NULL );

        xTaskCreate( vTask2, "Task2", 240, NULL, 3, NULL );

        /* Start the scheduler so the created tasks start executing. */
        vTaskStartScheduler();
	for( ;; );
	}
}
void vApplicationIdleHook(void)
{
}