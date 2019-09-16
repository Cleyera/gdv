#include <gdv/mp/test/test.h>

GDV_MP_TEST_CASE(distance) {
    using l = type_list<int, char, short>;
    using b = begin_t<l>;
    using e = end_t<l>;
    GDV_MP_TEST_EQ((distance<b, e>::value), 3);
    GDV_MP_TEST_EQ((distance<b::next::next, e::prev>::value), 0);
#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
    GDV_MP_TEST_EQ((distance_v<b, e>), 3);
    GDV_MP_TEST_EQ((distance_v<b::next::next, e::prev>), 0);
#endif /*GDV_MP_ENABLE_VARIABLE_TEMPLATES*/
}
