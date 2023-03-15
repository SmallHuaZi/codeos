#ifndef __CONCEPT_HPP__
#define __CONCEPT_HPP__


namespace com
{

    template <typename _Base, typename _Derived>
    concept IsBaseOf = requires (_Derived *t1, _Derived &t2) 
    {
        { static_cast<_Base *>(t1) };
        { static_cast<_Base &>(t2) };
    };
    
} // namespace com





#endif