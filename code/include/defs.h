/**
 * 本文件定义常用数据类型
 */
#ifndef __CHAOSDEFS_H__
#define __CHAOSDEFS_H__

#define _NULL (void *)0
typedef signed int _int32_t;
typedef unsigned int _uint32_t;
typedef signed long long _int64_t;
typedef unsigned long long _uint64_t;
typedef unsigned short _uint16_t;
typedef short _int16_t;
typedef unsigned char _uint8_t;
typedef signed char _int8_t;
typedef unsigned long long _size_t;
typedef signed long longssize_t;
/**
 * 不要使用 intptr_t, uintptr_t，请用 int64_t, uint64_t 代替
 * typedef int64_t intptr_t;
 * typedef uint64_t uintptr_t;
 */

#define typeof __typeof__
#ifdef __compiler_offsetof
#define offsetof(type, member) __compiler_offsetof(type, member)
#else
#define offsetof(type, member) ((uint64_t) & ((type *)0)->member)
#endif
#define container_of(ptr, type, member)                                        \
  ({                                                                           \
    const typeof(((type *)0)->member) *_mptr = (ptr);                          \
    (type *)((char *)_mptr - offsetof(type, member));                          \
  })

#endif
