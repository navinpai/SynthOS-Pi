#include "SynthOS_Scheduler.h"

/*
 * Create a LOOP task.
 */
void SynthOS_createLoopTask(SynthOS_TCB *tcb, void (*function)(), int priority,
			    int period) {
  SynthOS_tcbInit(tcb, function, priority, period);
  SynthOS_scheduleTask(tcb);
}

/*
 * Create a CALL task.
 */
void SynthOS_createCallTask(SynthOS_TCB *tcb, void (*function)(), int priority,
			    int period) {
  // CALL tasks are not runnable until "called" so they don't
  // get scheduled at creation time.
  SynthOS_tcbInit(tcb, function, priority, period);
}
