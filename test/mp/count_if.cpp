#include <tuple>
#include <gdv/mp/test/test.h>

template <typename Ty>
struct is_int : public ::std::is_same<Ty, int> {
};

GDV_MP_TEST_CASE(count_if) {
    using l1 = ::std::tuple<int, char, short>;
    using l2 = ::std::tuple<int, int, int>;
    using l3 = ::std::tuple<char, short, long long>;
    using l4 = ::std::tuple<>;
    GDV_MP_TEST_EQ((count_if<l1, is_int>::value), (size_t)1);
    GDV_MP_TEST_EQ((count_if<l2, is_int>::value), (size_t)3);
    GDV_MP_TEST_EQ((count_if<l3, is_int>::value), (size_t)0);
    GDV_MP_TEST_EQ((count_if<l4, is_int>::value), (size_t)0);
#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
    GDV_MP_TEST_EQ((count_if_v<l1, is_int>), (size_t)1);
    GDV_MP_TEST_EQ((count_if_v<l2, is_int>), (size_t)3);
    GDV_MP_TEST_EQ((count_if_v<l3, is_int>), (size_t)0);
    GDV_MP_TEST_EQ((count_if_v<l4, is_int>), (size_t)0);
#endif // GDV_MP_ENABLE_VARIABLE_TEMPLATES
}
