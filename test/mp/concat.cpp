#include <gdv/mp/test/test.h>

GDV_MP_TEST_CASE(concat) {
    GDV_MP_TEST((std::is_same<
            concat<
                type_list<int, char>,
                type_list<short>
            >::type,
            type_list<int, char, short>
        >::value));
    GDV_MP_TEST((std::is_same<
            concat_t<
                type_list<int, char>,
                type_list<short> >,
            type_list<int, char, short>
        >::value));
}
