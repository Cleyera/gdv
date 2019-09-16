#include <gdv/mp/test/test.h>

template <typename... Ty>
using is_int = ::gdv::mp::bind<::std::is_same, int>::type<Ty...>;

template <typename T1, typename T2, typename T3>
struct is_ics {
    static constexpr bool value = ::std::is_same<T1, int>::value
        && ::std::is_same<T2, char>::value
        && ::std::is_same<T3, short>::value;
};

template <typename Ty>
using is_char = ::gdv::mp::bind<is_ics, int, placeholder<0>, short>::type<Ty>;

template <typename T1, typename T2>
using is_sc = ::gdv::mp::bind<is_ics, int, placeholder<1>, placeholder<0> >::type<T1, T2>;

template <typename Ty>
using is_short = ::gdv::mp::bind<is_sc, placeholder<0>, char>::type<Ty>;

GDV_MP_TEST_CASE(bind) {
    GDV_MP_TEST((is_int<int>::value));
    GDV_MP_TEST((is_char<char>::value));
    GDV_MP_TEST((is_sc<short, char>::value));
    GDV_MP_TEST((is_short<short>::value));
}
