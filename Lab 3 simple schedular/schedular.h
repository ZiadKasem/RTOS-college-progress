#ifndef SCHEDULAR-H
  #define SCHEDULAR-H
#include "Systic_timer.h" 

void createfun(void (*PtrToFun)(void), int );
void schedular();

#endif