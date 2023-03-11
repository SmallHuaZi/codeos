#include    "inode.hpp"


namespace fs
{

    namespace ext2
    {

        inode::
            inode(disk_inode *dino, task *t)
                : _M_disk_map(dino),
                  _M_write(false),
                  _M_update(true),
                  _M_task(t)
            {}


        struct inode *
        inode::
            _S_alloc_inode()
        {

        }


        void
        inode::
            _S_free_inode(struct inode *ino)
        {

        }
        
    } // namespace ext2
    
    
} // namespace fs
