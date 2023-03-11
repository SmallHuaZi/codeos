#ifndef __GDESC_HPP__
#define __GDESC_HPP__


#include    <sys/type.hpp>
#include    <common/property.hpp>

#include    "config.hpp"

namespace fs
{
    namespace ext2
    {
        /// @warning: is`s unsafe
        using namespace os;

        struct __PACKED group_desc
        {
            usize    _M_bg_block_bitmap;
            usize    _M_bg_inode_bitmap;
            usize    _M_bg_inode_table;
            usize    _M_free_blocks_count;
            usize    _M_free_inodes_count;
            usize    _M_used_dirs_count;        // directories count
            usize    _M_unused_inode_tables;
            u8       _M_checking_code[FS_CHECKING_CODE_LEN];
        };
        
    } // namespace ext2
    
    
} // namespace fs




#endif