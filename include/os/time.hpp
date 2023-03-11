#ifndef __TIME_HPP__
#define __TIME_HPP__


#include    <sys/type.hpp>

namespace os 
{ 
    namespace internal 
    {

        template <typename _TimeT = os::internal::__time_t>
        struct _Time_desc 
        {
            _TimeT      _M_data;
        };
    }

    typedef     internal::_Time_desc<>        time_t;
    
} // namespace os




#endif