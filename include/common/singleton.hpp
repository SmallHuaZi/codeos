#ifndef __SINGLETON_HPP__
#define __SINGLETON_HPP__

#include "property.hpp"

namespace com
{

    template <typename _T>
    class singleton
    {
    public:
        typedef   _T *    pointer;
        typedef   _T &    reference;


    public:
        __ALWAYS_INLINE
        static bool
        is_initialized()
        { return    0 != _S_instance; }


        __ALWAYS_INLINE
        static reference 
        get()
        { return    *_S_instance; }


    public:
        __ALWAYS_INLINE
        singleton()
        { if (_S_instance) _S_instance = this; }


        __ALWAYS_INLINE
        virtual
        ~singleton()
        { if (this == _S_instance) _S_instance = 0; }


    private:
        static inline pointer   _S_instance = 0;
    };
    
} // namespace os




#endif