#include <tuple>
#include <gdv/mp/test/test.h>

template <typename Ty>
struct is_int : public ::std::is_same<Ty, int> {
};

template <typename ...Args>
struct packer;

GDV_MP_TEST_CASE(push_back_if) {
    GDV_MP_TEST_IS_SAME(
        push_back_if<
            ::std::tuple<short>,
            int,
            is_int
        >::type,
        ::std::tuple<short, int>
    );
    GDV_MP_TEST_IS_SAME(
        push_back_if<
            ::std::tuple<short>,
            char,
            is_int
        >::type,
        ::std::tuple<short>
    );
    GDV_MP_TEST_IS_SAME(
        push_back_if_t<
            ::std::tuple<short>,
            int,
            is_int
        >,
        ::std::tuple<short, int>
    );
    GDV_MP_TEST_IS_SAME(
        push_back_if_t<
            ::std::tuple<short>,
            char,
            is_int
        >,
        ::std::tuple<short>
    );

    GDV_MP_TEST_IS_SAME(
        push_back_if<
            packer<short>,
            int,
            is_int
        >::type,
        packer<short, int>
    );
    GDV_MP_TEST_IS_SAME(
        push_back_if<
            packer<short>,
            char,
            is_int
        >::type,
        packer<short>
    );
    GDV_MP_TEST_IS_SAME(
        push_back_if_t<
            packer<short>,
            int,
            is_int
        >,
        packer<short, int>
    );
    GDV_MP_TEST_IS_SAME(
        push_back_if_t<
            packer<short>,
            char,
            is_int
        >,
        packer<short>
    );
}
