#ifndef INCLUDE_MM_MEMORY_LAYOUT_H_
#define INCLUDE_MM_MEMORY_LAYOUT_H_

/**
 * @file memory_layout.h
 * @brief 声明内存管理模块的宏、函数、全局变量
 *
 * 在阅读代码时要分清物理地址和虚拟地址，否则会导致混乱。
 * 本模块注释中专门写了函数参数是物理地址还是虚拟地址，如果没有写，默认是虚拟地址。
 *
 * 进程地址空间：
 *     0xFFFFFFFF----->+--------------+-----------------+
 *                     |              |
 *                     |              |
 *                     |    Kernel    |
 *                     |              |
 *                     |              |
 *     0xC0000000----->---------------+
 *                     |    Hole      |
 *     0xBFFFFFF0----->---------------+
 *                     |    Stack     |
 *                     |      +       |
 *                     |      |       |
 *                     |      v       |
 *                     |              |
 *                     |              |
 *                     |      ^       |
 *                     |      |       |
 *                     |      +       |
 *                     | Dynamic data |
 *            brk----->+--------------+
 *                     |              |
 *                     | Static data  |
 *                     |              |
 *                     +--------------+
 *                     |              |
 *                     |     Text     |
 *                     |              |
 *     0x00010000----->---------------+
 *                     |   Reserved   |
 *     0x00000000----->+--------------+
 */

#define SBI_BASE 0x80000000
#define SBI_TOP 0x80200000
#define MEM_BASE 0x80000000

#endif