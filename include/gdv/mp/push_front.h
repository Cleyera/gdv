#ifndef GDV_MP_PUSH_FRONT_H_
#define GDV_MP_PUSH_FRONT_H_

namespace gdv {
namespace mp {

template <typename List, typename Ty>
struct push_front;

template <template <typename...> typename Packer, typename ...Args, typename Ty>
struct push_front<Packer<Args...>, Ty> {
    using type = Packer<Ty, Args...>;
};

template <typename List, typename Ty>
using push_front_t = typename push_front<List, Ty>::type;

} // namespace mp
} // namespace gdv

#endif
