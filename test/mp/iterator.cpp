#include <gdv/mp/test/test.h>

GDV_MP_TEST_CASE(begin_end) {
    using b = begin_t<type_list<int, char, short> >;
    using e = end_t<type_list<int, char, short> >;
    GDV_MP_TEST_IS_SAME(b::type, int);
    GDV_MP_TEST_IS_SAME(b::next::type, char);
    GDV_MP_TEST_IS_SAME(b::next::next::type, short);
    GDV_MP_TEST_IS_SAME(b::next::next::prev::type, char);
    GDV_MP_TEST_IS_SAME(b::next::next::next, e);
    GDV_MP_TEST_IS_SAME(e::prev::type, short);
    GDV_MP_TEST_IS_SAME(e::prev::prev::type, char);
    GDV_MP_TEST_IS_SAME(e::prev::prev::prev::type, int);
    GDV_MP_TEST_IS_SAME(b::next::next, e::prev);
}

GDV_MP_TEST_CASE(next) {
    using b = begin_t<type_list<int, char, short> >;
    using e = end_t<type_list<int, char, short> >;
    GDV_MP_TEST_IS_SAME(b::next, next_t<b>);
    GDV_MP_TEST_IS_SAME(b::next::next, next_t<next_t<b> >);
    GDV_MP_TEST_IS_SAME(b::next::next, next_t<b, 2>);
    GDV_MP_TEST_IS_SAME(b::next::next::next, next_t<b, 3>);
    GDV_MP_TEST_IS_SAME(e, next_t<b, 3>);
}

GDV_MP_TEST_CASE(prev) {
    using b = begin_t<type_list<int, char, short> >;
    using e = end_t<type_list<int, char, short> >;
    GDV_MP_TEST_IS_SAME(e::prev, prev_t<e>);
    GDV_MP_TEST_IS_SAME(e::prev::prev, prev_t<prev_t<e> >);
    GDV_MP_TEST_IS_SAME(e::prev::prev, prev_t<e, 2>);
    GDV_MP_TEST_IS_SAME(e::prev::prev::prev, prev_t<e, 3>);
    GDV_MP_TEST_IS_SAME(b, prev_t<e, 3>);
}
