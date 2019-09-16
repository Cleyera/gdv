#ifndef  GDV_MP_ITERATOR_H_
#define GDV_MP_ITERATOR_H_

#include <type_traits>
#include "config.h"
#include "pack_operations.h"

namespace gdv {
namespace mp {

namespace detail {

template <template <typename...> typename Container, typename Distance, typename Head, typename Tail>
struct iterator {
    template <typename... Ty>
    using container_type = Container<Ty...>;
    using difference_type = Distance;
    using head = Head;
    using tail = Tail;
};

} // namespace detail

template <typename... Ty>
struct bidirectional_iterator;

template <template <typename...> typename Ty,
    typename Head, typename... Tail, typename... Prev>
struct bidirectional_iterator<Ty<Head, Tail...>, Ty<Prev...> >
    : public ::gdv::mp::detail::iterator<Ty, size_t,
    typename ::gdv::mp::reverse<Ty<Prev...> >::type, Ty<Head, Tail...> > {
    using type = Head;
    using next = bidirectional_iterator<Ty<Tail...>, Ty<Head, Prev...> >;
    using prev = bidirectional_iterator<
        Ty<typename ::gdv::mp::head<Prev...>::type, Head, Tail...>,
        typename ::gdv::mp::tail<Ty<Prev...> >::type
    >;
};

template <template <typename...> typename Ty, typename Head, typename... Tail>
struct bidirectional_iterator<Ty<Head, Tail...>, Ty<> >
    : public ::gdv::mp::detail::iterator<Ty, size_t, Ty<>, Ty<Head, Tail...> > {
    using type = Head;
    using next = bidirectional_iterator<Ty<Tail...>, Ty<Head> >;
};

template <template <typename...> typename Ty, typename Head, typename... Tail>
struct bidirectional_iterator<Ty<>, Ty<Head, Tail...> >
    : public ::gdv::mp::detail::iterator<Ty, size_t,
    typename ::gdv::mp::reverse<Ty<Head, Tail...> >::type, Ty<> > {
    using prev = bidirectional_iterator<Ty<Head>, Ty<Tail...> >;
};

template <template <typename...> typename Ty>
struct bidirectional_iterator<Ty<> >
    : public ::gdv::mp::detail::iterator<Ty, size_t, Ty<>, Ty<> > {};

template <typename... Ty>
struct begin;
template <template <typename...> typename Ty, typename... Elements>
struct begin<Ty<Elements...> > {
    using type = bidirectional_iterator<Ty<Elements...>, Ty<> >;
};
template <typename... Ty>
using begin_t = typename ::gdv::mp::begin<Ty...>::type;

template <typename... Ty>
struct end;
template <template <typename...> typename Ty, typename... Elements>
struct end<Ty<Elements...> > {
    using type = bidirectional_iterator<
        Ty<>, typename ::gdv::mp::reverse<Ty<Elements...> >::type>;
};
template <typename... Ty>
using end_t = typename ::gdv::mp::end<Ty...>::type;

template <typename Iterator, size_t I = 1>
struct next {
    using type = typename ::gdv::mp::next<typename Iterator::next, I - 1>::type;
};
template <typename Iterator>
struct next<Iterator, 0> {
    using type = Iterator;
};
template <typename Iterator, size_t I = 1>
using next_t = typename ::gdv::mp::next<Iterator, I>::type;

template <typename Iterator, size_t I = 1>
struct prev {
    using type = typename ::gdv::mp::prev<typename Iterator::prev, I - 1>::type;
};
template <typename Iterator>
struct prev<Iterator, 0> {
    using type = Iterator;
};
template <typename Iterator, size_t I = 1>
using prev_t = typename ::gdv::mp::prev<Iterator, I>::type;

template <typename Begin, typename End, size_t N>
struct distance_impl {
    static constexpr size_t value = ::gdv::mp::distance_impl<
        typename Begin::next, End, N + 1>::value;
};
template <typename Iterator, size_t N>
struct distance_impl <Iterator, Iterator, N> {
    static constexpr size_t value = N;
};
template <typename Begin, typename End>
struct distance {
    static constexpr size_t value = ::gdv::mp::distance_impl<Begin, End, 0>::value;
};
#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
template <typename Begin, typename End>
static constexpr size_t distance_v = ::gdv::mp::distance<Begin, End>::value;
#endif /*GDV_MP_ENABLE_VARIABLE_TEMPLATES*/

} // namespace mp
} // namespace gdv

#endif
