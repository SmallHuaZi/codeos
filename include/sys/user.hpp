#ifndef __USER_HPP__
#define __USER_HPP__

#include    <sys/type.hpp>
#include    <common/property.hpp>

namespace os
{

    class __PACKED user
    {
    public:
        typedef internal::__uid_t       id_t;


        id_t
        acquire_id() const
        { return    _M_id; }


        

        user(id_t id)
            : _M_id(id)
        {}


    private:
        internal::__uid_t     _M_id;
    };
    
} // namespace os



#endif