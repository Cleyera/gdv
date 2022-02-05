#ifndef GDV_MP_ALL_OF_H_
#define GDV_MP_ALL_OF_H_

#include <type_traits>
#include <gdv/mp/config.h>

namespace gdv {
namespace mp {

namespace detail {

template <template <typename> typename Pred, typename ...Args>
struct all_of;

template <template <typename> typename Pred, typename Head, typename ...Tail>
struct all_of <Pred, Head, Tail...>: public ::std::conditional<
    Pred<Head>::value,
    ::gdv::mp::detail::all_of<Pred, Tail...>,
    ::std::false_type
>::type {
};

template <template <typename> typename Pred, typename Ty>
struct all_of<Pred, Ty> : public ::std::conditional<
    Pred<Ty>::value, ::std::true_type, ::std::false_type
>::type {
};

template <template <typename> typename Pred>
struct all_of<Pred> : public ::std::true_type {};

} // namespace detail

template <typename Args, template <typename> typename Pred>
struct all_of : public ::gdv::mp::detail::all_of<Pred, Args> {
};

template <
    template <typename...> typename Packer,
    typename ...Args,
    template <typename>
    typename Pred>
struct all_of<Packer<Args...>, Pred>
    : public ::gdv::mp::detail::all_of<Pred, Args...> {
};

#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
template <typename Ty, template <typename> typename Pred>
static constexpr bool all_of_v = ::gdv::mp::all_of<Ty, Pred>::value;
#endif /*GDV_MP_ENABLE_VARIABLE_TEMPLATES*/

} // namespace mp
} // namespace gdv

#endif
