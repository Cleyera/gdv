#include <tuple>
#include <gdv/mp/test/test.h>

GDV_MP_TEST_CASE(for_each) {
    using l1 = ::std::tuple<int, char, short>;
    using l2 = ::std::tuple<>;
    GDV_MP_TEST_IS_SAME(for_each_t<l1, std::add_pointer>, ::std::tuple<int*, char*, short*>);
    GDV_MP_TEST_IS_SAME(for_each_t<l2, std::remove_pointer>, ::std::tuple<>);
}
