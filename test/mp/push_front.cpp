#include <gdv/mp/test/test.h>

GDV_MP_TEST_CASE(push_front) {
    GDV_MP_TEST_IS_SAME(
        push_front<
            int,
            type_list<short>
        >::type,
        type_list<int, short>);
    GDV_MP_TEST_IS_SAME(
        push_front<
            int,
            type_list<>
        >::type,
        type_list<int>);
    GDV_MP_TEST_IS_SAME(
        push_front_t<
            int,
            type_list<short> >,
        type_list<int, short>);
    GDV_MP_TEST_IS_SAME(
        push_front_t<
            int,
            type_list<> >,
        type_list<int>);
}
