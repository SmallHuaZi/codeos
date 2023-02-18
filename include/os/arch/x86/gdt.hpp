#ifndef __GDT_HPP__
#define __GDT_HPP__

#include    <common/type.hpp>

#include    "x86_config.hpp"

namespace os
{
    class gdt
    {
    public:
        struct desc_selector
        {

        };

    
    private:
        desc_selector           [];
    };

} // namespace os



#endif