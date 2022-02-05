#include <tuple>
#include <gdv/mp/test/test.h>

template <typename ...Args>
struct packer;

GDV_MP_TEST_CASE(push_back) {
    GDV_MP_TEST_IS_SAME(
        push_back<
            ::std::tuple<short>,
            int
        >::type,
        ::std::tuple<short, int>
    );
    GDV_MP_TEST_IS_SAME(
        push_back<
            ::std::tuple<>,
            int
        >::type,
        ::std::tuple<int>
    );
    GDV_MP_TEST_IS_SAME(
        push_back_t<
            ::std::tuple<short>,
            int
        >,
        ::std::tuple<short, int>
    );
    GDV_MP_TEST_IS_SAME(
        push_back_t<
            ::std::tuple<>,
            int
        >,
        ::std::tuple<int>
    );

    GDV_MP_TEST_IS_SAME(
        push_back<
            packer<short>,
            int
        >::type,
        packer<short, int>
    );
    GDV_MP_TEST_IS_SAME(
        push_back<
            packer<>,
            int
        >::type,
        packer<int>
    );
    GDV_MP_TEST_IS_SAME(
        push_back_t<
            packer<short>,
            int
        >,
        packer<short, int>
    );
    GDV_MP_TEST_IS_SAME(
        push_back_t<
            packer<>,
            int
        >,
        packer<int>
    );
}
