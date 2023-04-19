struct trapframe
{
    //这里列出所有可能会用到的CSR寄存器
    //如果最后发现没有用到（trap帧可能不需要保存）可以删掉
    uint64_t tvec; //trap vector 保存发生异常时处理器需要跳转到的地址 需要我来设置还是默认有一个地址...? 
    uint64_t epc; //exception PC 保存异常发生时PC的值 need
    uint64_t cause; //exception cause 指示发生异常的种类 need
    uint64_t tval; //trap value 保存了陷入的附加信息 need
    uint64_t scratch; //scratch need
    uint64_t status; //ststus need
    uint64_t ie; //interrupt enable 指示可处理和被忽略的中断 不需要？
    uint64_t ip; //interrupt pending 列出目前正准备处理的中断 不需要？
    //以下是通用寄存器
    uint64_t zero; //x0
    uint64_t ra; //x1
    uint64_t sp; //x2
    uint64_t gp; //x3
    uint64_t tp; //x4
    uint64_t t0; //x5
    uint64_t t1; //x6
    uint64_t t2; //x7
    uint64_t s0; //x8
    uint64_t s1; //x9
    uint64_t a0; //x10
    uint64_t a1; //x11
    uint64_t a2; //x12
    uint64_t a3; //x13
    uint64_t a4; //x14
    uint64_t a5; //x15
    uint64_t a6; //x16
    uint64_t a7; //x17
    uint64_t s2; //x18
    uint64_t s3; //x19
    uint64_t s4; //x20
    uint64_t s5; //x21
    uint64_t s6; //x22
    uint64_t s7; //x23
    uint64_t s8; //x24
    uint64_t s9; //x25
    uint64_t s10; //x26
    uint64_t s11; //x27
    uint64_t t3; //x28
    uint64_t t4; //x29
    uint64_t t5; //x30
    uint64_t t6; //x31
}