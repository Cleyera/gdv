#include <gdv/mp/test/test.h>

template <typename Ty>
struct is_int {
    static constexpr bool value = ::std::is_same<Ty, int>::value;
};

GDV_MP_TEST_CASE(replace_if) {
    using l1 = type_list<int, char, short>;
    using l2 = type_list<char, short>;
    GDV_MP_TEST_IS_SAME(remove_if_t<begin_t<l1>, end_t<l1>, is_int>, l2);
    GDV_MP_TEST_IS_SAME(remove_if_t<begin_t<l1>, end_t<l1>::prev, is_int>, l2);
    GDV_MP_TEST_IS_SAME(remove_if_t<begin_t<l1>::next, end_t<l1>, is_int>, l1);
}
