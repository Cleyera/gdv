#ifndef GDV_MP_REMOVE_IF_H_
#define GDV_MP_REMOVE_IF_H_

#include <type_traits>
#include <gdv/mp/push_front.h>

namespace gdv {
namespace mp {

template <typename Args, template <typename> typename Pred>
struct remove_if;

template <
    template <typename...> typename Packer,
    typename Head,
    typename ...Tail,
    template <typename> typename Pred>
struct remove_if<Packer<Head, Tail...>, Pred>
    : public ::std::conditional<
        Pred<Head>::value,
        typename ::gdv::mp::remove_if<Packer<Tail...>, Pred>,
        ::gdv::mp::push_front<
            typename ::gdv::mp::remove_if<Packer<Tail...>, Pred>::type,
            Head
        >
    >::type {
};

template <
    template <typename...> typename Packer,
    template <typename> typename Pred>
struct remove_if <Packer<>, Pred> {
    using type = Packer<>;
};

template <typename Args, template <typename> typename Pred>
using remove_if_t = typename ::gdv::mp::remove_if<Args, Pred>::type;

} // namespace mp
} // namespace gdv

#endif
