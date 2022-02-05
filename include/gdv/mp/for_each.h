#ifndef GDV_MP_FOR_EACH_H_
#define GDV_MP_FOR_EACH_H_

#include <type_traits>
#include <gdv/mp/push_front.h>

namespace gdv {
namespace mp {

template <typename Args, template <typename> typename Pred>
struct for_each;

template <
    template <typename...> typename Packer,
    typename Head,
    typename ...Tail,
    template <typename> typename Pred>
struct for_each<Packer<Head, Tail...>, Pred> {
    using type = typename ::gdv::mp::push_front<
        typename ::gdv::mp::for_each<
            Packer<Tail...>,
            Pred
        >::type,
        typename Pred<Head>::type
    >::type;
};

template <
    template <typename...> typename Packer,
    template <typename> typename Pred>
struct for_each<Packer<>, Pred> {
    using type = Packer<>;
};

template <typename Args, template <typename> typename Pred>
using for_each_t = typename ::gdv::mp::for_each<Args, Pred>::type;

} // namespace mp
} // namespace gdv

#endif
