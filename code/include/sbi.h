#ifndef __SBI_H__
#define __SBI_H__
#include "main.h"

/*
 * Copyright (C) 2023 by LZU_OSLAB
 *
 *   This program is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU General Public License
 *   as published by the Free Software Foundation, version 3.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 */

/** error type */
#define SBI_SUCCESS 0
#define SBI_ERR_FAILED -1
#define SBI_ERR_NOT_SUPPORTED -2
#define SBI_ERR_INVALID_PARAM -3
#define SBI_ERR_DENIED -4
#define SBI_ERR_INVALID_ADDRESS -5
#define SBI_ERR_ALERADY_AVAILABLE -6
#define SBI_ERR_ALREADY_STARTED -7
#define SBI_ERR_ALREADY_STOPPED -8

/** extenstion id */
/** a7 register encodes the SBI extention ID */
#define SBI_EXT_BASE 0x10
#define SBI_EXT_TIME 0x54494D45
#define SBI_EXT_IPI 0x735049
#define SBI_EXT_RFENCE 0x52464E43
#define SBI_EXT_HSM 0x48534D
#define SBI_EXT_SRST 0x53525354
#define SBI_EXT_PMU 0x504D55
#define SBI_EXT_DBCN 0x4442434E
#define SBI_EXT_SUSP 0x53555350
#define SBI_EXT_CPPC 0x43505043
/** legacy extension id */
/** a7 register encodes the SBI legacy extention ID */
#define SBI_EXT_LEGACY_GET_CHAR 0x02
#define SBI_EXT_LEGACY_PUT_CHAR 0x03

/** a6 register encodes the SBI function ID */
/** SBI function IDs for BASE extension */
#define SBI_EXT_BASE_GET_SPEC_VERSION 0x0
#define SBI_EXT_BASE_GET_IMP_ID 0x1
#define SBI_EXT_BASE_GET_IMP_VERSION 0x2
#define SBI_EXT_BASE_PROBE_EXT 0x3
#define SBI_EXT_BASE_GET_MVENDORID 0x4
#define SBI_EXT_BASE_GET_MARCHID 0x5
#define SBI_EXT_BASE_GET_MIMPID 0x6

/** SBI function IDs for TIME extension */
#define SBI_EXT_TIME_SET_TIMER 0x0

/** SBI function IDs for IPI extension*/
#define SBI_EXT_IPI_SEND_IPI 0x0

/** SBI function IDs for RFENCE extension */
#define SBI_EXT_RFENCE_REMOTE_FENCE_I 0x0
#define SBI_EXT_RFENCE_REMOTE_SFENCE_VMA 0x1
#define SBI_EXT_RFENCE_REMOTE_SFENCE_VMA_ASID 0x2
#define SBI_EXT_RFENCE_REMOTE_HFENCE_GVMA_VMID 0x3
#define SBI_EXT_RFENCE_REMOTE_HFENCE_GVMA 0x4
#define SBI_EXT_RFENCE_REMOTE_HFENCE_VVMA_ASID 0x5
#define SBI_EXT_RFENCE_REMOTE_HFENCE_VVMA 0x6

/** SBI function IDs for HSM extension */
#define SBI_EXT_HSM_HART_START 0x0
#define SBI_EXT_HSM_HART_STOP 0x1
#define SBI_EXT_HSM_HART_GET_STATUS 0x2
#define SBI_EXT_HSM_HART_SUSPEND 0x3

#define SBI_HSM_STATE_STARTED 0x0
#define SBI_HSM_STATE_STOPPED 0x1
#define SBI_HSM_STATE_START_PENDING 0x2
#define SBI_HSM_STATE_STOP_PENDING 0x3
#define SBI_HSM_STATE_SUSPENDED 0x4
#define SBI_HSM_STATE_SUSPEND_PENDING 0x5
#define SBI_HSM_STATE_RESUME_PENDING 0x6

#define SBI_HSM_SUSP_BASE_MASK 0x7fffffff
#define SBI_HSM_SUSP_NON_RET_BIT 0x80000000
#define SBI_HSM_SUSP_PLAT_BASE 0x10000000

#define SBI_HSM_SUSPEND_RET_DEFAULT 0x00000000
#define SBI_HSM_SUSPEND_RET_PLATFORM SBI_HSM_SUSP_PLAT_BASE
#define SBI_HSM_SUSPEND_RET_LAST SBI_HSM_SUSP_BASE_MASK
#define SBI_HSM_SUSPEND_NON_RET_DEFAULT SBI_HSM_SUSP_NON_RET_BIT
#define SBI_HSM_SUSPEND_NON_RET_PLATFORM (SBI_HSM_SUSP_NON_RET_BIT | \
                                          SBI_HSM_SUSP_PLAT_BASE)
#define SBI_HSM_SUSPEND_NON_RET_LAST (SBI_HSM_SUSP_NON_RET_BIT | \
                                      SBI_HSM_SUSP_BASE_MASK)

/** SBI function IDs for SRST extension */
#define SBI_EXT_SRST_RESET 0x0

#define SBI_SRST_RESET_TYPE_SHUTDOWN 0x0
#define SBI_SRST_RESET_TYPE_COLD_REBOOT 0x1
#define SBI_SRST_RESET_TYPE_WARM_REBOOT 0x2
#define SBI_SRST_RESET_TYPE_LAST SBI_SRST_RESET_TYPE_WARM_REBOOT

#define SBI_SRST_RESET_REASON_NONE 0x0
#define SBI_SRST_RESET_REASON_SYSFAIL 0x1

/** sbi implementation id */
#define BERKELY_BOOT_LOADER 0
#define OPENSBI 1
#define XVISOR 2
#define KVM 3
#define RUSTSBI 4
#define DIOSIX 5

/** sbi ecall return type */

/**
 * @brief sbi return type
 * @copyright riscv-non-isa
 */
struct sbiret
{
    long error;
    long value;
};

struct sbiret riscv_sbi_ecall(uint64_t sbi_extension_id, uint64_t sbi_function_id, uint64_t arg0, uint64_t arg1, uint64_t arg2);
struct sbiret sbi_get_spec_version();                                       /** get sbi specification version */
struct sbiret sbi_get_impl_id();                                            /** get sbi implementation id */
struct sbiret sbi_get_impl_version();                                       /** get sbi implementation version */
struct sbiret sbi_system_reset(uint32_t reset_type, uint32_t reset_reason); /** reset system */
struct sbiret sbi_probe_extension(uint64_t extension_id);                   /** probe sbi extenstion */
void sbi_set_timer(uint64_t stime_value);                                   /** set timer */
int sbi_console_getchar(void);                                              /** read a byte from debug console */
void sbi_console_putchar(int ch);                                           /** print character to debug console */

void print_system_infomation();
struct sbiret riscv_sbi_ecall(uint64_t sbi_extension_id, uint64_t sbi_function_id, uint64_t arg0, uint64_t arg1, uint64_t arg2);

#endif
