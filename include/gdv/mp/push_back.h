#ifndef GDV_MP_PUSH_BACK_H_
#define GDV_MP_PUSH_BACK_H_

namespace gdv {
namespace mp {

template <typename List, typename Ty>
struct push_back;

template <
    template <typename...> typename Packer,
    typename ...Args,
    typename Ty>
struct push_back<Packer<Args...>, Ty> {
    using type = Packer<Args..., Ty>;
};

template <typename List, typename Ty>
using push_back_t = typename ::gdv::mp::push_back<List, Ty>::type;

} // namespace mp
} // namespace gdv

#endif
