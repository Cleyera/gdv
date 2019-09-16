#include <gdv/mp/test/test.h>

GDV_MP_TEST_CASE(equal) {
    using l1 = type_list<int, char, short>;
    using l2 = type_list<int, char, short>;
    using l3 = type_list<int, char, long>;
    using l4 = type_list<int, char, short, bool>;
    GDV_MP_TEST((equal<begin_t<l1>, end_t<l1>, begin_t<l2>, end_t<l2> >::value));
    GDV_MP_TEST_NOT((equal<begin_t<l1>, end_t<l1>, begin_t<l3>, end_t<l3> >::value));
    GDV_MP_TEST_NOT((equal<begin_t<l1>, end_t<l1>, begin_t<l4>, end_t<l4> >::value));
    GDV_MP_TEST((equal<begin_t<l1>, end_t<l1>, begin_t<l4>, end_t<l4>::prev>::value));
#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
    GDV_MP_TEST((equal_v<begin_t<l1>, end_t<l1>, begin_t<l2>, end_t<l2> >));
    GDV_MP_TEST_NOT((equal_v<begin_t<l1>, end_t<l1>, begin_t<l3>, end_t<l3> >));
    GDV_MP_TEST_NOT((equal_v<begin_t<l1>, end_t<l1>, begin_t<l4>, end_t<l4> >));
    GDV_MP_TEST((equal_v<begin_t<l1>, end_t<l1>, begin_t<l4>, end_t<l4>::prev>));
#endif // GDV_MP_ENABLE_VARIABLE_TEMPLATES
}
