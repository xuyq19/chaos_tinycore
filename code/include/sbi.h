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
#define BASE_EXTENSTION 0x10
#define TIMER_EXTENTION 0x54494D45
#define HART_STATE_EXTENTION 0x48534D
#define RESET_EXTENTION 0x53525354

/** sbi implementation id */

/** we love OpenSBI */
#define BERKELY_BOOT_LOADER 0
#define OPENSBI 1
#define XVISOR 2
#define KVM 3
#define RUSTSBI 4
#define DIOSIX 5

/** sbi function code */
/** a6 register encodes the SBI function ID */
uint64_t SBI_SET_TIMER = 0x0;
uint64_t SBI_CONSOLE_PUTCHAR = 0x1;
uint64_t SBI_CONSOLE_GETCHAR = 0x2;
uint64_t SBI_CLEAR_IPI = 0x3;
uint64_t SBI_SEND_IPI = 0x4;
uint64_t SBI_REMOTE_FENCE_I = 0x5;
uint64_t SBI_REMOTE_SFENCE_VMA = 0x6;
uint64_t SBI_REMOTE_SFENCE_VMA_ASID = 0x7;
uint64_t SBI_SHUTDOWN = 0x8;

/** sbi ecall return type */

/**
 * @brief sbi return type
 * @copyright riscv-non-isa
 * @param error error type
 */
struct sbiret
{
    long error;
    long value;
};

struct sbiret sbi_get_spec_version();                 /** get sbi specification version */
struct sbiret sbi_get_impl_id();                      /** get sbi implementation id */
struct sbiret sbi_get_impl_version();                 /** get sbi implementation version */
struct sbiret sbi_probe_extension(long extension_id); /** probe sbi extenstion */
void sbi_set_timer(uint64_t stime_value);             /** set timer */
int sbi_console_getchar(void);                        /** read a byte from debug console */
void sbi_console_putchar(unsigned char ch);           /** print character to debug console */
void sbi_shutdown();                                  /** shutdown */
void print_system_infomation();
uint64_t riscv_sbi_ecall(uint64_t sbi_type, uint64_t arg0, uint64_t arg1, uint64_t arg2);

#endif
