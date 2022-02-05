#ifndef GDV_MP_NONE_OF_H_
#define GDV_MP_NONE_OF_H_

#include <type_traits>
#include <gdv/mp/config.h>

namespace gdv {
namespace mp {

namespace detail {

template <template <typename> typename Pred, typename ...Args>
struct none_of;

template <template <typename> typename Pred, typename Head, typename ...Tail>
struct none_of <Pred, Head, Tail...>: public ::std::conditional<
    Pred<Head>::value,
    ::std::false_type,
    ::gdv::mp::detail::none_of<Pred, Tail...>
>::type {
};

template <template <typename> typename Pred, typename Ty>
struct none_of<Pred, Ty> : public ::std::conditional<
    Pred<Ty>::value, ::std::false_type, ::std::true_type
>::type {
};

template <template <typename> typename Pred>
struct none_of<Pred> : public ::std::true_type {};

} // namespace detail

template <typename Args, template <typename> typename Pred>
struct none_of : public ::gdv::mp::detail::none_of<Pred, Args> {
};

template <
    template <typename...> typename Packer,
    typename ...Args,
    template <typename> typename Pred>
struct none_of<Packer<Args...>, Pred> :
    public ::gdv::mp::detail::none_of<Pred, Args...> {
};

#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
template <typename Ty, template <typename> typename Pred>
static constexpr bool none_of_v = ::gdv::mp::none_of<Ty, Pred>::value;
#endif /*GDV_MP_ENABLE_VARIABLE_TEMPLATES*/

} // namespace mp
} // namespace gdv

#endif
