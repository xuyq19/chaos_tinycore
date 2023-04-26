#ifndef __CPUMASK_H__
#define __CPUMASK_H__

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define BITS_PER_LONG 64

typedef struct cpumask {
  uint64_t bits[BITS_PER_LONG / 64];
} cpumask_t;
