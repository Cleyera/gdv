#ifndef GDV_MP_PUSH_BACK_IF_H_
#define GDV_MP_PUSH_BACK_IF_H_

#include <type_traits>

namespace gdv {
namespace mp {

template <typename List, typename Ty, template <typename> typename Pred>
struct push_back_if;

template <
    template <typename...> typename Packer,
    typename ...Args,
    typename Ty,
    template <typename> typename Pred>
struct push_back_if<Packer<Args...>, Ty, Pred>
    : public ::std::conditional<
        Pred<Ty>::value,
        Packer<Args..., Ty>,
        Packer<Args...>
    > {
};

template <typename List, typename Ty, template <typename> typename Pred>
using push_back_if_t = typename ::gdv::mp::push_back_if<List, Ty, Pred>::type;

} // namespace mp
} // namespace gdv

#endif
