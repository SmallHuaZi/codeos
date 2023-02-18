#ifndef     __PROPERTY_HPP__
#define     __PROPERTY_HPP__

#ifdef      __GNUC__
#define     __PACKED                [[gnu::packed]]
#define     __ALIGNAS(size)         [[gnu::aligned(size)]]
#define     __ALWAYS_INLINE         [[gnu::always_inline]] 
#elif       _MSC_VER
#define     __PACKED                 
#define     __ALIGNAS(size)         alignas(size) 
#define     __ALWAYS_INLINE         [[msvc::__forceinline]]
#endif


/// @cppstandard: property
#define     __NODISCARD(msg)        [[nodiscard(#msg)]]
#define     __NORETURN              [[noretrurn]]

#endif