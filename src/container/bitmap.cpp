#include    <libc/string.hpp>
#include    <container/bitmap.hpp>


namespace os
{

    /// @brief Set The Specified Byte To One 
    void
    bitmap:: 
        set(usize const pos)
    {
        if(pos > (_M_len << 3))
            return;

        usize pos_of_byte = pos >> 3;
        u8 pos_of_bit  = pos % 8;
        u8 vaild_bit   = 1 << pos_of_bit;

        u8 *data_ptr = (u8 *)_M_bit;
        data_ptr[pos_of_byte] |= vaild_bit;
    }




    /// @brief Set A Length Of Bytes From The Specified Position To One 
    void
    bitmap::
        set(usize const pos, usize const len)
    {
        if((pos + len) > (_M_len << 3))
            return;
        if(1 == len) 
            return set(pos);

        u8 pos_of_bit = pos % 8;
        usize pos_of_byte = pos >> 3;

        usize nbytes = (len + pos_of_bit >> 3);
        if ((len + pos_of_bit) % 8)
            ++nbytes;

        u8 bytes[nbytes];
        std::memset(bytes, 0xff, nbytes);

        bytes[0] <<= pos_of_bit;
        if (len < (8 - pos_of_bit)) {
            u8 ofs = 8 - pos_of_bit - len;
            bytes[0] <<= ofs;
            bytes[0] >>= ofs;
        } 
        else {
            usize end_byte_fill_count = (len + pos_of_bit - 8) % 8;
            if (end_byte_fill_count) {
                bytes[nbytes - 1] >>= 8 - end_byte_fill_count;
            }
        }
        

        u8 *data_ptr = (u8 *)_M_bit;
        for (usize idx {0}; idx < nbytes; ++idx) {
            data_ptr[pos_of_byte + idx] |= bytes[idx];
        }
    }




    /// @brief Set The Spedcified Byte To Zero
    void
    bitmap::
        clear(usize const pos)
    {
        if(pos > (_M_len << 3))
            return;

        usize pos_of_byte = pos >> 3;
        u8 pos_of_bit = pos % 8;
        u8 high_bit   = 0xff << (pos_of_bit + 1);
        u8 low_bit    = 0xff >> (8 - pos_of_bit);
        u8 *byte_ptr  = (u8 *)(_M_bit);

        high_bit |= low_bit;
        byte_ptr[pos_of_byte] &= high_bit;
    }



    /// @brief Set A Length Of Bytes From The Specified Position To Zero
    void
    bitmap::
        clear(usize const pos, usize const len)
    {
        if (pos > (_M_len << 3))
            return;

        usize pos_of_byte = pos >> 3; 
        u8 pos_of_bit = (pos % 8);

        usize nbytes = (len + pos_of_bit >> 3);
        if (len + pos_of_bit % 8) 
            ++nbytes;
        u8 bytes[nbytes];
        std::memset(bytes, 0, sizeof(bytes));

        u8 high_bit = 0xff << (pos_of_bit + len);
        u8 low_bit  = 0xff >> (8 - pos_of_bit);
        bytes[0] = high_bit | low_bit;
        if (len > (8 - pos_of_bit)) {
            usize end_byte_clear_count = (len + pos_of_bit - 8) % 8; 
            if (end_byte_clear_count) {
                bytes[nbytes - 1] = 0xff;
                bytes[nbytes - 1] >>= end_byte_clear_count;
                bytes[nbytes - 1] <<= end_byte_clear_count;
            }
        }

        u8 *data_ptr = (u8 *)_M_bit;
        for (usize idx {0}; idx < nbytes; ++idx) {
            data_ptr[pos_of_byte + idx] &= bytes[idx];
        }
    }


} // namespace os
