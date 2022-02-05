#ifndef GDV_MP_REPLACE_H_
#define GDV_MP_REPLACE_H_

#include <type_traits>
#include <gdv/mp/push_front.h>

namespace gdv {
namespace mp {

template <typename Args, typename Old, typename New>
struct replace;

template <
    template <typename...> typename Packer,
    typename Head,
    typename ...Tail,
    typename Old,
    typename New>
struct replace <Packer<Head, Tail...>, Old, New>
    : public ::gdv::mp::push_front<
        typename ::gdv::mp::replace<Packer<Tail...>, Old, New>::type,
        typename ::std::conditional<
            ::std::is_same<Head, Old>::value,
            New,
            Head
        >::type
    > {
};

template <template <typename...> typename Packer, typename Old, typename New>
struct replace <Packer<>, Old, New> {
    using type = Packer<>;
};

template <typename Args, typename Old, typename New>
using replace_t = typename ::gdv::mp::replace<Args, Old, New>::type;

} // namespace mp
} // namespace gdv

#endif
