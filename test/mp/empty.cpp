#include <gdv/mp/test/test.h>

GDV_MP_TEST_CASE(empty) {
    GDV_MP_TEST((empty<>::value));
    GDV_MP_TEST_NOT((empty<int>::value));
    GDV_MP_TEST((empty<type_list<> >::value));
    GDV_MP_TEST_NOT((empty<type_list<int> >::value));
#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
    GDV_MP_TEST((empty_v<>));
    GDV_MP_TEST_NOT((empty_v<int>));
    GDV_MP_TEST((empty_v<type_list<> >));
    GDV_MP_TEST_NOT((empty_v<type_list<int> >));
#endif // GDV_MP_ENABLE_VARIABLE_TEMPLATES
}
