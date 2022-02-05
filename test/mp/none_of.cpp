#include <tuple>
#include <type_traits>
#include <gdv/mp/test/test.h>

template <typename Ty>
struct is_int : public ::std::is_same<Ty, int> {
};

template <typename ...Args>
struct packer;

GDV_MP_TEST_CASE(any_of) {
    using l1 = ::std::tuple<char, short, long long>;
    using l2 = ::std::tuple<int, char, short>;
    using l3 = packer<char, short, long long>;
    using l4 = packer<int, char, short>;
    GDV_MP_TEST((none_of<l1, is_int>::value));
    GDV_MP_TEST_NOT((none_of<l2, is_int>::value));
    GDV_MP_TEST((none_of<l3, is_int>::value));
    GDV_MP_TEST_NOT((none_of<l4, is_int>::value));
#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
    GDV_MP_TEST((none_of_v<l1, is_int>));
    GDV_MP_TEST_NOT((none_of_v<l2, is_int>));
    GDV_MP_TEST((none_of_v<l3, is_int>));
    GDV_MP_TEST_NOT((none_of_v<l4, is_int>));
#endif /*GDV_MP_ENABLE_VARIABLE_TEMPLATES*/
}
