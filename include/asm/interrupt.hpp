#ifndef __INTERRUP_HPP__
#define __INTERRUP_HPP__

#include    <common/property.hpp>

namespace os
{
    class interrupt
    {

        __ALWAYS_INLINE
        static void
        sti()
        { asm ("sti     \n\t"::); }


        __ALWAYS_INLINE
        static void
        cli()
        { asm ("cli     \n\t"::); }


        __ALWAYS_INLINE
        static void
        iret()
        { asm ("iret    \n\t"::); }


    };
    
} // namespace os



#endif