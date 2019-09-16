#ifndef GDV_MP_PACK_OPERATIONS_H_
#define GDV_MP_PACK_OPERATIONS_H_

#include <type_traits>
#include <gdv/mp/config.h>

namespace gdv {
namespace mp {

template <typename... Ty>
struct size {
    static constexpr size_t value = sizeof...(Ty);
};
template <template <typename...> typename Ty, typename... Elements>
struct size<Ty<Elements...> > {
    static constexpr size_t value = ::gdv::mp::size<Elements...>::value;
};
#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
template <typename... Ty>
static constexpr size_t size_v = ::gdv::mp::size<Ty...>::value;
#endif // GDV_MP_ENABLE_VARIABLE_TEMPLATES

template <typename... Ty>
struct max;
template <typename Head, typename... Tail>
struct max<Head, Tail...> {
    static constexpr size_t value = sizeof(Head) > max<Tail...>::value ? sizeof(Head) : max<Tail...>::value;
};
template <typename Ty>
struct max<Ty> {
    static constexpr size_t value = sizeof(Ty);
};
template <template <typename...> typename Ty, typename... Elements>
struct max<Ty<Elements...> > {
    static constexpr size_t value = ::gdv::mp::max<Elements...>::value;
};
#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
template <typename... Ty>
static constexpr size_t max_v = ::gdv::mp::max<Ty...>::value;
#endif // GDV_MP_ENABLE_VARIABLE_TEMPLATES

template <typename... Ty>
struct min;
template <typename Head, typename... Tail>
struct min<Head, Tail...> {
    static constexpr size_t value = sizeof(Head) < min<Tail...>::value ? sizeof(Head) : min<Tail...>::value;
};
template <typename Ty>
struct min<Ty> {
    static constexpr size_t value = sizeof(Ty);
};
template <template <typename...> typename Ty, typename... Elements>
struct min<Ty<Elements...> > {
    static constexpr size_t value = ::gdv::mp::min<Elements...>::value;
};
#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
template <typename... Ty>
static constexpr size_t min_v = ::gdv::mp::min<Ty...>::value;
#endif // GDV_MP_ENABLE_VARIABLE_TEMPLATES

template <typename... Ty>
struct empty : public ::std::false_type {};
template <>
struct empty<> : public ::std::true_type {};
template <template <typename...> typename Ty>
struct empty<Ty<> > : public ::std::true_type {};
#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
template <typename... Ty>
static constexpr bool empty_v = ::gdv::mp::empty<Ty...>::value;
#endif // GDV_MP_ENABLE_VARIABLE_TEMPLATES

template <typename... Ty>
struct head;
template <typename Head, typename... Tail>
struct head<Head, Tail...> {
    using type = Head;
};
template <template <typename...> typename Ty, typename Head, typename... Tail>
struct head<Ty<Head, Tail...> > {
    using type = Head;
};
template <typename... Ty>
using head_t = typename ::gdv::mp::head<Ty...>::type;

template <typename... Ty>
struct tail;
template <template <typename...> typename Ty, typename Head, typename... Tail>
struct tail<Ty<Head, Tail...> > {
    using type = Ty<Tail...>;
};
template <typename... Ty>
using tail_t = typename tail<Ty...>::type;

template <typename... Ty>
struct back;
template <typename Head, typename... Tail>
struct back<Head, Tail...> {
    using type = typename ::gdv::mp::back<Tail...>::type;
};
template <typename Ty>
struct back<Ty> {
    using type = Ty;
};
template <template <typename...> typename Ty, typename... Elements>
struct back<Ty<Elements...> > {
    using type = typename ::gdv::mp::back<Elements...>::type;
};
template <typename... Ty>
using back_t = typename ::gdv::mp::back<Ty...>::type;

template <size_t I, typename... Ty>
struct at;
template <size_t I, typename Head, typename... Tail>
struct at<I, Head, Tail...> {
    using type = typename ::gdv::mp::at<I - 1, Tail...>::type;
};
template <typename Head, typename... Tail>
struct at<0, Head, Tail...> {
    using type = Head;
};
template <size_t I>
struct at<I>;
template <size_t I, template <typename...> typename Ty, typename... Elements>
struct at<I, Ty<Elements...> > {
    using type = typename ::gdv::mp::at<I, Elements...>::type;
};
template <template <typename...> typename Ty, typename ...Elements>
struct at<0, Ty<Elements...> > {
    using type = typename ::gdv::mp::at<0, Elements...>::type;
};
template <size_t I, typename... Ty>
using at_t = typename ::gdv::mp::at<I, Ty...>::type;

template <typename Ty0, typename... Ty1>
struct concat;
template <template <typename...> typename Ty, typename... Left, typename... Right>
struct concat <Ty<Left...>, Ty<Right...> > {
    using type = Ty<Left..., Right...>;
};
template <typename... Ty>
using concat_t = typename ::gdv::mp::concat<Ty...>::type;

template <typename... Ty>
struct push_back;
template <template <typename...> typename Container, typename Ty, typename... Elements>
struct push_back<Ty, Container<Elements...> > {
    using type = Container<Elements..., Ty>;
};
template <typename... Ty>
using push_back_t = typename ::gdv::mp::push_back<Ty...>::type;

template <typename... Ty>
struct push_front;
template <template <typename...> typename Container, typename Ty, typename... Elements>
struct push_front<Ty, Container<Elements...> > {
    using type = Container<Ty, Elements...>;
};
template <typename... Ty>
using push_front_t = typename ::gdv::mp::push_front<Ty...>::type;

template <template <typename> typename Pred, typename Ty, typename... Elements>
struct push_back_if;
template <template <typename> typename Pred,
    typename Ty, template <typename...> typename Container, typename... Elements>
struct push_back_if<Pred, Ty, Container<Elements...> >
    : public ::std::conditional<
        Pred<Ty>::value,
        Container<Elements..., Ty>,
        Container<Elements...>
    > {};
template <template <typename> typename Pred, typename Ty, typename... Elements>
using push_back_if_t = typename ::gdv::mp::push_back_if<Pred, Ty, Elements...>::type;

template <template <typename> typename Pred, typename Ty, typename... Elements>
struct push_front_if;
template <template <typename> typename Pred,
    typename Ty, template <typename...> typename Container, typename... Elements>
struct push_front_if<Pred, Ty, Container<Elements...> >
    : public ::std::conditional<
        Pred<Ty>::value,
        Container<Ty, Elements...>,
        Container<Elements...>
    > {};
template <template <typename> typename Pred, typename Ty, typename... Elements>
using push_front_if_t = typename ::gdv::mp::push_front_if<Pred, Ty, Elements...>::type;

template <typename... Ty>
struct reverse;
template <template <typename...> typename Ty, typename Head, typename... Tail>
struct reverse<Ty<Head, Tail...> > {
    using type = typename ::gdv::mp::push_back<
        Head, typename ::gdv::mp::reverse<Ty<Tail...> >::type
    >::type;
};
template <template <typename...> typename Ty, typename Head>
struct reverse<Ty<Head> > {
    using type = Ty<Head>;
};
template <template <typename...> typename Ty>
struct reverse<Ty<> > {
    using type = Ty<>;
};
template <typename... Ty>
using reverse_t = typename ::gdv::mp::reverse<Ty...>::type;

template <typename First, typename Last = typename First::next>
struct erase {
    using type = typename ::gdv::mp::concat<typename First::head, typename Last::tail>::type;
};
template <typename First, typename Last = typename First::next>
using erase_t = typename ::gdv::mp::erase<First, Last>::type;

} // namespace mp
} // namespace gdv

#endif
