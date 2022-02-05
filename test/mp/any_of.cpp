#include <tuple>
#include <type_traits>
#include <gdv/mp/test/test.h>

template <typename Ty>
struct is_int : public ::std::is_same<Ty, int> {
};

template <typename ...Args>
struct packer;

GDV_MP_TEST_CASE(any_of) {
    using l1 = ::std::tuple<int, char, short>;
    using l2 = ::std::tuple<char, short, long long>;
    using l3 = packer<int, char, short>;
    using l4 = packer<char, short, long long>;
    GDV_MP_TEST((any_of<l1, is_int>::value));
    GDV_MP_TEST_NOT((any_of<l2, is_int>::value));
    GDV_MP_TEST((any_of<l3, is_int>::value));
    GDV_MP_TEST_NOT((any_of<l4, is_int>::value));
#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
    GDV_MP_TEST((any_of_v<l1, is_int>));
    GDV_MP_TEST_NOT((any_of_v<l2, is_int>));
    GDV_MP_TEST((any_of_v<l3, is_int>));
    GDV_MP_TEST_NOT((any_of_v<l4, is_int>));
#endif /*GDV_MP_ENABLE_VARIABLE_TEMPLATES*/
}
