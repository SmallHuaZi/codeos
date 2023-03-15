#ifndef __STD_TYPE_HPP__
#define __STD_TYPE_HPP__

#include    <arch.hpp>

namespace os
{

    namespace internal
    {
        typedef     unsigned long long  __uid_t;
        typedef     unsigned long long  __tid_t;
        typedef     unsigned long long  __pid_t;
        typedef     unsigned long long  __time_t;
        
    } // namespace internal



    typedef     char        i8;
    typedef     short       i16;
    typedef     int         i32;


    typedef     unsigned char       u8;
    typedef     unsigned short      u16;
    typedef     unsigned int        u32;


#if defined(__64BIT) && __64BIT == 1ul
    typedef     long long               isize;      // depends paltform
    typedef     unsigned long long      usize;      // depends platform
    typedef     long long               i64;
    typedef     unsigned long long      u64;
#else
#if defined(__32BIT)
    typedef     int             isize;
    typedef     unsigned int    usize;
#endif
#endif

} // namespace os


#endif