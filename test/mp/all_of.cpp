#include <gdv/mp/test/test.h>

template <typename Ty>
struct is_int {
    static constexpr bool value = ::std::is_same<Ty, int>::value;
};

GDV_MP_TEST_CASE(all_of) {
    using l1 = type_list<int, int, int>;
    using l2 = type_list<int, char, short>;
    GDV_MP_TEST((all_of<begin_t<l1>, end_t<l1>, is_int>::value));
    GDV_MP_TEST_NOT((all_of<begin_t<l2>, end_t<l2>, is_int>::value));
#ifdef GDV_MP_ENABLE_VARIABLE_TEMPLATES
    GDV_MP_TEST((all_of_v<begin_t<l1>, end_t<l1>, is_int>));
    GDV_MP_TEST_NOT((all_of_v<begin_t<l2>, end_t<l2>, is_int>));
#endif /*GDV_MP_ENABLE_VARIABLE_TEMPLATES*/
}
