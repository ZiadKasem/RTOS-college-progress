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





int main(){
	DIO_init();
	DIO_WritePin(&GPIO_PORTB_DATA_R,4,1);
	
return 0;
}