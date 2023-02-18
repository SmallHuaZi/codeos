#ifndef __IO_HPP__
#define __IO_HPP__

#include    <common/type.hpp>
#include    <common/property.hpp>

namespace os
{
    class pio
    {
        public:
        __ALWAYS_INLINE
        static u8 
        in(u8 port) 
        { 
            u8 register val asm ("al");
            __asm__ __volatile__ (
                "inb %0, %%al  \n\t" 
                ::"d"(port)
            ); 

            return  val;
        }


        __ALWAYS_INLINE
        static void 
        out(u8 port, u8 val)
        {
            __asm__ __volatile__ (
                "outb %0, %1    \n\t"
                ::"a"(port) "d"(val)
            );
        }


        __ALWAYS_INLINE
        static u16 
        in(u16 port)
        { 
            u16 register val asm ("ax");
            __asm__ __volatile__ (
                "inw %0, %%ax  \n\t" 
                ::"d"(port)
            ); 

            return  val;
        }


        __ALWAYS_INLINE
        static void 
        out(u16 port, u16 val)
        {
            __asm__ __volatile__ (
                "outw %0, %1    \n\t"
                ::"a"(port) "d"(val)
            );
        }


        __ALWAYS_INLINE
        static u32 
        in(u32 port)
        { 
            u32 register val asm ("eax");
            __asm__ __volatile__ (
                "inl %0, %%eax  \n\t" 
                ::"d"(port)
            ); 

            return  val;
        }


        __ALWAYS_INLINE
        static void 
        out(u32 port, u32 val)
        {
            __asm__ __volatile__ (
                "outl %0, %1    \n\t"
                ::"a"(port) "d"(val)
            );
        }
    };
    
} // namespace os



#endif