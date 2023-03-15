#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__


namespace com
{

    template <typename _T>
    class factory
    {
        typedef _T      value_type;
        typedef _T *    pointer;
        typedef _T &    reference;
    

    public:
        template <typename... _Args>
        pointer
        new_instance(_Args ...&&args);
    };
    
} // namespace com




#endif