#include"../include/sbi.h"
#include"../include/timer.h"
#include"../include/riscv.h"
#include <stdint.h>

/** clock interrupt times */
volatile uint64_t ticks;

/** every timebase times, clock interrupt will be triggered */


/**
 * @brief Get the cycles object
 * 
 * @return uint64_t 
 */
static inline uint64_t get_cycles(){
    uint64_t cycles;
    asm volatile("rdtime %0" : "=r"(cycles));
    return cycles; 
}

/**
 * @brief init clock
 * 
 */
void clock_init(){
    ticks=0;
    // enable clock interrupt(set CSR_MIE)
    set_csr(sie, 1 << IRQ_S_TIMER);

}

/**
 * @brief next clock interrupt time
 * 
 */
void clock_next_event(){
    // set next clock interrupt time
    uint64_t next_event = get_cycles() + timebase;
    sbi_set_timer(next_event);
}