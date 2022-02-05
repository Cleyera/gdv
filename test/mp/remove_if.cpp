#include <tuple>
#include <gdv/mp/test/test.h>

template <typename Ty>
struct is_int : public ::std::is_same<Ty, int> {
};

template <typename ...Args>
struct packer;

GDV_MP_TEST_CASE(replace_if) {
    using l1 = ::std::tuple<int, char, short>;
    using l2 = ::std::tuple<char, short, unsigned>;
    using l3 = ::std::tuple<int, int, int>;
    using l4 = ::std::tuple<>;
    using l5 = packer<int, char, short>;
    using l6 = packer<char, short, unsigned>;
    using l7 = packer<int, int, int>;
    using l8 = packer<>;
    GDV_MP_TEST_IS_SAME(remove_if_t<l1, is_int>, ::std::tuple<char, short>);
    GDV_MP_TEST_IS_SAME(remove_if_t<l2, is_int>, ::std::tuple<char, short, unsigned>);
    GDV_MP_TEST_IS_SAME(remove_if_t<l3, is_int>, ::std::tuple<>);
    GDV_MP_TEST_IS_SAME(remove_if_t<l4, is_int>, ::std::tuple<>);
    GDV_MP_TEST_IS_SAME(remove_if_t<l5, is_int>, packer<char, short>);
    GDV_MP_TEST_IS_SAME(remove_if_t<l6, is_int>, packer<char, short, unsigned>);
    GDV_MP_TEST_IS_SAME(remove_if_t<l7, is_int>, packer<>);
    GDV_MP_TEST_IS_SAME(remove_if_t<l8, is_int>, packer<>);
}
