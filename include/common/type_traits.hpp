#ifndef __TYPE_TRAITS_HPP__
#define __TYPE_TRAITS_HPP__


namespace com
{
    template <bool val>
    struct boolean
    { static constexpr bool value = val; };

    using true_type  =  boolean<true>;
    using false_type =  boolean<false>;



    template <typename _Base, typename _Deri>
    struct is_base_of
    {
        static true_type
        _decltype(_Base *);

        static false_type
        _decltype(...);

        static _Deri *
        _declvalue();
        
        static constexpr bool value = decltype(_decltype(_declvalue()))::value;
    };
    
} // namespace com



#endif