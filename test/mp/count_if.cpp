#include <gdv/mp/test/test.h>

template <typename Ty>
struct is_int {
    static constexpr bool value = std::is_same<int, Ty>::value;
};

GDV_MP_TEST_CASE(count_if) {
    using l1 = type_list<int, char, short>;
    using l2 = type_list<int, int, int>;
    GDV_MP_TEST_EQ((count_if<begin_t<l1>, end_t<l1>, is_int>::value), (size_t)1);
    GDV_MP_TEST_EQ((count_if<begin_t<l2>, end_t<l2>, is_int>::value), (size_t)3);
#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
    GDV_MP_TEST_EQ((count_if_v<begin_t<l1>, end_t<l1>, is_int>), (size_t)1);
    GDV_MP_TEST_EQ((count_if_v<begin_t<l2>, end_t<l2>, is_int>), (size_t)3);
#endif // GDV_MP_ENABLE_VARIABLE_TEMPLATES
}
