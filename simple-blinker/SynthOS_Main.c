/*
 *Automatically generated by SynthOS
 */
#include "SynthOS_globals.h"
extern void SynthOS_init();
extern void notmain(struct SynthOS_TCB *);

int main() {
    SynthOS_init();
    // Create LOOP tasks and CALL tasks.
    SynthOS_createLoopTask(&SynthOS_tcb_notmain, &notmain, 0, 1);
    // Call INIT tasks.
    // Start the application.
    SynthOS_schedule();
    return 0;
}
