#include <gdv/mp/test/test.h>

GDV_MP_TEST_CASE(at) {
    GDV_MP_TEST((std::is_same<at<0, int, char, short>::type, int>::value));
    GDV_MP_TEST((std::is_same<at<1, int, char, short>::type, char>::value));
    GDV_MP_TEST((std::is_same<at<0, type_list<int, char, short> >::type, int>::value));
    GDV_MP_TEST((std::is_same<at<1, type_list<int, char, short> >::type, char>::value));
    GDV_MP_TEST((std::is_same<at_t<0, int, char, short>, int>::value));
    GDV_MP_TEST((std::is_same<at_t<1, int, char, short>, char>::value));
    GDV_MP_TEST((std::is_same<at_t<0, type_list<int, char, short> >, int>::value));
    GDV_MP_TEST((std::is_same<at_t<1, type_list<int, char, short> >, char>::value));
}
