#include <tuple>
#include <gdv/mp/test/test.h>

template <typename ...Args>
struct packer;

GDV_MP_TEST_CASE(replace) {
    using l1 = ::std::tuple<int, char, short>;
    using l2 = ::std::tuple<int, int, int>;
    using l3 = ::std::tuple<>;
    using l4 = packer<int, char, short>;
    using l5 = packer<int, int, int>;
    using l6 = packer<>;
    GDV_MP_TEST_IS_SAME(replace_t<l1, int, short>, ::std::tuple<short, char, short>);
    GDV_MP_TEST_IS_SAME(replace_t<l2, int, short>, ::std::tuple<short, short, short>);
    GDV_MP_TEST_IS_SAME(replace_t<l3, int, short>, ::std::tuple<>);
    GDV_MP_TEST_IS_SAME(replace_t<l4, int, short>, packer<short, char, short>);
    GDV_MP_TEST_IS_SAME(replace_t<l5, int, short>, packer<short, short, short>);
    GDV_MP_TEST_IS_SAME(replace_t<l6, int, short>, packer<>);
}
