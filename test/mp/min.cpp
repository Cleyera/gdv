#include <gdv/mp/test/test.h>

struct size_test1 {
    char c[1];
};

struct size_test2 {
    char c[2];
};

struct size_test3 {
    char c[3];
};

GDV_MP_TEST_CASE(min) {
    GDV_MP_TEST_EQ((min<size_test1, size_test2, size_test3>::value), sizeof(size_test1));
    GDV_MP_TEST_EQ((min<type_list<size_test1, size_test2, size_test3> >::value), sizeof(size_test1));
#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
    GDV_MP_TEST_EQ((min_v<size_test1, size_test2, size_test3>), sizeof(size_test1));
    GDV_MP_TEST_EQ((min_v<type_list<size_test1, size_test2, size_test3> >), sizeof(size_test1));
#endif // GDV_MP_ENABLE_VARIABLE_TEMPLATES
}
