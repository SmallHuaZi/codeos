#include    <libc++/stddef.hpp>
#include    <libc++/string.hpp>


namespace std
{
    void
    memset(void *dest, char const c, size_t const n)
    {
#if (defined(__X86__) && __86__ == 1ul) || (defined(__X86_64__) && __X86_64__ == 1ul)
	    asm volatile (
	    	"0:                    	\n\t"
	    	"cmp $0, %1            	\n\t"
	    	"jz  1f					\n\t"
	    	"dec %1                 \n\t"
	    	"mov %2, (%0, %1, 1)    \n\t"
	    	"jmp 0b                 \n\t"
	    	"1:"
	    	: "=D"(dest)
	    	: "c"(n), "a"(c)
	    );
#else 
#if (defined(__RISCV__) && __RISCV__ == 1ul) || (defined(__RISCV64__) && __RISCV64__ == 1ul)
        asm volatile (
            "0:"
            "1:"
            : "=D"(dest)
            : "c"(n), "a"(c)
        );
        /***/
#else 
#if (defined(__ARM__) && __ARM__ == 1) || (defined(__ARM64__) && __ARM64__ == 1ul)
        asm volatile (
            "0:"
            "1:"
            : "=D"(dest)
            : "c"(n), "a"(c)
        );
        /***/
#endif
#endif              
#endif
    }


    int 
    memcmp(void const *x, void const *y, size_t const n)
    {
	    int res; 
#if (defined(__X86__) && __86__ == 1ul) || (defined(__X86_64__) && __X86_64__ == 1ul)
	    asm volatile (
	    	"xor %%rax, %%rax	\n\t"
	    	"repz cmpsb		\n\t"
	    	"jecxz	0f		\n\t"
	    	"xor %%edx, %%edx	\n\t"
	    	"xor %%eax, %%eax	\n\t"
	    	"movb -1(%1), %%al	\n\t"
	    	"movb -1(%2), %%dl	\n\t"
	    	"sub %%edx, %%eax	\n\t"
	    	"mov %%eax, %0	\n\t"
	    	"0:				\n\t"
	    	: "=r"(res)
	    	: "D"(x), "S"(y), "c"(n)
	    );
#else 
#if (defined(__RISCV__) && __RISCV__ == 1ul) || (defined(__RISCV64__) && __RISCV64__ == 1ul)
        asm volatile (
            "0:"
            "1:"
            : "=D"(dest)
            : "c"(n), "a"(c)
        );
        /***/
#else 
#if (defined(__ARM__) && __ARM__ == 1) || (defined(__ARM64__) && __ARM64__ == 1ul)
        asm volatile (
            "0:"
            "1:"
            : "=D"(dest)
            : "c"(n), "a"(c)
        );
        /***/
#endif
#endif              
#endif
        return res; 
    }

    

    /*
        Maybe is`s better to use an inline function
    */
    void
    memcpy(void *dest, void const *src, size_t const n)
    {
#if (defined(__X86__) && __86__ == 1ul) || (defined(__X86_64__) && __X86_64__ == 1ul)
        asm volatile (
            "cld    \n\t"
            "rep movsb  \n\t"
            : "=D"(dest)
            : "S"(src), "c"(n)
        );
#else 
#if (defined(__RISCV__) && __RISCV__ == 1ul) || (defined(__RISCV64__) && __RISCV64__ == 1ul)
        asm volatile (
        );
        /***/
#else 
#if (defined(__ARM__) && __ARM__ == 1) || (defined(__ARM64__) && __ARM64__ == 1ul)
        asm volatile (
        );
        /***/
#endif
#endif              
#endif              
    }


    void
    memmove(void *dest, void const *src, size_t n)
    {

#if (defined(__X86__) && __86__ == 1ul) || (defined(__X86_64__) && __X86_64__ == 1ul)
        asm volatile (
            "cmp %%rdi, %%rsi   \n\t"
            "jge 0f   \n\t"            
            "add %2, %%rdi \n\t"
            "add %2, %%rsi \n\t"
		    "inc %2	\n\t"
            "std    \n\t"
		    "jmp 1f	\n\t"
		    "0:		\n\t"
            "cld    \n\t"
		    "1:		\n\t"
            "repz movsb"
            : "=D"(dest)
            : "S"(src), "c"(n)
        );
#else 
#if (defined(__RISCV__) && __RISCV__ == 1ul) || (defined(__RISCV64__) && __RISCV64__ == 1ul)
        asm volatile (
        );
        /***/
#else 
#if (defined(__ARM__) && __ARM__ == 1) || (defined(__ARM64__) && __ARM64__ == 1ul)
        asm volatile (
        );
        /***/
#endif
#endif              
#endif              
    }
} // namespace std
