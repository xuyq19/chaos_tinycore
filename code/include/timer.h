#ifndef _TIMER_H
#define _TIMER_H

#include "sbi.h"

/* every timebase times, the timer interrupt will be triggered
 * timebase = 1000000 means 1s
 * timebase = 1000 means 1ms
 * timebase = 1 means 1us
 * in qemu, timebase = 100000, the frequency of timer interrupt is 10Hz
 */
static uint64_t timebase = 100000;

extern volatile size_t ticks;

void timer_init();
void timer_next();

#endif
