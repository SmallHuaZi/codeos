#ifndef __BUF_HEAD_HPP__
#define __BUF_HEAD_HPP__


#include    <sys/type.hpp>
#include    <common/property.hpp>
#include    <container/list.hpp>

namespace fs
{

    namespace ext2
    {
        using namespace os;


        struct buffer_head 
        {
        private:
            typedef     list<struct task *>         taks_list;
            typedef     list<struct buffer_head*>   buf_list;


        public:
            i8       *_M_data; 
            u8        _M_dev;
            u8        _M_dirty;
            u8        _M_users;
            u32       _M_blocks;

            taks_list   _M_wait_list;
            buf_list    _M_free_list; 
            buf_list    _M_list;
        };
        
    } // namespace ext2
    
    
} // namespace fs





#endif