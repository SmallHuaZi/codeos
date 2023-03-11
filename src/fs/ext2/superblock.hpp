#ifndef __SUPERBLOCK_HPP__
#define __SUPERBLOCK_HPP__


#include    <sys/type.hpp>
#include    <common/property.hpp>

namespace fs
{
    namespace ext2 
    {
        /// @warning: it`s unsafe
        using namespace os;


        struct __PACKED super_block
        {
            usize       _M_inodes_count;
            usize       _M_blocks_count;
            usize       _M_reserved_blocks_count;
            usize       _M_free_blocks_count;
            usize       _M_free_inodes_count;
            usize       _M_first_data_block;
            usize       _M_mkfs_time;

            u32         _M_blocks_per_group;
            u32         _M_inodes_per_group;

            u16         _M_first_inode;         // first non-reserved inode number
            u16         _M_inode_size;
            u16         _M_gdesc_size;
            u16         _M_block_group_no;
            u8          _M_prealloc_dir_blocks;
            u8          _M_vname_len;
            u8          _M_volime_name[0];
        };

    }
    
} // namespace fs



#endif