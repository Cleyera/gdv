#include <gdv/mp/test/test.h>

template <typename Ty>
struct is_int {
    static constexpr bool value = std::is_same<int, Ty>::value;
};

GDV_MP_TEST_CASE(push_back_if) {
    GDV_MP_TEST_IS_SAME(
        push_back_if<
            is_int,
            int,
            type_list<short>
        >::type,
        type_list<short, int>);
    GDV_MP_TEST_IS_SAME(
        push_back_if<
            is_int,
            char,
            type_list<short>
        >::type,
        type_list<short>);
    GDV_MP_TEST_IS_SAME(
        push_back_if_t<
            is_int,
            int,
            type_list<short> >,
        type_list<short, int>);
    GDV_MP_TEST_IS_SAME(
        push_back_if_t<
            is_int,
            char,
            type_list<short> >,
        type_list<short>);
}
