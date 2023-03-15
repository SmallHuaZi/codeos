#ifndef     __PROPERTY_HPP__
#define     __PROPERTY_HPP__


#if defined(__GNUC__)
#define     __PACKED                [[gnu::packed]]
#define     __ALIGNAS(size)         [[gnu::aligned(size)]]
#define     __ALWAYS_INLINE         [[gnu::always_inline]] 
#define     __AS_NAKED              [[gnu::naked]]
#else       
#if         defined(_MSC_VER)
#define     __PACKED                 
#define     __ALIGNAS(size)         alignas(size) 
#define     __ALWAYS_INLINE         [[msvc::forceinline]] 
#define     __AS_NAKED              __declspec(naked) 
#endif
#endif


/// @cppstandard: property
#define     __NODISCARD(msg)        [[nodiscard(#msg)]]
#define     __NORETURN              [[noretrurn]]
#define     __MAYBE_UNUSED          [[maybe_unused]]



#endif