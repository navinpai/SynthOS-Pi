
#include "SynthOS_Config.h"

#include "SynthOS_Kernel.h"

#include "SynthOS_globals.h"

#line 5 "blinker01.c"
extern void PUT32 ( unsigned int , unsigned int ) ; 

#line 6 "blinker01.c"
extern unsigned int GET32 ( unsigned int ) ; 

#line 7 "blinker01.c"
extern void dummy ( unsigned int ) ; 

#line 14 "blinker01.c"
void notmain ( struct SynthOS_TCB * SynthOS_tcb) 
{ 
    static unsigned int ra ; 
#line 15 "blinker01.c"
    switch ( SynthOS_tcb -> nextState ) { case 0 : goto SynthOS_label_0 ; } 
#line 18 "blinker01.c"
    SynthOS_label_0 : { } ra = GET32 ( 0x20200004 ) ; 
    ra &= ~ ( 7 << 18 ) ; 
    ra |= 1 << 18 ; 
    PUT32 ( 0x20200004 , ra ) ; 
#line 23 "blinker01.c"
    while ( 1 ) 
    { 
        PUT32 ( 0x2020001C , 1 << 16 ) ; 
        for ( ra = 0 ; ra < 0x100000 ; ra ++ ) dummy ( ra ) ; 
        PUT32 ( 0x20200028 , 1 << 16 ) ; 
        for ( ra = 0 ; ra < 0x100000 ; ra ++ ) dummy ( ra ) ; 
    } 
#line 23 "blinker01.c"
    { SynthOS_tcb -> nextState = 0 ; SynthOS_scheduleTask ( SynthOS_tcb ) ; return ; } 
#line 31 "blinker01.c"
} 
