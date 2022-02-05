#include <gdv/mp/test/test.h>

GDV_MP_TEST_CASE(count) {
    using l1 = ::std::tuple<int, char, short>;
    using l2 = ::std::tuple<int, int, int>;
    using l3 = ::std::tuple<>;
    GDV_MP_TEST_EQ((count<l1, int>::value), (size_t)1);
    GDV_MP_TEST_EQ((count<l2, int>::value), (size_t)3);
    GDV_MP_TEST_EQ((count<l3, int>::value), (size_t)0);
#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
    GDV_MP_TEST_EQ((count_v<l1, int>), (size_t)1);
    GDV_MP_TEST_EQ((count_v<l2, int>), (size_t)3);
    GDV_MP_TEST_EQ((count_v<l3, int>), (size_t)0);
#endif // GDV_MP_ENABLE_VARIABLE_TEMPLATES
}
