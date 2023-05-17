#ifndef INCLUDE_MM_MEMORY_LAYOUT_H_
#define INCLUDE_MM_MEMORY_LAYOUT_H_
#include <riscv.h>

#define KERNEL_START 0x80200000L                             // sbi defines
#define PHYSICAL_MEMORY_END (0x80000000 + 128 * 1024 * 1024) // 128MB

#define MAXVA (1L << (9 + 9 + 9 + 12 - 1)) // 256 GB, as SV39 defines
#define USER_TOP MAXVA                     // virtual address of user space top

#define TRAMPOLINE (USER_TOP - PAGE_SIZE)  /**跳板页面的虚拟地址，它是用于在用户空间和内核空间之间进行转换的一个小内存区域。*/
#define TRAPFRAME (TRAMPOLINE - PAGE_SIZE) /**trapframe的虚拟地址，它是用于保存中断帧的一个小内存区域。*/

/**define UART registers as QEMU defines*/
#define UART0 0x10000000L /**256MB*/
#define UART0_IRQ 10      /**与UART设备相关联的中断号*/

/**define virt IO*/
#define VIRTIO0 0x10001000L /**256MB + 4KB*/
#define VIRTIO0_IRQ 1       /**与virtio设备相关联的中断号*/

/**define PLIC*/
/** Platform level interrupt controller*/
#define PLIC 0x0c000000L // 192 MB
#define PLIC_PRIORITY (PLIC + 0x0)
#define PLIC_PENDING (PLIC + 0x1000)
#define PLIC_MENABLE(hart) (PLIC + 0x2000 + (hart)*0x100)
#define PLIC_SENABLE(hart) (PLIC + 0x2080 + (hart)*0x100)
#define PLIC_MPRIORITY(hart) (PLIC + 0x200000 + (hart)*0x2000)
#define PLIC_SPRIORITY(hart) (PLIC + 0x201000 + (hart)*0x2000)
#define PLIC_MCLAIM(hart) (PLIC + 0x200004 + (hart)*0x2000)
#define PLIC_SCLAIM(hart) (PLIC + 0x201004 + (hart)*0x2000)

#define USER_STACK_BOTTOM 0xC0000000 // 3GB, user stack lower address
#define USER_TEXT_START 0x1000

#endif