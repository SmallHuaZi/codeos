#ifndef __ALIGN_HPP__
#define __ALIGN_HPP__

#include <sys/type.hpp>
#include <common/property.hpp>

namespace mem
{
    using namespace os;

    __ALWAYS_INLINE
    static inline constexpr bool
    is_power_of_two(isize val)
    { return    val > 0 && (val & (val - 1) == 0); }


    __ALWAYS_INLINE
    static inline constexpr usize
    align_upper(usize val, usize ali)
    { return    (val + --ali) & ~(ali); }


    __ALWAYS_INLINE
    static inline constexpr usize
    align_lower(usize val, usize ali)
    { return    (val) & ~(--ali); }

    
} // namespace os


#endif