/*
 * Round robin scheduler.
 *
 * copyright 2004, Zeidman Technologies
 */

#include "SynthOS_Scheduler.h"
#include "SynthOS_List.h"
#include "SynthOS_Lock.h"

/*
 * Scheduler initializes this to 0. The scheduler will return if this is
 * ever non-zero.
 */
volatile char SynthOS_abort;

/*
 * The currently executing task.
 */
static SynthOS_TCB *currentTask;  

/*
 * The run queue.
 */
static SynthOS_List runnableTasks;

/**
 * Initialize the scheduler.
 */
void SynthOS_initScheduler() {
  SynthOS_listInit(&runnableTasks);
  currentTask = 0;
  SynthOS_abort = 0;
}

/*
 * Schedule the CPU.
 */
void SynthOS_schedule() {
  while (SynthOS_abort == 0) {
    int old = SynthOS_lock();
    currentTask = (SynthOS_TCB *) SynthOS_listRemoveFirst(&runnableTasks);
    SynthOS_unlock(old);
    if (currentTask != 0) {
      // We have a runnable task. But we must check if its period
      // counter has advanced to where it's truly runnable. Note that
      // we use the priority field to count the period ticks. See
      // SynthOS_scheduleTask() for more details.
      currentTask->priority--;
      if (currentTask->priority == 0) {
	// Run the task. The period counter (priority field) will be
	// reset when the task is rescheduled.
	(currentTask->function)(currentTask);
      } else {
	// Even though runnable, we must skip over it because of its period.
	int old = SynthOS_lock();
	SynthOS_listAppend(&runnableTasks, (SynthOS_List *) currentTask);
	SynthOS_unlock(old);
      }
    }
  }
}

/*
 * Schedule a task for execution.
 */
void SynthOS_scheduleTask(SynthOS_TCB *tcb) {
  int old = SynthOS_lock();
  // We use the priority field of the tcb as a "period counter" since it's
  // not otherwise used by the round robin scheduler. Here we immediately
  // set the period counter equal to the period so it can begin the
  // countdown. The scheduler does the counting down of the period counter,
  // and we do the setting here.
  tcb->priority = tcb->period;
  SynthOS_listAppend(&runnableTasks, (SynthOS_List *) tcb);
  SynthOS_unlock(old);
}




