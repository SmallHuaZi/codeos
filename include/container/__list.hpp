#ifndef ____LIST_HPP__
#define ____LIST_HPP__

#include    <sys/type.hpp>

namespace os
{
    namespace internal 
    {

        struct _List_node_base
        {
            struct _List_node_base  *_M_prev;
            struct _List_node_base  *_M_next;


            _List_node_base()
                : _M_next(0), _M_prev(0)
            {}

            _List_node_base(_List_node_base *next, 
                            _List_node_base *prev)
                : _M_next(next), _M_prev(prev)
            {}
        };


        struct _List_head
            : _List_node_base
        {
            usize       _M_counter;


            _List_head()
                : _M_counter(0), 
                _List_node_base()
            {}
        };




        static inline bool 
        __list_empty(_List_node_base const *entry)
        { return  entry == entry->_M_next; }




        static inline void
        __list_delete(_List_node_base *prev, 
                    _List_node_base *next)
        {
            prev->_M_next = next;
            next->_M_prev = prev;
        }




        void
        __list_add_tail(_List_node_base *entry, 
                        _List_node_base *fresh);




        void
        __list_add_front(_List_node_base *entry, 
                        _List_node_base *fresh);




        void
        __list_splice_tail(_List_head *l1, 
                        _List_head *l2);




        void
        __list_splice_front(_List_head *l1,
                            _List_head *l2);




        void
        __list_replace(_List_node_base *fresh, 
                    _List_node_base *old);



        void
        __list_range_replace(_List_node_base *start, 
                            _List_node_base *finish,
                            _List_node_base *start1,
                            _List_node_base *finish1);

    } // namespace internal

} // namespace os



#endif