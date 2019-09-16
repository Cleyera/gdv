#include <gdv/mp/test/test.h>

GDV_MP_TEST_CASE(for_each_n) {
    using l1 = type_list<int, char, short>;
    using l2 = type_list<int*, char*, short*>;
    using l3 = type_list<int, char*, short*>;
    GDV_MP_TEST_IS_SAME(for_each_n_t<begin_t<l1>, 3, std::add_pointer>, l2);
    GDV_MP_TEST_IS_SAME(for_each_n_t<begin_t<l2>, 3, std::remove_pointer>, l1);
    GDV_MP_TEST_IS_SAME(for_each_n_t<begin_t<l1>::next, 2, std::add_pointer>, l3);
}
