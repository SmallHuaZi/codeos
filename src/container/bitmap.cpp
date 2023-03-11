#include    <libc/string.hpp>
#include    <container/bitmap.hpp>


namespace os
{
    void
    bitmap:: 
        set(usize const pos)
    {
        static constexpr const int USIZE_BITS = sizeof(usize) << 3;

        if(pos > (_M_len << 3))
            return;

        u8 pos_of_byte = pos >> USIZE_BITS;
        u8 pos_of_bit  = pos % USIZE_BITS;
        u8 vaild_bit   = 1 << pos_of_bit;

        u8 *byte_ptr = (u8 *)(_M_bit);
        byte_ptr[pos_of_byte] |= vaild_bit;
    }




    /**   11111111
     * x: 00011111
     * y: 01111100 
     */
    void
    bitmap::
        set(usize const pos, usize const len)
    {
        if((pos + len) > (_M_len << 3))
            return;
        if(1 == len) 
            return set(pos);

        u8 bytes[(len >> 3) + 1];
        std::memset(bytes, len >> 3, 0xff);
        bytes[0] <<= pos;
    }



    /**      11111111 
     *  x:   11111000 << 3  00000000 << 8 11111110 << 1
     *  y:   00000011 >> 6  01111111 >> 1 00000000 >> 8 
     *  x|y: 11111011
     *  
     */
    void
    bitmap::
        clear(usize const pos)
    {
        if(pos > (_M_len << 3))
            return;

        u8 pos_of_byte = pos >> 3;
        u8 pos_of_bit  = (pos % sizeof(u8));
        u8 high_bit   = 0xff << (pos_of_bit + 1);
        u8 low_bit    = 0xff >> (sizeof(u8) - pos_of_bit);
        u8 *byte_ptr  = (u8 *)(_M_bit);

        high_bit |= low_bit;
        byte_ptr[pos_of_byte] &= high_bit;
    }



    void
    bitmap::
        clear(usize const pos, usize const len)
    {

    }


} // namespace os
