#ifndef __SBI_H__
#define __SBI_H__
#include "main.h"

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
#define SBI_EXT_BASE 0x10         // probing which SBI extensions are available and for querying the version of the SBI.
#define SBI_EXT_TIME 0x54494D45   // timer extension. only has set timer function
#define SBI_EXT_IPI 0x735049      // inter-processor interrupt extension
#define SBI_EXT_RFENCE 0x52464E43 // This extension defines all remote fence related functions.
#define SBI_EXT_HSM 0x48534D      // This extension defines Hart State Management
#define SBI_EXT_SRST 0x53525354   // Thsi extension defines system reset extension
#define SBI_EXT_PMU 0x504D55      // This extension defines performance monitoring unit
#define SBI_EXT_DBCN 0x4442434E   // This extension defines debug console
#define SBI_EXT_SUSP 0x53555350   // This extension defines suspend/resume
#define SBI_EXT_CPPC 0x43505043   // This extension defines core performance policy control
/** legacy extension id */
/** a7 register encodes the SBI legacy extention ID */
#define SBI_EXT_LEGACY_GET_CHAR 0x02 // get char from console
#define SBI_EXT_LEGACY_PUT_CHAR 0x03 // put char to console

/** a6 register encodes the SBI function ID */
/** SBI function IDs for BASE extension */
#define SBI_EXT_BASE_GET_SPEC_VERSION 0x0 // get SBI specification version
#define SBI_EXT_BASE_GET_IMP_ID 0x1       // get SBI implementation ID
#define SBI_EXT_BASE_GET_IMP_VERSION 0x2  // get SBI implementation version
#define SBI_EXT_BASE_PROBE_EXT 0x3        // probe SBI extension
#define SBI_EXT_BASE_GET_MVENDORID 0x4    // get machine vendor id
#define SBI_EXT_BASE_GET_MARCHID 0x5      // get machine architecture id
#define SBI_EXT_BASE_GET_MIMPID 0x6       // get machine implementation id

/** SBI function IDs for TIME extension */
#define SBI_EXT_TIME_SET_TIMER 0x0 // SBI_EXT_RFENCE

/** SBI function IDs for IPI extension*/
#define SBI_EXT_IPI_SEND_IPI 0x0 // send inter-processor interrupt

/** SBI function IDs for RFENCE extension */
#define SBI_EXT_RFENCE_REMOTE_FENCE_I 0x0          // Instructs remote harts to execute FENCE.I instruction.
#define SBI_EXT_RFENCE_REMOTE_SFENCE_VMA 0x1       // Instructs the remote harts to execute one or more SFENCE.VMA instructions, covering the range of virtual addresses between start and size.
#define SBI_EXT_RFENCE_REMOTE_SFENCE_VMA_ASID 0x2  // Instruct the remote harts to execute one or more SFENCE.VMA instructions, covering the range of virtual addresses between start and size. This covers only the given ASID.
#define SBI_EXT_RFENCE_REMOTE_HFENCE_GVMA_VMID 0x3 // Instruct the remote harts to execute one or more HFENCE.GVMA instructions, covering the range of guest physical addresses between start and size only for the given VMID. This function call is only valid for harts implementing hypervisor extension.
#define SBI_EXT_RFENCE_REMOTE_HFENCE_GVMA 0x4      // Instruct the remote harts to execute one or more HFENCE.GVMA instructions, covering the range of guest physical addresses between start and size for all the guests. This function call is only valid for harts implementing hypervisor extension.
#define SBI_EXT_RFENCE_REMOTE_HFENCE_VVMA_ASID 0x5 // Instruct the remote harts to execute one or more HFENCE.VVMA instructions, covering the range of guest virtual addresses between start and size for the given ASID and current VMID (in hgatp CSR) of calling hart. This function call is only valid for harts implementing hypervisor extension.
#define SBI_EXT_RFENCE_REMOTE_HFENCE_VVMA 0x6      // Instruct the remote harts to execute one or more HFENCE.VVMA instructions, covering the range of guest virtual addresses between start and size for current VMID (in hgatp CSR) of calling hart. This function call is only valid for harts implementing hypervisor extension.

/** SBI function IDs for HSM extension */
#define SBI_EXT_HSM_HART_START 0x0
#define SBI_EXT_HSM_HART_STOP 0x1
#define SBI_EXT_HSM_HART_GET_STATUS 0x2
#define SBI_EXT_HSM_HART_SUSPEND 0x3

#define SBI_HSM_STATE_STARTED 0x0         // The hart is physically powered-up and executing normally.
#define SBI_HSM_STATE_STOPPED 0x1         // The hart is not executing in supervisor-mode or any lower privilege mode. It is probably powered-down by the SBI implementation if the underlying platform has a mechanism to physically power-down harts.
#define SBI_HSM_STATE_START_PENDING 0x2   // Some other hart has requested to start (or power-up) the hart from the STOPPED state and the SBI implementation is still working to get the hart in the STARTED state.
#define SBI_HSM_STATE_STOP_PENDING 0x3    // The hart has requested to stop (or power-down) itself from the STARTED state and the SBI implementation is still working to get the hart in the STOPPED state.
#define SBI_HSM_STATE_SUSPENDED 0x4       // This hart is in a platform specific suspend (or low power) state.
#define SBI_HSM_STATE_SUSPEND_PENDING 0x5 // The hart has requested to put itself in a platform specific low power state from the STARTED state and the SBI implementation is still working to get the hart in the platform specific SUSPENDED state.
#define SBI_HSM_STATE_RESUME_PENDING 0x6  // An interrupt or platform specific hardware event has caused the hart to resume normal execution from the SUSPENDED state and the SBI implementation is still working to get the hart in the STARTED state.

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
#define SBI_EXT_SRST_RESET 0x0           // Reset the system
#define SBI_SRST_RESET_TYPE_SHUTDOWN 0x0 // Shutdown the system
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
struct sbiret sbi_get_spec_version();                                                                                         /** get sbi specification version */
struct sbiret sbi_get_impl_id();                                                                                              /** get sbi implementation id */
struct sbiret sbi_get_impl_version();                                                                                         /** get sbi implementation version */
struct sbiret sbi_system_reset(uint32_t reset_type, uint32_t reset_reason);                                                   /** reset system */
struct sbiret sbi_probe_extension(uint64_t extension_id);                                                                     /** probe sbi extenstion */
void sbi_set_timer(uint64_t stime_value);                                                                                     /** set timer */
int sbi_console_getchar(void);                                                                                                /** read a byte from debug console */
void sbi_console_putchar(int ch);                                                                                             /** print character to debug console */
void sbi_remote_fence_i(const unsigned long *hart_mask);                                                                      /** remote fence i */
void sbi_remote_sfence_vma(const unsigned long *hart_mask, unsigned long start, unsigned long size);                          /** remote sfence vma */
void sbi_remote_sfence_vma_asid(const unsigned long *hart_mask, unsigned long start, unsigned long size, unsigned long asid); /** remote sfence vma asid */
// void sbi_clear_ipi
struct sbiret riscv_sbi_ecall(uint64_t sbi_extension_id, uint64_t sbi_function_id, uint64_t arg0, uint64_t arg1, uint64_t arg2);

#endif
 