#ifndef GDV_MP_CONCAT_H_
#define GDV_MP_CONCAT_H_

#include <type_traits>

namespace gdv {
namespace mp {

template <typename Args1, typename Args2>
struct concat;

template <
    template <typename...> typename Packer,
    typename ...Args1,
    typename ...Args2>
struct concat <Packer<Args1...>, Packer<Args2...> > {
    using type = Packer<Args1..., Args2...>;
};

template <typename L1, typename L2>
using concat_t = typename ::gdv::mp::concat<L1, L2>::type;

} // namespace mp
} // namespace gdv

#endif
