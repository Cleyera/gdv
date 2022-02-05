#include <gdv/mp/test/test.h>

GDV_MP_TEST_CASE(concat) {
    GDV_MP_TEST_IS_SAME(
        concat<
            ::std::tuple<int, char>,
            ::std::tuple<short>
        >::type,
        ::std::tuple<int, char, short>
    );
    GDV_MP_TEST_IS_SAME(
        concat<
            ::std::tuple<>,
            ::std::tuple<short>
        >::type,
        ::std::tuple<short>
    );
    GDV_MP_TEST_IS_SAME(
        concat<
            ::std::tuple<>,
            ::std::tuple<>
        >::type,
        ::std::tuple<>
    );
    GDV_MP_TEST_IS_SAME(
        concat_t<
            ::std::tuple<int, char>,
            ::std::tuple<short>
        >,
        ::std::tuple<int, char, short>
    );
    GDV_MP_TEST_IS_SAME(
        concat_t<
            ::std::tuple<>,
            ::std::tuple<short>
        >,
        ::std::tuple<short>
    );
    GDV_MP_TEST_IS_SAME(
        concat_t<
            ::std::tuple<int, char>,
            ::std::tuple<>
        >,
        ::std::tuple<int, char>
    );
    GDV_MP_TEST_IS_SAME(
        concat_t<
            ::std::tuple<>,
            ::std::tuple<>
        >,
        ::std::tuple<>
    );
}
