#include    <container/internal/__list.hpp>


namespace os
{

    namespace internal
    {

        void
        __list_add_tail(_List_node_base *entry, 
                        _List_node_base *fresh)    
        {
            _List_node_base *old_next { entry->_M_next };

            fresh->_M_next      =   old_next;
            fresh->_M_prev      =   entry;
            entry->_M_next      =   fresh; 
            old_next->_M_prev   =   fresh;
        }


        void
        __list_add_front(_List_node_base *entry,
                         _List_node_base *fresh)
        {
            _List_node_base *old_prev { entry->_M_prev };

            fresh->_M_next      =   entry;
            fresh->_M_prev      =   old_prev;
            entry->_M_prev      =   fresh;
            old_prev->_M_next   =   fresh;
        }


        void
        __list_splice_tail(_List_head *fresh, 
                           _List_head *stale)
        {
            _List_node_base *front_of_stale { stale->_M_next}; 
            _List_node_base *tail_of_stale  { stale->_M_prev };
            _List_node_base *tail_of_fresh  { fresh->_M_prev};
            
            fresh->_M_prev = tail_of_stale;
            tail_of_stale->_M_next  = fresh;
            tail_of_fresh->_M_next  = front_of_stale;
            front_of_stale->_M_prev = tail_of_fresh;
            
            *stale = _List_head();
        }


        void
        __list_splice_front(_List_head *fresh, 
                            _List_head *stale)
        {
            _List_node_base *front_of_stale { stale->_M_next };
            _List_node_base *tail_of_stale  { stale->_M_prev };
            _List_node_base *front_of_fresh { fresh->_M_next };

            fresh->_M_next = front_of_stale;
            front_of_stale->_M_prev = fresh;
            tail_of_stale->_M_next  = front_of_fresh;
            front_of_fresh->_M_prev = tail_of_stale;

            *stale = _List_head();
        }
            

        void
        __list_replace(_List_node_base *fresh,
                       _List_node_base *stale)
        {
            _List_node_base *prev_of_stale { stale->_M_prev };
            _List_node_base *next_of_stale { stale->_M_next };

            prev_of_stale->_M_next = fresh;
            next_of_stale->_M_prev = fresh;
            fresh->_M_prev = prev_of_stale;
            fresh->_M_next = next_of_stale;
        }


        void
        __list_range_replace(_List_node_base *start, 
                             _List_node_base *finish,
                             _List_node_base *start1,
                             _List_node_base *finish1)
        {
            _List_node_base *prev_of_old { start1->_M_prev };
            _List_node_base *next_of_old { finish1->_M_next };

            prev_of_old->_M_next = start;
            next_of_old->_M_prev = finish;
            start->_M_prev  = prev_of_old;
            finish->_M_next = next_of_old;
        }

        
    } // namespace internal
    
} // namespace os
