#include <gdv/mp/test/test.h>

GDV_MP_TEST_CASE(push_back) {
    GDV_MP_TEST_IS_SAME(
        push_back<
            int,
            type_list<short>
        >::type,
        type_list<short, int>);
    GDV_MP_TEST_IS_SAME(
        push_back<
            int,
            type_list<>
        >::type,
        type_list<int>);
    GDV_MP_TEST_IS_SAME(
        push_back_t<
            int,
            type_list<short> >,
        type_list<short, int>);
    GDV_MP_TEST_IS_SAME(
        push_back_t<
            int,
            type_list<> >,
        type_list<int>);
}
