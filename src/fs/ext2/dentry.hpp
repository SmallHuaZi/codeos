#ifndef __DIRENT_HPP__
#define __DIRENT_HPP__

#include    <common/property.hpp>

namespace fs
{

    namespace ext2
    {
        struct __PACKED dentry 
        {
            unsigned long long  _M_inode;
            unsigned short      _M_size;
            unsigned short      _M_name_len;
            unsigned char       _M_type; 
#if _MSC_VER
            char                _M_name[3];
#elif __GNUC__
            char                _M_name[0];
#endif
        };
    
    } // namespace ext2

} // namespace fs



#endif