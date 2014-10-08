#include "SynthOS_TCB.h"

void SynthOS_tcbInit(SynthOS_TCB *tcb, void (*function)(SynthOS_TCB *), 
		     int priority, int period) {
  tcb->function = function;
  tcb->priority = priority;
  tcb->period = period;
  tcb->nextState = 0;
  tcb->next = tcb;
  tcb->previous = tcb;
}

