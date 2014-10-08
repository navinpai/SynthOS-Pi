#ifndef SYNTHOS_SCHEDULER_INCLUDED
#define SYNTHOS_SCHEDULER_INCLUDED

#include "SynthOS_TCB.h"

/*
 * This variable is initialized to 0 by the scheduler when it begins
 * execution. The scheduler checks this flag every time it schedules
 * a task--if it's ever non-zero, the scheduler returns to main(), which
 * will then return to whatever code called main(). This provides
 * a simple "exception" mechanism for the user. If something disastrous
 * happens, a user task can clean things up (whatever the hardware requires)
 * and then abort execution simply by setting this flag to 1.
 */
extern volatile char SynthOS_abort;

extern void SynthOS_initScheduler();
extern void SynthOS_createLoopTask(SynthOS_TCB *tcb, void (*function)(), 
				   int priority, int period);
extern void SynthOS_createCallTask(SynthOS_TCB *tcb, void (*function)(), 
				   int priority, int period);
extern void SynthOS_scheduleTask(SynthOS_TCB *tcb);
extern void SynthOS_schedule();

#endif
