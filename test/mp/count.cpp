#include <gdv/mp/test/test.h>

GDV_MP_TEST_CASE(count) {
    using l1 = type_list<int, char, short>;
    using l2 = type_list<int, int, int>;
    GDV_MP_TEST_EQ((count<begin_t<l1>, end_t<l1>, int>::value), (size_t)1);
    GDV_MP_TEST_EQ((count<begin_t<l2>, end_t<l2>, int>::value), (size_t)3);
#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
    GDV_MP_TEST_EQ((count_v<begin_t<l1>, end_t<l1>, int>), (size_t)1);
    GDV_MP_TEST_EQ((count_v<begin_t<l2>, end_t<l2>, int>), (size_t)3);
#endif // GDV_MP_ENABLE_VARIABLE_TEMPLATES
}
