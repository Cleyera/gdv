#include <gdv/mp/test/test.h>
// 
// template <typename Ty>
// struct is_int {
//     static constexpr bool value = ::std::is_same<int, Ty>::value;
// };
// 
// GDV_MP_TEST_CASE(find_if) {
//     using l1 = type_list<int, char, short>;
//     using l2 = type_list<long long, char, short>;
//     GDV_MP_TEST_IS_SAME(find_if_t<begin_t<l1>, end_t<l1>, is_int>, begin_t<l1>);
//     GDV_MP_TEST_IS_SAME(find_if_t<begin_t<l2>, end_t<l2>, is_int>, end_t<l2>);
// }
