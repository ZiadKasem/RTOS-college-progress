#include "tm4c123gh6pm.h"

void TimerInit(){
	
	  SYSCTL_RCGCTIMER_R |= SYSCTL_RCGCTIMER_R0; // Enable Timer 0 clock
		TIMER0_CTL_R &= !TIMER_CTL_TAEN; // Disable Timer 0
		TIMER0_CFG_R = TIMER_CFG_32_BIT_TIMER; // Set Timer 0 as a 32-bit timer
		TIMER0_TAMR_R = TIMER_TAMR_TAMR_PERIOD; // Set Timer 0 in periodic mode
		TIMER0_TAILR_R = 7999; // Set the desired period value
		TIMER0_IMR_R |= TIMER_IMR_TATOIM; // Enable Timer 0 timeout interrupt
		NVIC_EN0_R |= 1 << (INT_TIMER0A - 16); // Enable Timer 0 interrupt in the NVIC
		TIMER0_CTL_R |= TIMER_CTL_TAEN; // Enable Timer 0
}
// 5.2.5.2 clock config
