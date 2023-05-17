#include "../include/sbi.h"

/**
 * @brief sbi return type
 *
 * @param sbi_extension_id a7
 * @param sbi_function_id a6
 * @param arg0 a0
 * @param arg1 a1
 * @param arg2 a2
 * @return struct sbiret
 */
struct sbiret riscv_sbi_ecall(uint64_t sbi_extension_id, uint64_t sbi_function_id, uint64_t arg0, uint64_t arg1, uint64_t arg2)
{
    register uint64_t a0 asm("x10") = arg0;
    register uint64_t a1 asm("x11") = arg1;
    register uint64_t a2 asm("x12") = arg2;
    register uint64_t a7 asm("x17") = sbi_extension_id;
    register uint64_t a6 asm("x16") = sbi_function_id;
    __asm__ __volatile__("ecall \n\t"
                         : /* empty output list */
                         : "+r"(a0), "+r"(a1), "r"(a2), "r"(a7), "r"(a6)
                         : "memory");
    return (struct sbiret){a0, a1};
}

/**
 * @brief sbi console putchar
 *
 *
 * @param ch
 */
void sbi_console_putchar(int ch)
{
    riscv_sbi_ecall(SBI_EXT_LEGACY_PUT_CHAR, 0, ch, 0, 0);
}

/**
 * @brief sbi console getchar
 *
 * @return int
 */
int sbi_console_getchar()
{
    riscv_sbi_ecall(SBI_EXT_LEGACY_GET_CHAR, 0, 0, 0, 0);
}

/**
 * @brief sbi get spec version
 *
 * @return struct sbiret
 */
struct sbiret sbi_get_spec_version()
{
    // return (struct sbiret){ error, value };
    return riscv_sbi_ecall(SBI_EXT_BASE, 0, 0, 0, 0);
}

/**
 * @brief sbi get impl id
 *
 * @return struct sbiret
 */
struct sbiret sbi_get_impl_id()
{
    return riscv_sbi_ecall(SBI_EXT_BASE, 1, 0, 0, 0);
}

/**
 * @brief sbi get impl version
 *
 * @return struct sbiret
 */
struct sbiret sbi_get_impl_version()
{
    return riscv_sbi_ecall(SBI_EXT_BASE, 2, 0, 0, 0);
}

/**
 * @brief sbi probe extension
 *
 * @param extension_id
 * @return struct sbiret
 */
struct sbiret sbi_probe_extension(uint64_t extension_id)
{
    return riscv_sbi_ecall(SBI_EXT_BASE, 3, extension_id, 0, 0);
}

struct sbiret sbi_system_reset(uint32_t reset_type, uint32_t reset_reason)
{
    return riscv_sbi_ecall(SBI_EXT_SRST, reset_type, 0, 0, 0);
}

/**
 * @brief sbi set timer
 *
 * @param stime_value
 */
void sbi_set_timer(uint64_t stime_value)
{
    riscv_sbi_ecall(SBI_EXT_TIME, SBI_EXT_TIME_SET_TIMER, stime_value, 0, 0);
}

/**
 * @brief Instructs remote harts to execute FENCE.I instruction. The hart_mask is same as described in sbi_send_ipi().
 *
 * @param *hart_mask
 */
void sbi_remote_fence_i(const unsigned long *hart_mask)
{
    riscv_sbi_ecall(SBI_EXT_RFENCE, SBI_EXT_RFENCE_REMOTE_FENCE_I, hart_mask, 0, 0);
}

/**
 * @brief Instructs remote harts to execute SFENCE.VMA instruction. The hart_mask is same as described in sbi_send_ipi().
 *
 * @param hart_mask
 * @param start
 * @param size
 */
void sbi_remote_sfence_vma(const unsigned long *hart_mask, unsigned long start, unsigned long size)
{
    riscv_sbi_ecall(SBI_EXT_RFENCE, SBI_EXT_RFENCE_REMOTE_SFENCE_VMA, hart_mask, 0, 0);
}

/**
 * @brief Instructs remote harts to execute SFENCE.VMA instruction with ASID. The hart_mask is same as described in sbi_send_ipi().
 *
 * @param hart_mask
 * @param start
 * @param size
 * @param asid
 */
void sbi_remote_sfence_vma_asid(const unsigned long *hart_mask, unsigned long start, unsigned long size, unsigned long asid)
{
    riscv_sbi_ecall(SBI_EXT_RFENCE, SBI_EXT_RFENCE_REMOTE_SFENCE_VMA_ASID, hart_mask, 0, 0);
}

void sbi_hart_start(uint64_t hart_id, uint64_t start_addr, uint64_t a1)
{
    riscv_sbi_ecall(0x48534D, 0, hart_id, start_addr, a1);
}