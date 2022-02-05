#ifndef GDV_MP_REPLACE_IF_H_
#define GDV_MP_REPLACE_IF_H_

#include <type_traits>
#include <gdv/mp/push_front.h>

namespace gdv {
namespace mp {

template <typename Args, template <typename> typename Pred, typename New>
struct replace_if;

template <
    template <typename...> typename Packer,
    typename Head,
    typename ...Tail,
    template <typename> typename Pred,
    typename New>
struct replace_if <Packer<Head, Tail...>, Pred, New>
    : public ::gdv::mp::push_front<
        typename ::gdv::mp::replace_if<Packer<Tail...>, Pred, New>::type,
        typename ::std::conditional<Pred<Head>::value, New, Head>::type
    > {
};

template <
    template <typename...> typename Packer,
    template <typename> typename Pred,
    typename New>
struct replace_if <Packer<>, Pred, New> {
    using type = Packer<>;
};

template <typename Args, template <typename> typename Pred, typename New>
using replace_if_t = typename ::gdv::mp::replace_if<Args, Pred, New>::type;

} // namespace mp
} // namespace gdv

#endif
