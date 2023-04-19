#include<stdint.h>
#include<stddef.h>
/*
Interrupt & Exception
| Interrupt | Exception Code | Description                      |
| :-------: | :------------: | :------------------------------- |
|     1     |       0        | User software interrupt          |
|     1     |       1        | Supervisor software interrupt    |
|     1     |       2        | Reserved for future standard use |
|     1     |       3        | Machine software interrupt       |
|     1     |       4        | User timer interrupt             |
|     1     |       5        | Supervisor timer interrupt       |
|     1     |       6        | Reserved for future standard use |
|     1     |       7        | Machine timer interrupt          |
|     1     |       8        | User external interrupt          |
|     1     |       9        | Supervisor external interrupt    |
|     1     |       10       | Reserved for future standard use |
|     1     |       11       | Machine external interrupt       |
|     1     |     12–15      | Reserved for future standard use |
|     1     |      ≥16       | Reserved for platform use        |
|     0     |       0        | Instruction address misaligned   |
|     0     |       1        | Instruction access fault         |
|     0     |       2        | Illegal instruction              |
|     0     |       3        | Breakpoint                       |
|     0     |       4        | Load address misaligned          |
|     0     |       5        | Load access fault                |
|     0     |       6        | Store/AMO address misaligned     |
|     0     |       7        | Store/AMO access fault           |
|     0     |       8        | Environment call from U-mode     |
|     0     |       9        | Environment call from S-mode     |
|     0     |       10       | Reserved                         |
|     0     |       11       | Environment call from M-mode     |
|     0     |       12       | Instruction page fault           |
|     0     |       13       | Load page fault                  |
|     0     |       14       | Reserved for future standard use |
|     0     |       15       | Store/AMO page fault             |
|     0     |     16–23      | Reserved for future standard use |
|     0     |     24–31      | Reserved for custom use          |
|     0     |     32–47      | Reserved for future standard use |
|     0     |     48–63      | Reserved for custom use          |
|     0     |      ≥64       | Reserved for future standard use |
*/
//中断部分
#define INT_U_SOFT 0
#define INT_S_SOFT 1

#define INT_M_SOFT 3
#define INT_U_TIME 4
#define INT_S_TIME 5

#define INT_M_TIME 7
#define INT_U_EXT 8
#define INT_S_EXT 9

#define INT_M_EXT 11


//异常部分
#define EX_INSTR_ADD_MIS 0
#define EX_INSTR_ACC_F 1
#define EX_ILL_INSTR 2
#define EX_BREAKPOINT 3
#define EX_LOAD_ADD_MIS 4
#define EX_LOAD_ACC_F 5
#define EX_SA_ADD_MIS 6
#define EX_SA_ACC_F 7
#define EX_U_ECALL 8
#define EX_S_ECALL 9

#define EX_M_ECALL 11
#define EX_INSTR_P_F 12
#define EX_LOAD_P_F 13

#define EX_SA_P_F 15
#define EX_STD 16

#define EX_CUST 24

struct trapframe
{
    //通用寄存器
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
    //CSR寄存器
    uint64_t status; //status
    uint64_t epc; //exception PC 保存异常发生时PC的值
    uint64_t tval; //trap value 保存了陷入的附加信息
    uint64_t cause; //exception cause 指示发生异常的种类
};