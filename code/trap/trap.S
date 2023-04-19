#初始化 init

.global __save_register
.align 4
#四字节对齐
__save_register:
    #栈是高地址向低地址生长，sp减去一段数为sp占用了一段空间 36个64位寄存器下移36 * (64/8)
    addi sp, sp, -36*8
    #存储x1-x31寄存器的值到栈中
    #x0为zero x2为sp
    sd x1, 1*8(sp)
    sd x3, 3*8(sp)
    sd x4, 4*8(sp)
    sd x5, 5*8(sp)
    sd x6, 6*8(sp)
    sd x7, 7*8(sp)
    sd x8, 8*8(sp)
    sd x9, 9*8(sp)
    sd x10, 10*8(sp)
    sd x11, 11*8(sp)
    sd x12, 12*8(sp)
    sd x13, 13*8(sp)
    sd x14, 14*8(sp)
    sd x15, 15*8(sp)
    sd x16, 16*8(sp)
    sd x17, 17*8(sp)
    sd x18, 18*8(sp)
    sd x19, 19*8(sp)
    sd x20, 20*8(sp)
    sd x21, 21*8(sp)
    sd x22, 22*8(sp)
    sd x23, 23*8(sp)
    sd x24, 24*8(sp)
    sd x25, 25*8(sp)
    sd x26, 26*8(sp)
    sd x27, 27*8(sp)
    sd x28, 28*8(sp)
    sd x29, 29*8(sp)
    sd x30, 30*8(sp)
    sd x31, 31*8(sp)
    #通用寄存器保存完毕
    #读取并保存sstatus sepc stval scause寄存器
    #读取csr寄存器
    csrr s1, sstatus
    cssr s2, sepc
    csrr s3, stval
    cssr s4, scause
    #存储sp csr寄存器
    sd s1 32*8(sp)
    sd s2 33*8(sp)
    sd s3 34*8(sp)
    sd s4 35*8(sp)
    #Q:为啥要把s0再放一次
    sd s0, 2*8(sp)
    mv a0, sp
    #跳转到trap函数 PC+4 放入x1(默认放入x1...?)
    jal x1, trap
.global __restore_register
__restore_register
    ld s1 32*8(sp)
    ld s2 33*8(sp)
    csrw sstatus, s1
    csrw sepc, s2
    ld x1, 1*8(sp)
    ld x3, 3*8(sp)
    ld x4, 4*8(sp)
    ld x5, 5*8(sp)
    ld x6, 6*8(sp)
    ld x7, 7*8(sp)
    ld x8, 8*8(sp)
    ld x9, 9*8(sp)
    ld x10, 10*8(sp)
    ld x11, 11*8(sp)
    ld x12, 12*8(sp)
    ld x13, 13*8(sp)
    ld x14, 14*8(sp)
    ld x15, 15*8(sp)
    ld x16, 16*8(sp)
    ld x17, 17*8(sp)
    ld x18, 18*8(sp)
    ld x19, 19*8(sp)
    ld x20, 20*8(sp)
    ld x21, 21*8(sp)
    ld x22, 22*8(sp)
    ld x23, 23*8(sp)
    ld x24, 24*8(sp)
    ld x25, 25*8(sp)
    ld x26, 26*8(sp)
    ld x27, 27*8(sp)
    ld x28, 28*8(sp)
    ld x29, 29*8(sp)
    ld x30, 30*8(sp)
    ld x31, 31*8(sp)
    ld x2, 2*8(sp)
    sret
    
_interrupt_handler:
    # 中断处理程序
    # 在这里处理中断，然后使用sret指令返回
    sret                      # 使用sret指令返回