#include "trap.h"
struct trapframe *trap(struct trapframe *tf);
struct trapframe *int_handle(struct trapframe *tf);
struct trapframe *ex_handle(struct trapframe *tf);
/*
从trap.S的__save_register引入到trap,栈的地址作为trapframe地址参数
最后返回栈的地址作为__restore_register的参数恢复寄存器的值
*/
struct trapframe *trap(struct trapframe *tf)
{
    //判定是异常还是中断
    if(tf->cause < 0) return int_handle(tf);
    else return ex_handle(tf);
}
struct trapframe *int_handle(struct trapframe *tf)
{
    //将cause最高位设为0
    int64_t cause = (tf->cause << 1) >> 1;
    switch(cause) 
    {
        case INT_U_SOFT:
        break;
        case INT_S_SOFT:
        break;
        case INT_M_SOFT:
        break;
        case INT_U_TIME:
        break;
        case INT_S_TIME:
        break;
        case INT_M_TIME:
        break;
        case INT_U_EXT:
        break;
        case INT_S_EXT:
        break;
        case INT_M_EXT:
        break;
        default:
        break;
    }
    return tf;
}
struct trapframe *ex_handle(struct trapframe *tf)
{
    //cause > 0
    int64_t cause = tf->cause;
    switch(cause)
    {
        case EX_INSTR_ADD_MIS:
        break;
        case EX_INSTR_ACC_F:
        break;
        case EX_ILL_INSTR:
        break;
        case EX_BREAKPOINT:
        break;
        case EX_LOAD_ADD_MIS:
        break;
        case EX_LOAD_ACC_F:
        break;
        case EX_SA_ADD_MIS:
        break;
        case EX_SA_ACC_F:
        break;
        case EX_U_ECALL:
        break;
        case EX_S_ECALL:
        break;
        case EX_M_ECALL:
        break;
        case EX_INSTR_P_F:
        break;
        case EX_LOAD_P_F:
        break;
        case EX_SA_P_F:
        break;
        default:
        break;
    }
    return tf;
}