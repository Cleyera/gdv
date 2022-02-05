#ifndef GDV_MP_ANY_OF_H_
#define GDV_MP_ANY_OF_H_

#include <type_traits>
#include <gdv/mp/config.h>

namespace gdv {
namespace mp {

namespace detail {
template <template <typename> typename Pred, typename ...Args>
struct any_of;

template <template <typename> typename Pred, typename Head, typename ...Tail>
struct any_of<Pred, Head, Tail...> : public ::std::conditional<
    Pred<Head>::value,
    ::std::true_type,
    ::gdv::mp::detail::any_of<Pred, Tail...>
>::type {
};

template <template <typename> typename Pred, typename Ty>
struct any_of<Pred, Ty> : public ::std::conditional<
    Pred<Ty>::value, ::std::true_type, ::std::false_type
>::type {
};

} // namespace detail

template <typename Args, template <typename> typename Pred>
struct any_of : public ::gdv::mp::detail::any_of<Pred, Args> {
};

template <
    template <typename...> typename Packer,
    typename ...Args,
    template <typename> typename Pred>
struct any_of<Packer<Args...>, Pred>
    : public ::gdv::mp::detail::any_of<Pred, Args...> {
};

#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
template <typename Ty, template <typename> typename Pred>
static constexpr bool any_of_v = ::gdv::mp::any_of<Ty, Pred>::value;
#endif /*GDV_MP_ENABLE_VARIABLE_TEMPLATES*/

} // namespace mp
} // namespace gdv

#endif
