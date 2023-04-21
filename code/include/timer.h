#ifndef _TIMER_H
#define _TIMER_H

#include "sbi.h"

extern volatile size_t ticks;

void timer_init();
void timer_next();

#endif
