#ifndef GDV_MP_BIND_H_
#define GDV_MP_BIND_H_

#include <gdv/mp/type_list.h>
#include <gdv/mp/algorithm.h>

namespace gdv {
namespace mp {

template <size_t I>
struct placeholder {
    static constexpr size_t value = I;
};

namespace detail {

template <size_t I, typename Args1, typename Args2>
struct replace_placeholder;
template <size_t I, typename... Args1, typename Head, typename... Tail>
struct replace_placeholder<I, type_list<Args1...>, type_list<Head, Tail...> >
    : public ::std::conditional<
        ::std::is_same<
            typename ::gdv::mp::find<
                typename ::gdv::mp::begin<type_list<Args1...> >::type,
                typename ::gdv::mp::end<type_list<Args1...> >::type,
                ::gdv::mp::placeholder<I>
            >::type,
            typename ::gdv::mp::end<type_list<Args1...> >::type
        >::value,
        typename ::gdv::mp::concat<
            type_list<Args1...>,
            type_list<Head, Tail...>
        >::type,
        typename ::gdv::mp::detail::replace_placeholder<
            I + 1,
            typename ::gdv::mp::replace<
                typename ::gdv::mp::begin<type_list<Args1...> >::type,
                typename ::gdv::mp::end<type_list<Args1...> >::type,
                ::gdv::mp::placeholder<I>,
                Head
            >::type,
            type_list<Tail...> >::type > {
};
template <size_t I, typename... Args1>
struct replace_placeholder<I, type_list<Args1...>, type_list<> >
    : public ::std::enable_if<
        ::std::is_same<
            typename ::gdv::mp::find<
                typename ::gdv::mp::begin<type_list<Args1...> >::type,
                typename ::gdv::mp::end<type_list<Args1...> >::type,
                ::gdv::mp::placeholder<I>
            >::type,
            typename ::gdv::mp::end<type_list<Args1...> >::type
        >::value,
        type_list<Args1...> > {
};

} // namespace detail

template <template <typename...> typename Function, typename... Args>
struct bind {
    template <typename... Ty>
    using type = typename ::gdv::mp::detail::receive<
        Function,
        typename ::gdv::mp::detail::replace_placeholder<
            0, type_list<Args...>, type_list<Ty...>
        >::type
    >::type;
};

} // namespace mp
} // namespace gdv

#endif
