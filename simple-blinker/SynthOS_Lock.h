#ifndef SYNTHOS_LOCK_INCLUDED
#define SYNTHOS_LOCK_INCLUDED

#include "SynthOS_Config.h"

// The SynthOS_Config.h file should override these defines. If not, the
// defines given here work for a system with interrupts always disabled.

extern int SynthOS_nullLock();
extern void SynthOS_nullUnlock(int);

#ifndef SynthOS_lock
#define SynthOS_lock SynthOS_nullLock
#endif

#ifndef SynthOS_unlock
#define SynthOS_unlock SynthOS_nullUnlock
#endif

#ifndef SynthOS_enableInterrupts
#define SynthOS_enableInterrupts SynthOS_nullEnableInterrupts
#endif

#endif
