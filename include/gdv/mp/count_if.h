#ifndef GDV_MP_COUNT_IF_H_
#define GDV_MP_COUNT_IF_H_

#include <type_traits>

namespace gdv {
namespace mp {

template <typename Args, template <typename> typename Pred>
struct count_if;

template <
    template <typename...> typename Packer,
    typename Head,
    typename ...Tail,
    template <typename> typename Pred>
struct count_if<Packer<Head, Tail...>, Pred> {
    static constexpr size_t value = count_if<Packer<Tail...>, Pred>::value
        + ::std::conditional<
            Pred<Head>::value,
            ::std::integral_constant<size_t, 1>,
            ::std::integral_constant<size_t, 0>
        >::type::value;
};

template <
    template <typename...> typename Packer,
    template <typename> typename Pred>
struct count_if <Packer<>, Pred> {
    static constexpr size_t value = 0;
};

#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
template <typename Args, template <typename> typename Pred>
static constexpr size_t count_if_v = ::gdv::mp::count_if<Args, Pred>::value;
#endif /*GDV_MP_ENABLE_VARIABLE_TEMPLATES*/

} // namespace mp
} // namespace gdv

#endif
