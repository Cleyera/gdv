#ifndef GDV_MP_BIND_H_
#define GDV_MP_BIND_H_

#include <tuple>
#include <gdv/mp/concat.h>
#include <gdv/mp/none_of.h>
#include <gdv/mp/replace.h>

namespace gdv {
namespace mp {

template <size_t I>
struct placeholder {
    static constexpr size_t value = I;
};

namespace detail {

template <size_t I>
struct is_placeholder {
    template <typename Ty>
    struct type : public ::std::conditional<
        ::std::is_same<typename ::gdv::mp::placeholder<I>, Ty>::value,
        ::std::true_type, ::std::false_type
    >::type {
    };
};

template <size_t I, typename Args1, typename Args2>
struct replace_placeholder;

template <size_t I, typename... Args1, typename Head, typename... Tail>
struct replace_placeholder<I, ::std::tuple<Args1...>, ::std::tuple<Head, Tail...> >
    : public ::std::conditional<
        ::gdv::mp::none_of<
            ::std::tuple<Args1...>,
            ::gdv::mp::detail::is_placeholder<I>::template type
        >::value,
        typename ::gdv::mp::concat<
            ::std::tuple<Args1...>,
            ::std::tuple<Head, Tail...>
        >::type,
        typename ::gdv::mp::detail::replace_placeholder<
            I + 1,
            typename ::gdv::mp::replace<
                ::std::tuple<Args1...>, ::gdv::mp::placeholder<I>, Head
            >::type,
            ::std::tuple<Tail...>
        >::type
    > {
};

template <size_t I, typename... Args1>
struct replace_placeholder<I, ::std::tuple<Args1...>, ::std::tuple<> >
    : public ::std::enable_if<
        ::gdv::mp::none_of<
            ::std::tuple<Args1...>,
            ::gdv::mp::detail::is_placeholder<I>::template type
        >::value,
        ::std::tuple<Args1...> 
    > {
};

template <template <typename...> typename Function, typename Args>
struct fwd;

template <template <typename...> typename Function, typename ...Args>
struct fwd<Function, ::std::tuple<Args...> > {
    using type = Function<Args...>;
};

} // namespace detail

template <template <typename...> typename Function, typename ...Args>
struct bind {
    template <typename... Ty>
    using type = typename ::gdv::mp::detail::fwd<
        Function,
        typename ::gdv::mp::detail::replace_placeholder<
            0, ::std::tuple<Args...>, ::std::tuple<Ty...>
        >::type
    >::type;
};


template <template <typename...> typename Function, typename ...Args>
using bind_t = typename ::gdv::mp::bind<Function, Args...>::type;

} // namespace mp
} // namespace gdv

#endif
