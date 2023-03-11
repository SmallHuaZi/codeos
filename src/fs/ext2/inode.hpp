#ifndef __INODE_HPP__
#define __INODE_HPP__


#include    <sys/type.hpp>
#include    <common/property.hpp>

namespace fs 
{

    namespace ext2
    {
        /// @warning: it`s unsafe
        using namespace os;
        
        enum    { EXT2_N_BLOCKS = 12 };


        struct __PACKED disk_inode {
            usize     _M_mode;
            usize     _M_links;
            usize     _M_bptr[EXT2_N_BLOCKS];
            usize     _M_uid;
            usize     _M_gid;
            usize     _M_size;
        };



        struct __PACKED inode {
            struct disk_inode * _M_disk_map;

            // memory mapping
            bool  _M_write;     // write back
            bool  _M_update;    // new data
            void *_M_lock;  // point to lock
            void *_M_dir_acl;   // directory access control list
            void *_M_file_acl;  // file access control list
            struct task *_M_task;  // point to task/thread
            usize        _M_ref_count;
            usize        _M_atime;
            usize        _M_ctime;
            usize        _M_mtime;
            usize        _M_dtime;

        
        private:
            static struct inode * 
            _S_alloc_inode();

            static void
            _S_free_inode(struct inode *ino);

            void
            _M_lock();

            void
            _M_unlock();


        public:
            /// @brief Get inode struct size
            static constexpr int
            mem_size()
            { return    sizeof(struct inode); }


            /// @brief: Alloc a new inode
            static struct inode *
            alloc_inode()
            { return    _S_alloc_inode(); }


            /// @brief: Free a inode
            static void
            free_inode(struct inode *ino)
            { _S_free_inode(ino); }


            /// @brief: Copy inode to the other inode
            static void
            copy(struct inode *d, struct inode *s);


            /// @brief: Copy inode to the other inode and reset d            
            static void
            copy_and_reset(struct inode *d, struct inode *s);


        public:
            inode(struct inode &ino) = delete;
            inode(struct inode &&ino) = delete;


            /// @brief: Create an empty inode
            inode() = default;


            /// @brief: Create an new inode
            inode(struct disk_inode *, struct task *);


            /// @brief: Wait inode lock
            void
            wait();


            /// @brief: Write back disk
            void
            sync();


            /// @brief: Reset inode
            void
            clear();


            operator disk_inode *()
            { return this->_M_disk_map; }


        };

    } // namespace ext2

} // namespace fs




#endif