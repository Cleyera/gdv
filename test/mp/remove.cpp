#include <tuple>
#include <gdv/mp/test/test.h>

template <typename ...Args>
struct packer;

GDV_MP_TEST_CASE(remove) {
    using l1 = ::std::tuple<int, char, short>;
    using l2 = ::std::tuple<char, short, unsigned>;
    using l3 = ::std::tuple<int, int, int>;
    using l4 = ::std::tuple<>;
    using l5 = packer<int, char, short>;
    using l6 = packer<char, short, unsigned>;
    using l7 = packer<int, int, int>;
    using l8 = packer<>;
    GDV_MP_TEST_IS_SAME(remove_t<l1, int>, ::std::tuple<char, short>);
    GDV_MP_TEST_IS_SAME(remove_t<l2, int>, ::std::tuple<char, short, unsigned>);
    GDV_MP_TEST_IS_SAME(remove_t<l3, int>, ::std::tuple<>);
    GDV_MP_TEST_IS_SAME(remove_t<l4, int>, ::std::tuple<>);
    GDV_MP_TEST_IS_SAME(remove_t<l5, int>, packer<char, short>);
    GDV_MP_TEST_IS_SAME(remove_t<l6, int>, packer<char, short, unsigned>);
    GDV_MP_TEST_IS_SAME(remove_t<l7, int>, packer<>);
    GDV_MP_TEST_IS_SAME(remove_t<l8, int>, packer<>);
}
