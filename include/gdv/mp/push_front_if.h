#ifndef GDV_MP_PUSH_FRONT_IF_H_
#define GDV_MP_PUSH_FRONT_IF_H_

#include <type_traits>

namespace gdv {
namespace mp {

template <typename List, typename Ty, template <typename> typename Pred>
struct push_front_if;

template <
    template <typename...> typename Packer,
    typename ...Args,
    typename Ty,
    template <typename> typename Pred>
struct push_front_if<Packer<Args...>, Ty, Pred>
    : public ::std::conditional<
        Pred<Ty>::value,
        Packer<Ty, Args...>,
        Packer<Args...>
    > {
};

template <typename List, typename Ty, template <typename> typename Pred>
using push_front_if_t = typename ::gdv::mp::push_front_if<List, Ty, Pred>::type;

} // namespace mp
} // namespace gdv

#endif
