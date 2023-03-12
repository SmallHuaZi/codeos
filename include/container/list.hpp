#ifndef __LIST_HPP__
#define __LIST_HPP__

#include    <common/property.hpp>

#include    "internal/__list.hpp"

namespace os
{
    template <typename _T>
    class list
    {
        typedef     _T      value_type;
        typedef     _T *    pointer;
        typedef     _T &    reference;


    public:
        struct _List_node
            : _List_node_base
        {
            value_type      _M_value_field; 


        public:
            _List_node(_List_node &&) = delete;

            _List_node(_List_node const &) = delete;

            _List_node()
                : _M_value_field(), 
                  _List_node_base()
            {}

            _List_node(reference val)
                : _M_value_field(val), 
                  _List_node_base()
            {}

            _List_node_base(pointer next, 
                            pointer prev, 
                            reference val)
                : _M_value_field(val), 
                  _List_node_base(next, prev)
            {}
        };


        typedef     _List_node      _Node_type;
        typedef     _List_node *    _Node_ptr;
        typedef     internal::_List_node_base     _Node_base_type;
        typedef     internal::_List_node_base    *_Node_base_ptr;


        struct _List_iterator
        {
            typedef     _List_iterator      _Self;


        public:
            __ALWAYS_INLINE
            _List_iterator(_Node_base_ptr *entry)
                : _M_data(static_cast<_Node_ptr>(entry))
            {}

            _List_iterator(_List_iterator &&) = delete;

            _List_iterator(_List_iterator const &) = delete;


        public:
            __ALWAYS_INLINE
            reference
            operator*()
            { return    _M_data->_M_value_field; }


            __ALWAYS_INLINE
            _Self &
            operator++()
            { return    _M_data = _M_data->_M_next, *this }


            __ALWAYS_INLINE
            _Self &
            operator--()
            { return    _M_data = _M_data->_M_prev, *this; }


            __ALWAYS_INLINE
            _Self
            operator++(int)
            {
                _Self   old(*this);
                _M_data = _M_data->_M_next;
                return  old;
            }


            __ALWAYS_INLINE
            _Self
            operator--(int)
            {
                _Self   old(*this);
                _M_data = _M_data->_M_prev;
                return  old;
            }


        public:
            _Node_ptr   _M_data;
        };


        typedef     _List_iterator      itr;


    public:
        list() = default;

        list(list &&) = delete;

        list(list const &) = delete;


    public:
        __ALWAYS_INLINE
        void
        add_front(_Node_ptr fresh)
        { internal::__list_add_front(_M_head._M_next, fresh); }


        __ALWAYS_INLINE
        void
        add_tail(_Node_ptr fresh)
        { internal::__list_add_tail(_M_head._M_prev, fresh); }


        __ALWAYS_INLINE
        void
        replace(itr fresh, itr stale)
        { internal::__list_replace(fresh._M_data, stale._M_data); }


        __ALWAYS_INLINE
        void
        replace(_Node_ptr fresh, _Node_ptr stale)
        { internal::__list_replace(fresh, stale); }


        __ALWAYS_INLINE
        void
        replace(itr start, itr finish, itr start1, itr finish1)
        { internal::__list_range_replace(start._M_data, finish._M_data, start1._M_data, finish1._M_data); }


        __ALWAYS_INLINE
        void
        merge_front(list &other)
        { internal::__list_splice_front(&_M_head, &other._M_head); }


        __ALWAYS_INLINE
        void
        merge_tail(list &other)
        { internal::__list_splice_tail(&_M_head, &other._M_head); }


        __ALWAYS_INLINE
        void
        erase(_Node_ptr entry)
        { internal::__list_delete(entry->_M_prev, entry->_M_next); }


        __ALWAYS_INLINE
        usize
        size()
        { return    _M_head._M_counter; }


        __ALWAYS_INLINE
        itr 
        begin()
        { return    itr(_M_head->_M_next); }


        __ALWAYS_INLINE
        itr
        end()
        { return    itr(_M_head); }


    private:
        internal::_List_head        _M_head;

    };
    
} // namespace os



#endif