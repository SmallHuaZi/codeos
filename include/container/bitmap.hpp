#ifndef __BITMAP_HPP__
#define __BITMAP_HPP__

#include    <sys/type.hpp>
#include    <common/property.hpp>


namespace os
{

    /**
     *  @pos: from 0 to 7 with byte
     */
    class __PACKED bitmap 
    {
    private:
        usize  _M_len; 
        usize  _M_bit[0];


    public:
        bitmap(bitmap &&) = delete;

        bitmap(bitmap const &) = delete;

        bitmap(usize const len);


    public: 
        void
        set(usize const pos);

        void
        set(usize const pos, usize const len);

        void
        clear(usize const pos);

        void
        clear(usize const pos, usize const len);

        isize
        get(usize const len);

        bool 
        is_dirty(usize const pos);

        void
        filp();

        void
        resize(usize const len);
    };


    __ALWAYS_INLINE
    inline
    bitmap::
        bitmap(usize const len)
            :_M_len(len)
    {}


    __ALWAYS_INLINE
    inline void
    bitmap::
        resize(usize const len)
    { _M_len = len; }
    

} // namespace os



#endif