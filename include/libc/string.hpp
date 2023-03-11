#ifndef __STRING_HPP__
#define __STRING_HPP__

#include    "ctype.hpp"

namespace std 
{
    void
    memcpy(void *src, void *dest, size_t n);


    int 
    memcmp(void *x, void *y, size_t n);


    void
    memset(void *x, size_t n, char v);


    void
    memmove(void *dest, void *src, size_t n);
    
} // namespace os




#endif