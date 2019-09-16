#ifndef GDV_COLOR_RGB_H_
#define GDV_COLOR_RGB_H_

#include <algorithm>
#include <gdv/tween.h>

namespace gdv {

template <typename Ty>
struct hsv;
template <typename Ty>
struct rgb;

template <typename Ty>
hsv<Ty> to_hsv(rgb<Ty> c) noexcept;

template <typename Ty>
struct rgb {

    constexpr rgb() noexcept
        : a{}, r{}, g{}, b{}{}

    constexpr rgb(Ty a, Ty r, Ty g, Ty b) noexcept
        : a{a}, r{r}, g{g}, b{b}{}

    rgb(hsv<Ty> c) noexcept
        : a{}, r{}, g{}, b{} {
        *this = to_rgb(c);
    }

    constexpr rgb(const rgb &co) noexcept
        : a{co.a}, r{co.r}, g{co.g}, b{co.b}{}

    rgb& operator = (rgb c) noexcept {
        a = c.a;
        r = c.r;
        g = c.g;
        b = c.b;
        return *this;
    }

    Ty a, r, g, b;
};

template <typename Ty>
rgb<Ty> operator + (const rgb<Ty> &c1, const rgb<Ty> &c2) noexcept {
    return {c1.a + c2.a, c1.r + c2.r, c1.g + c2.g, c1.b + c2.b};
}

template <typename Ty>
rgb<Ty> operator - (const rgb<Ty> &c1, const rgb<Ty> &c2) noexcept {
    return {c1.a - c2.a, c1.r - c2.r, c1.g - c2.g, c1.b - c2.b};
}

template <typename Ty>
rgb<Ty> operator * (const rgb<Ty> &c1, const rgb<Ty> &c2) noexcept {
    return {c1.a * c2.a, c1.r * c2.r, c1.g * c2.g, c1.b * c2.b};
}

template <typename Ty>
rgb<Ty>& operator += (rgb<Ty> &c1, const rgb<Ty> &c2) noexcept {
    c1.a += c2.a;
    c1.r += c2.r;
    c1.g += c2.g;
    c1.b += c2.b;
    return c1;
}

template <typename Ty>
rgb<Ty>& operator -= (rgb<Ty> &c1, const rgb<Ty> &c2) noexcept {
    c1.a -= c2.a;
    c1.r -= c2.r;
    c1.g -= c2.g;
    c1.b -= c2.b;
    return c1;
}

template <typename Ty>
rgb<Ty>& operator *= (rgb<Ty> &c1, const rgb<Ty> &c2) noexcept {
    c1.a *= c2.a;
    c1.r *= c2.r;
    c1.g *= c2.g;
    c1.b *= c2.b;
    return c1;
}

template <typename Ty>
hsv<Ty> to_hsv(rgb<Ty> c) noexcept {
    constexpr Ty _1 = static_cast<Ty>(1);
    constexpr Ty _2 = static_cast<Ty>(2);
    constexpr Ty _3 = static_cast<Ty>(3);
    Ty max = ::std::max({c.r, c.g, c.b});
    Ty min = ::std::min({c.r, c.g, c.b});
    Ty diff = max - min;
    hsv<Ty> hsv;

    hsv.s = diff / max;
    hsv.v = max;
    hsv.a = c.a;

    if (c.r >= c.g && c.r >= c.b) {
        hsv.h = (c.g - c.b) / diff;
    } else if (c.g >= c.r && c.g >= c.b) {
        hsv.h = (c.b - c.r) / diff + (_1 / _3);
    } else {
        hsv.h = (c.r - c.g) / diff + (_2 / _3);
    }

    return hsv;
}

} // namespace gdv

#endif
