#include "SynthOS_Lock.h"

/*
 * Disable interrupts an return the previous state of the interrupt system.
 * This version is used for systems without interrupts.
 */
int SynthOS_nullLock() {
  return 0;
}

/*
 * Restore interrupts to a previously recorded state.
 * This version is used for systems without interrupts.
 */
void SynthOS_nullUnlock(int oldState) {
}

/*
 * Enable all interrupts.
 * This version is used for systems without interrupts.
 */
void SynthOS_nullEnableInterrupts() {
}

