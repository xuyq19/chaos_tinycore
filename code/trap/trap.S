#初始化 init
.global _start

_start:
    # 设置mtvec寄存器
    la t0, _interrupt_handler # 将中断处理程序的入口地址加载到t0寄存器
    csrw mtvec, t0            # 将t0寄存器的值写入mtvec寄存器

    # 开启中断使能
    csrr t0, mstatus          # 将mstatus寄存器的值读入t0寄存器
    li t1, 0x8                # 将0x8写入t1寄存器，即将MIE位置为1
    or t0, t0, t1             # 将t0寄存器和t1寄存器的值进行或运算，将MIE位置为1
    csrw mstatus, t0          # 将t0寄存器的值写入mstatus寄存器

    # 触发中断
    ebreak                    # 触发ebreak指令，即触发中断

_interrupt_handler:
    # 中断处理程序
    # 在这里处理中断，然后使用sret指令返回
    sret                      # 使用sret指令返回