#include <gdv/mp/test/test.h>

GDV_MP_TEST_CASE(replace) {
    using l1 = type_list<int, char, short>;
    using l2 = type_list<short, char, short>;
    GDV_MP_TEST_IS_SAME(replace_t<begin_t<l1>, end_t<l1>, int, short>, l2);
    GDV_MP_TEST_IS_SAME(replace_t<begin_t<l1>, end_t<l1>::prev, int, short>, l2);
    GDV_MP_TEST_IS_SAME(replace_t<begin_t<l1>::next, end_t<l1>, int, short>, l1);
}
