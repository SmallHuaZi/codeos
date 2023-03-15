#ifndef __ARCH_HPP__
#define __ARCH_HPP__

#define     __16BIT     0ul 
#define     __32BIT     0ul
#define     __64BIT     1ul


#define     __X86__     1ul
#define     __ARM__     0ul
#define     __RISCV__   0ul


#if defined(__64BIT) && __64BIT == 1ul
#if defined(__X86__) && __X86__ == 1ul
#define     __X86_64__  1ul
#else
#if defined(__ARM__) && __ARM__ == 1ul
#define     __ARM64__   1ul
#else
#if defined(__RISCV) && __RISCV__ == 1ul
#define     __RISCV64__   1ul
#endif
#endif
#endif
#endif




#endif