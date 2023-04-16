#include "../include/sbi.h"

uint64_t sbi_call(uint64_t sbi_type, uint64_t arg0, uint64_t arg1, uint64_t arg2)
{
    register uint64_t a0 asm("x10") = arg0;
    register uint64_t a1 asm("x11") = arg1;
    register uint64_t a2 asm("x12") = arg2;
    register uint64_t a6 asm("x16") = 0;
    register uint64_t a7 asm("x17") = sbi_type;
    __asm__ __volatile__("ecall \n\t"
                         : /* empty output list */
                         : "r"(a0), "r"(a1), "r"(a2), "r"(a6), "r"(a7)
                         : "memory");
    return a0;
}

void sbi_console_putchar(unsigned char ch)
{
    sbi_call(SBI_CONSOLE_PUTCHAR, ch, 0, 0);
}

