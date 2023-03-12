#include    <libc/string.hpp>


namespace std
{
    void
    memset(void *dest, size_t n, char v)
    {
#if defined(__X86_64__)
        asm volatile (
            "loop_set:             \n\t"
            "dec %1                \n\t"
            "mov %2, (%0, %1, 1)   \n\t"
            "cmp $0, %1            \n\t"
            "jnz loop_set          \n\t"
            : "=D"(dest)
            : "c"(n), "a"(v)
        );
#else 
#if defined(__RISCV__)
        /***/
#else 
#if defined(__ARM__)
        /***/
#endif
#endif              
#endif
    }


    int 
    memcmp(void *x, void *y, size_t n)
    {
        int res = 0;
#if defined(__X86_64__)

    asm volatile (
        "   \n\t"
    );
#else 
#if defined(__ARM__)
    /***/
#else
#if defined(__RISCV__)
    /***/
#endif
#endif
#endif
        return res; 
    }

    
} // namespace std
