#ifndef SYNTHOS_TCB_INCLUDED
#define SYNTHOS_TCB_INCLUDED

/*
 * Task control block (TCB), holds scheduling information for each task.
 * Note that this logically "subclasses" SynthOS_List (the first two
 * fields) so that TCBs may be inserted into linked lists.
 */
typedef struct SynthOS_TCB {
  struct SynthOS_TCB *next;               // Next TCB on list.
  struct SynthOS_TCB *previous;           // Previous TCB on list.
  void (*function)(struct SynthOS_TCB *); // Function to call to execute task.
  unsigned char priority;                 // Priority of the task.
  unsigned char period;                   // Periodicity of task (round robin).
  unsigned short nextState;               // Next state for state machine.
} SynthOS_TCB;

extern void SynthOS_tcbInit(SynthOS_TCB *tcb,
			    void (*function)(SynthOS_TCB *), 
			    int priority,
			    int period);


#endif

