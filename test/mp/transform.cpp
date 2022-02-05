#include <gdv/mp/test/test.h>
// 
// GDV_MP_TEST_CASE(for_each) {
//     using l1 = type_list<int, char, short>;
//     using l2 = type_list<int*, char*, short*>;
//     using l3 = type_list<char*, short*>;
//     GDV_MP_TEST_IS_SAME(transform_t<begin_t<l1>, end_t<l1>, std::add_pointer>, l2);
//     GDV_MP_TEST_IS_SAME(transform_t<begin_t<l2>, end_t<l2>, std::remove_pointer>, l1);
//     GDV_MP_TEST_IS_SAME(transform_t<begin_t<l1>::next, end_t<l1>, std::add_pointer>, l3);
// }
