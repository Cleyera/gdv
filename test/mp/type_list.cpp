#include <gdv/mp/test/test.h>

GDV_MP_TEST_CASE(type_list) {
    GDV_MP_TEST_IS_SAME(
        type_list<int, char, short>,
        type_list<int, char, short>::type);
}
