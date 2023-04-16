    .global boot_mem_stack, boot_mem_stack_top, _start
    .section .text.entry

_start:
    /* 关闭所有中断 */
    csrw CSR_IE, zero
    csrw CSR_IP, zero
    la sp, boot_mem_stack_top
    call main
    .section.bss
boot_mem_stack:
    .space 0x10000
boot_mem_stack_top:

