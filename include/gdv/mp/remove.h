#ifndef GDV_MP_REMOVE_H_
#define GDV_MP_REMOVE_H_

#include <tuple>
#include <type_traits>
#include <gdv/mp/push_front.h>

namespace gdv {
namespace mp {

template <typename Args, typename Ty>
struct remove;

template <
    template <typename...> typename Packer,
    typename Head,
    typename ...Tail,
    typename Ty>
struct remove<Packer<Head, Tail...>, Ty>
    : public ::std::conditional<
        ::std::is_same<Head, Ty>::value,
        typename ::gdv::mp::remove<Packer<Tail...>, Ty>,
        ::gdv::mp::push_front<
            typename ::gdv::mp::remove<Packer<Tail...>, Ty>::type,
            Head
        >
    >::type {
};

template <template <typename...> typename Packer, typename Ty>
struct remove <Packer<>, Ty> {
    using type = Packer<>;
};

template <typename Args, typename Ty>
using remove_t = typename ::gdv::mp::remove<Args, Ty>::type;

} // namespace mp
} // namespace gdv

#endif
