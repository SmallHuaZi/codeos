#ifndef __EXT2_HPP__
#define __EXT2_HPP__

#include    <common/property.hpp>


namespace fs
{

    namespace ext2
    {
        struct inode;
        struct dir_ent;
        struct disk_inode;
        struct group_desc;
        struct super_block;


        enum file_type 
            : unsigned char 
        {
            UNKNOWN         = 0x00,     // unkonwn file cagecity 
            DIRECOTORY      = 0x01,     // directory
            REGULAR_FILE    = 0x02,     // normal file 
            SOCKET          = 0x03,     // socket mapping file
            SYMBOLIC_LINK   = 0x04,     // symbol linking file
            DERICE          = 0x05,     // block 
            FIFO            = 0x06
        };



        class __PACKED ext2
        {};
        
    } // namespace ext2
    
} // namespace fs


#endif
