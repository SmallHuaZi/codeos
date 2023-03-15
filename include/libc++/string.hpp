#ifndef __STRING_HPP__
#define __STRING_HPP__

#include    "ctype.hpp"
#include    "common/property.hpp"

namespace std 
{

    int 
    memcmp(void const *x, void const *y, size_t const n);


    void
    memset(void *dest, size_t const n, char const v);


    void
    memmove(void *dest, void const *src, size_t const n);


    void
    memcpy(void *dest, void *const src, size_t const n);


} // namespace os




#endif