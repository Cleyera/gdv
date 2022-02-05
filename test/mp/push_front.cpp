#include <tuple>
#include <gdv/mp/test/test.h>

template <typename ...Args>
struct packer;

GDV_MP_TEST_CASE(push_front) {
    GDV_MP_TEST_IS_SAME(
        push_front<
            ::std::tuple<short>,
            int
        >::type,
        ::std::tuple<int, short>
    );
    GDV_MP_TEST_IS_SAME(
        push_front<
            ::std::tuple<>,
            int
        >::type,
        ::std::tuple<int>
    );
    GDV_MP_TEST_IS_SAME(
        push_front_t<
            ::std::tuple<short>,
            int
        >,
        ::std::tuple<int, short>
    );
    GDV_MP_TEST_IS_SAME(
        push_front_t<
            ::std::tuple<>,
            int
        >,
        ::std::tuple<int>
    );

    GDV_MP_TEST_IS_SAME(
        push_front<
            packer<short>,
            int
        >::type,
        packer<int, short>
    );
    GDV_MP_TEST_IS_SAME(
        push_front<
            packer<>,
            int
        >::type,
        packer<int>
    );
    GDV_MP_TEST_IS_SAME(
        push_front_t<
            packer<short>,
            int
        >,
        packer<int, short>
    );
    GDV_MP_TEST_IS_SAME(
        push_front_t<
            packer<>,
            int
        >,
        packer<int>
    );
}
