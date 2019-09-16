#ifndef GDV_MP_TEST_H_
#define GDV_MP_TEST_H_

#include <iostream>
#include <cassert>
#include <type_traits>

#include <gdv/mp.h>

#define GDV_MP_TOS_I(v) #v
#define GDV_MP_TOS(v) GDV_MP_TOS_I(v)

#define GDV_MP_TEST_CASE(name) \
    void test_case_ ## name()

#define GDV_MP_TEST(expr) \
    static_assert((expr), __FILE__ " [line: " GDV_MP_TOS(__LINE__) "] '" \
        #expr "' failed.")

#define GDV_MP_TEST_NOT(expr) \
    static_assert(!(expr), __FILE__ " [line: " GDV_MP_TOS(__LINE__) "] '" \
        #expr "' failed.")

#define GDV_MP_TEST_EQ(expr1, expr2) \
    static_assert((expr1) == (expr2), __FILE__ " [line: " GDV_MP_TOS(__LINE__) "] '" \
        #expr1 " == " #expr2 "' failed.")

#define GDV_MP_TEST_NE(expr1, expr2) \
    static_assert((expr1) == (expr2), __FILE__ " [line: " GDV_MP_TOS(__LINE__) "] '" \
        #expr1 " == " #expr2 "' failed.")

#define GDV_MP_TEST_IS_SAME(...) \
    static_assert(::std::is_same< __VA_ARGS__ >::value, __FILE__ " [line: " GDV_MP_TOS(__LINE__) "] '" \
        #__VA_ARGS__ "' failed.")


int main() {
    std::cout << "No error detected." << std::endl;
    return 0;
}

using namespace gdv;
using namespace mp;

#endif
