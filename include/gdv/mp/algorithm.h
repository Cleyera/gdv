#ifndef GDV_MP_ALGORITHM_H_
#define GDV_MP_ALGORITHM_H_

#include <type_traits>

namespace gdv {
namespace mp {

namespace detail {

template <typename First, typename Last, typename Container>
struct restore_container {
    using type = typename ::gdv::mp::concat<
        typename ::gdv::mp::concat<typename First::head, Container>::type,
        typename Last::tail>::type;
};

template <template <typename...> typename Dst, typename Src>
struct receive;
template <template <typename...> typename Dst,
    template <typename...> typename Src, typename... Elements>
struct receive<Dst, Src<Elements...> > {
    using type = Dst<Elements...>;
};

} // namespace detail

template <typename First, typename Last, template <typename> typename Pred>
struct  all_of : public ::std::conditional<
    Pred<typename First::type>::value,
    ::gdv::mp::all_of<typename First::next, Last, Pred>,
    ::std::false_type>::type {
};
template <typename Iterator, template <typename> typename Pred>
struct all_of<Iterator, Iterator, Pred>  : public ::std::true_type {
};
#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
template <typename First, typename Last, template <typename> typename Pred>
static constexpr bool all_of_v = ::gdv::mp::all_of<First, Last, Pred>::value;
#endif /*GDV_MP_ENABLE_VARIABLE_TEMPLATES*/

template <typename First, typename Last, template <typename> typename Pred>
struct any_of : public ::std::conditional<
    Pred<typename First::type>::value,
    ::std::true_type,
    ::gdv::mp::any_of<typename First::next, Last, Pred> >::type {
};
template <typename Iterator, template <typename> typename Pred>
struct any_of<Iterator, Iterator, Pred> : public ::std::false_type {
};
#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
template <typename First, typename Last, template <typename> typename Pred>
static constexpr bool any_of_v = ::gdv::mp::any_of<First, Last, Pred>::value;
#endif /*GDV_MP_ENABLE_VARIABLE_TEMPLATES*/

template <typename First, typename Last, template <typename> typename Pred>
struct none_of : public ::std::conditional<
    Pred<typename First::type>::value,
    ::std::false_type,
    ::gdv::mp::none_of<typename First::next, Last, Pred> >::type {
};
template <typename Iterator, template <typename> typename Pred>
struct none_of<Iterator, Iterator, Pred> : public ::std::true_type {
};
#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
template <typename First, typename Last, template <typename> typename Pred>
static constexpr bool none_of_v = ::gdv::mp::none_of<First, Last, Pred>::value;
#endif /*GDV_MP_ENABLE_VARIABLE_TEMPLATES*/

template <typename First, typename Last, template <typename> typename Pred>
struct for_each_impl {
    using type = typename ::gdv::mp::push_front<
        typename Pred<typename First::type>::type,
        typename ::gdv::mp::for_each_impl<typename First::next, Last, Pred>::type>::type;
};
template <typename Iterator, template <typename> typename Pred>
struct for_each_impl<Iterator, Iterator, Pred> {
    using type = typename Iterator::template container_type<>;
};
template <typename First, typename Last, template <typename> typename Pred>
struct for_each {
    using type = typename ::gdv::mp::detail::restore_container<
        First, Last, typename ::gdv::mp::for_each_impl<First, Last, Pred>::type>::type;
};
template <typename First, typename Last, template <typename> typename Pred>
using for_each_t = typename ::gdv::mp::for_each<First, Last, Pred>::type;

template <typename First, size_t N, template <typename> typename Pred>
struct for_each_n {
    using type = typename ::gdv::mp::for_each<First, typename ::gdv::mp::next<First, N>::type, Pred>::type;
};
template <typename First, size_t N, template <typename> typename Pred>
using for_each_n_t = typename ::gdv::mp::for_each_n<First, N, Pred>::type;

template <typename First, typename Last, typename Ty>
struct find : public ::std::conditional<
    ::std::is_same<typename First::type, Ty>::value, First,
    typename ::gdv::mp::find<typename First::next, Last, Ty>::type> {
};
template <typename Iterator, typename Ty>
struct find <Iterator, Iterator, Ty> {
    using type = Iterator;
};
template <typename First, typename Last, typename Ty>
using find_t = typename ::gdv::mp::find<First, Last, Ty>::type;

template <typename First, typename Last, template <typename> typename Pred>
struct find_if : public ::std::conditional<
    Pred<typename First::type>::value, First,
    typename ::gdv::mp::find_if<typename First::next, Last, Pred>::type> {
};
template <typename Iterator, template <typename> typename Pred>
struct find_if <Iterator, Iterator, Pred> {
    using type = Iterator;
};
template <typename First, typename Last, template <typename> typename Pred>
using find_if_t = typename ::gdv::mp::find_if<First, Last, Pred>::type;

template <typename First, typename Last, template <typename> typename Pred>
struct find_if_not : public ::std::conditional<
    !Pred<typename First::type>::value, First,
    typename ::gdv::mp::find_if_not<typename First::next, Last, Pred>::type> {
};
template <typename Iterator, template <typename> typename Pred>
struct find_if_not <Iterator, Iterator, Pred> {
    using type = Iterator;
};
template <typename First, typename Last, template <typename> typename Pred>
using find_if_not_t = typename ::gdv::mp::find_if_not<First, Last, Pred>::type;

template <typename First, typename Last, typename Ty>
struct count {
    static constexpr size_t value = ::gdv::mp::count<typename First::next, Last, Ty>::value
        + (::std::is_same<typename First::type, Ty>::value ? 1 : 0);
};
template <typename Iterator, typename Ty>
struct count<Iterator, Iterator, Ty> {
    static constexpr size_t value = 0;
};
#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
template <typename First, typename Last, typename Ty>
static constexpr size_t count_v = ::gdv::mp::count<First, Last, Ty>::value;
#endif /*GDV_MP_ENABLE_VARIABLE_TEMPLATES*/

template <typename First, typename Last, template <typename> typename Pred>
struct count_if {
    static constexpr size_t value = ::gdv::mp::count_if<typename First::next, Last, Pred>::value
        + (Pred<typename First::type>::value ? 1 : 0);
};
template <typename Iterator, template <typename> typename Pred>
struct count_if<Iterator, Iterator, Pred> {
    static constexpr size_t value = 0;
};
#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
template <typename First, typename Last, template <typename> typename Pred>
static constexpr size_t count_if_v = ::gdv::mp::count_if<First, Last, Pred>::value;
#endif /*GDV_MP_ENABLE_VARIABLE_TEMPLATES*/

template <typename First, typename Last, template <typename> typename Pred>
struct transform {
    using type = typename ::gdv::mp::for_each_impl<First, Last, Pred>::type;
};
template <typename First, typename Last, template <typename> typename Pred>
using transform_t = typename ::gdv::mp::transform<First, Last, Pred>::type;

template <typename First1, typename Last1, typename First2, typename Last2,
    template <typename, typename> typename Pred = ::std::is_same>
struct equal : public ::std::conditional<
    ::std::is_same<typename First1::type, typename First2::type>::value,
    ::gdv::mp::equal<typename First1::next, Last1, typename First2::next, Last2>,
    ::std::false_type>::type {
};
template <typename Iterator, typename First, typename Last, template <typename, typename> typename Pred>
struct equal<Iterator, Iterator, First, Last, Pred> : public ::std::false_type {
};
template <typename First, typename Last, typename Iterator, template <typename, typename> typename Pred>
struct equal<First, Last, Iterator, Iterator, Pred> : public ::std::false_type {
};
template <typename Iterator1, typename Iterator2, template <typename, typename> typename Pred>
struct equal<Iterator1, Iterator1, Iterator2, Iterator2, Pred> : public ::std::true_type {
};
#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
template <typename First1, typename Last1, typename First2, typename Last2,
    template <typename, typename> typename Pred = ::std::is_same>
static constexpr bool equal_v = ::gdv::mp::equal<First1, Last1, First2, Last2, Pred>::value;
#endif /*GDV_MP_ENABLE_VARIABLE_TEMPLATES*/

template <typename First, typename Last, typename Old, typename New>
struct replace_impl {
    using type = typename ::gdv::mp::push_front<
        typename ::std::conditional<
            ::std::is_same<Old, typename First::type>::value, New, typename First::type>::type,
        typename ::gdv::mp::replace_impl<typename First::next, Last, Old, New>::type
    >::type;
};
template <typename Iterator, typename Old, typename New>
struct replace_impl<Iterator, Iterator, Old, New> {
    using type = typename Iterator::template container_type<>;
};
template <typename First, typename Last, typename Old, typename New>
struct replace {
    using type = typename ::gdv::mp::detail::restore_container<
        First, Last, typename ::gdv::mp::replace_impl<First, Last, Old, New>::type>::type;
};
template <typename First, typename Last, typename Old, typename New>
using replace_t = typename ::gdv::mp::replace<First, Last, Old, New>::type;

template <typename First, typename Last, template <typename> typename Pred, typename New>
struct replace_if_impl {
    using type = typename ::gdv::mp::push_front<
        typename ::std::conditional<Pred<typename First::type>::value, New, typename First::type>::type,
        typename ::gdv::mp::replace_if_impl<typename First::next, Last, Pred, New>::type>::type;
};
template <typename Iterator, template <typename> typename Pred, typename New>
struct replace_if_impl<Iterator, Iterator, Pred, New> {
    using type = typename Iterator::template container_type<>;
};
template <typename First, typename Last, template <typename> typename Pred, typename New>
struct replace_if {
    using type = typename ::gdv::mp::detail::restore_container<
        First, Last, typename ::gdv::mp::replace_if_impl<First, Last, Pred, New>::type>::type;
};
template <typename First, typename Last, template <typename> typename Pred, typename New>
using replace_if_t = typename ::gdv::mp::replace_if<First, Last, Pred, New>::type;

template <typename First, typename Last, typename Ty>
struct remove_impl {
    using type = typename ::std::conditional<
        ::std::is_same<typename First::type, Ty>::value,
        typename ::gdv::mp::remove_impl<typename First::next, Last, Ty>::type,
        typename ::gdv::mp::push_front<typename First::type,
            typename ::gdv::mp::remove_impl<typename First::next, Last, Ty>::type>::type
    >::type;
};
template <typename Iterator, typename Ty>
struct remove_impl<Iterator, Iterator, Ty> {
    using type = typename Iterator::template container_type<>;
};
template <typename First, typename Last, typename Ty>
struct remove {
    using type = typename ::gdv::mp::detail::restore_container<
        First, Last, typename ::gdv::mp::remove_impl<First, Last, Ty>::type>::type;
};
template <typename First, typename Last, typename Ty>
using remove_t = typename ::gdv::mp::remove<First, Last, Ty>::type;

template <typename First, typename Last, template <typename> typename Pred>
struct remove_if_impl {
    using type = typename ::std::conditional<
        Pred<typename First::type>::value,
        typename ::gdv::mp::remove_if_impl<typename First::next, Last, Pred>::type,
        typename ::gdv::mp::push_front<typename First::type,
            typename ::gdv::mp::remove_if_impl<typename First::next, Last, Pred>::type>::type
    >::type;
};
template <typename Iterator, template <typename> typename Pred>
struct remove_if_impl<Iterator, Iterator, Pred> {
    using type = typename Iterator::template container_type<>;
};
template <typename First, typename Last, template <typename> typename Pred>
struct remove_if {
    using type = typename ::gdv::mp::detail::restore_container<
        First, Last, typename ::gdv::mp::remove_if_impl<First, Last, Pred>::type>::type;
};
template <typename First, typename Last, template <typename> typename Pred>
using remove_if_t = typename ::gdv::mp::remove_if<First, Last, Pred>::type;

} // namespace mp
} // namespace gdv

#endif
