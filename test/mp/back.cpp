#include <gdv/mp/test/test.h>

GDV_MP_TEST_CASE(back) {
    GDV_MP_TEST((std::is_same<back<int, char, short>::type, short>::value));
    GDV_MP_TEST((std::is_same<back<type_list<int, char, short> >::type, short>::value));
    GDV_MP_TEST((std::is_same<back_t<int, char, short>, short>::value));
    GDV_MP_TEST((std::is_same<back_t<type_list<int, char, short> >, short>::value));
}
