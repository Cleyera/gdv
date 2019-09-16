#include <gdv/mp/test/test.h>

GDV_MP_TEST_CASE(remove) {
    using l1 = type_list<int, char, short>;
    using l2 = type_list<char, short>;
    GDV_MP_TEST_IS_SAME(remove_t<begin_t<l1>, end_t<l1>, int>, l2);
    GDV_MP_TEST_IS_SAME(remove_t<begin_t<l1>, end_t<l1>::prev, int>, l2);
    GDV_MP_TEST_IS_SAME(remove_t<begin_t<l1>::next, end_t<l1>, int>, l1);
}
