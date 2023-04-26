#include "../include/sbi.h"

void smp_prepare_cpus(unsigned int max_cpus)
{
    int cpuid;
    int ret;
    unsigned current_hartid = sbi_current_hartid();
}