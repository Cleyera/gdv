#include <gdv/mp/test/test.h>

GDV_MP_TEST_CASE(tail) {
    GDV_MP_TEST((std::is_same<tail<type_list<int, char, short> >::type, type_list<char, short> >::value));
    GDV_MP_TEST((std::is_same<tail_t<type_list<int, char, short> >, type_list<char, short> >::value));
}
