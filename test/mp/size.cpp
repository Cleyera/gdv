#include <gdv/mp/test/test.h>

GDV_MP_TEST_CASE(size) {
    GDV_MP_TEST_EQ((size<>::value), (size_t)0);
    GDV_MP_TEST_EQ((size<char, int>::value), (size_t)2);
    GDV_MP_TEST_EQ((size<type_list<int, char, double> >::value), (size_t)3);
#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
    GDV_MP_TEST_EQ((size_v<>), (size_t)0);
    GDV_MP_TEST_EQ((size_v<char, int>), (size_t)2);
    GDV_MP_TEST_EQ((size_v<type_list<int, char, double> >), (size_t)3);
#endif // GDV_MP_ENABLE_VARIABLE_TEMPLATES
}
