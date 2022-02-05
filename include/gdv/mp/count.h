#ifndef GDV_MP_COUNT_H_
#define GDV_MP_COUNT_H_

#include <type_traits>

namespace gdv {
namespace mp {

template <typename Args, typename Ty>
struct count;

template <
    template <typename...> typename Packer,
    typename Head,
    typename ...Tail,
    typename Ty>
struct count<Packer<Head, Tail...>, Ty> {
    static constexpr size_t value = count<Packer<Tail...>, Ty>::value
        + ::std::conditional<
            ::std::is_same<Head, Ty>::value,
            ::std::integral_constant<size_t, 1>,
            ::std::integral_constant<size_t, 0>
        >::type::value;
};

template <template <typename...> typename Packer, typename Ty>
struct count <Packer<>, Ty> {
    static constexpr size_t value = 0;
};

#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
template <typename Args, typename Ty>
static constexpr size_t count_v = ::gdv::mp::count<Args, Ty>::value;
#endif /*GDV_MP_ENABLE_VARIABLE_TEMPLATES*/

} // namespace mp
} // namespace gdv

#endif
