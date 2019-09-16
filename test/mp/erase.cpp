#include <gdv/mp/test/test.h>

GDV_MP_TEST_CASE(erase) {
    using l1 = type_list<int, char, short>;
    using l2 = type_list<char, short>;
    using l3 = type_list<short>;
    GDV_MP_TEST_IS_SAME(erase_t<begin_t<l1> >, l2);
    GDV_MP_TEST_IS_SAME(erase_t<begin_t<l1>, end_t<l1>::prev >, l3);
}
