#ifndef GDV_COLOR_HSV_H_
#define GDV_COLOR_HSV_H_

#include <cmath>

namespace gdv {

template <typename Ty>
struct rgb;
template <typename Ty>
struct hsv;

template <typename Ty>
rgb<Ty> to_rgb(hsv<Ty> c) noexcept;

template <typename Ty>
struct hsv {

    constexpr hsv() noexcept
        : a{}, h{}, s{}, v{}{}

    constexpr hsv(Ty a, Ty h, Ty s, Ty v) noexcept
        : a{a}, h{h}, s{s}, v{v}{}

    constexpr hsv(const hsv &c) noexcept
        : a{c.a}, h{c.h}, s{c.s}, v{c.v}{}

    hsv(rgb<Ty> c) noexcept
        : a{}, h{}, s{}, v{} {
        *this = to_hsv(c);
    }

    hsv& operator = (const hsv &c) noexcept {
        a = c.a;
        h = c.h;
        s = c.s;
        v = c.v;
        return *this;
    }

    Ty a, h, s, v;
};

template <typename Ty>
rgb<Ty> to_rgb(hsv<Ty> c) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    constexpr Ty _2 = static_cast<Ty>(2);
    constexpr Ty _3 = static_cast<Ty>(3);
    Ty p[] {
        ::std::abs(::std::fmod( _1        + c.h, _1) * (_2 * _3) - _3),
        ::std::abs(::std::fmod((_2 / _3)  + c.h, _1) * (_2 * _3) - _3),
        ::std::abs(::std::fmod((_1 / _3)  + c.h, _1) * (_2 * _3) - _3),
    };
    rgb rgb {
        c.a,
        c.v * ::gdv::tween::linear(_1, ::std::min(::std::max(p[0], _0), _1), c.s),
        c.v * ::gdv::tween::linear(_1, ::std::min(::std::max(p[1], _0), _1), c.s),
        c.v * ::gdv::tween::linear(_1, ::std::min(::std::max(p[2], _0), _1), c.s)
    };
    return rgb;
}

} // namespace gdv

#endif
