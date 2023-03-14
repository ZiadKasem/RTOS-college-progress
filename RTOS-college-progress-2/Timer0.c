#include "Timer0.h"



void TimerInit(){
    //set the clock
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                   SYSCTL_XTAL_16MHZ);
    //
    // The Timer0 peripheral must be enabled for use.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
    //while(!SysCtlPeripheralReady(TIMER0_BASE));
     //
    // Configure Timer0 as a 32-bit periodic timer.
    //
    TimerConfigure(TIMER0_BASE,TIMER_CFG_A_PERIODIC);
    //Set load value to done eac 1 sec
    TimerLoadSet(TIMER0_BASE, TIMER_A, SysCtlClockGet()/2);

}
