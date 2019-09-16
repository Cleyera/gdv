#ifndef GDV_VECTOR2_H_
#define GDV_VECTOR2_H_

#include <type_traits>
#include <cmath>

namespace gdv {

template <typename Ty>
struct vector2 {
    static_assert(::std::is_integral<Ty>::value || ::std::is_floating_point<Ty>::value, "invalid template parameter.");

    constexpr vector2() noexcept
        : x{}, y{}{}

    constexpr vector2(Ty x, Ty y) noexcept
        : x{x}, y{y}{}

    constexpr vector2(const vector2<Ty> &v) noexcept
        : x{v.x}, y{v.y}{}

    vector2<Ty>& operator = (const vector2<Ty> &v) noexcept {
        x = v.x;
        y = v.y;
        return *this;
    }

    Ty x;
    Ty y;
};

template <typename Ty>
bool operator == (vector2<Ty> v1, vector2<Ty> v2) noexcept {
    return v1.x == v2.x && v1.y == v2.y;
}

template <typename Ty>
bool operator != (vector2<Ty> v1, vector2<Ty> v2) noexcept {
    return v1.x != v2.x || v1.y != v2.y;
}

template <typename Ty>
vector2<Ty>& operator += (vector2<Ty> &v1, vector2<Ty> v2) noexcept {
    v1.x += v2.x;
    v1.y += v2.y;
    return v1;
}

template <typename Ty>
vector2<Ty>& operator += (vector2<Ty> &v, Ty val) noexcept {
    v.x += val;
    v.y += val;
    return v;
}

template <typename Ty>
vector2<Ty>& operator -= (vector2<Ty> &v1, vector2<Ty> v2) noexcept {
    v1.x -= v2.x;
    v1.y -= v2.y;
    return v1;
}

template <typename Ty>
vector2<Ty>& operator *= (vector2<Ty> &v, Ty val) noexcept {
    v.x *= val;
    v.y *= val;
    return v;
}

template <typename Ty>
vector2<Ty>& operator /= (vector2<Ty> &v, Ty val) noexcept {
    v.x /= val;
    v.y /= val;
    return v;
}

template <typename Ty>
vector2<Ty>& operator -= (vector2<Ty> &v, Ty val) noexcept {
    v.x -= val;
    v.y -= val;
    return v;
}

template <typename Ty>
vector2<Ty> operator + (vector2<Ty> v1, vector2<Ty> v2) noexcept {
    return {v1.x + v2.x, v1.y + v2.y};
}

template <typename Ty>
vector2<Ty> operator + (vector2<Ty> v, Ty val) noexcept {
    return {v.x + val, v.y + val};
}

template <typename Ty>
vector2<Ty> operator - (vector2<Ty> v1, vector2<Ty> v2) noexcept {
    return {v1.x - v2.x, v1.y - v2.y};
}

template <typename Ty>
vector2<Ty> operator - (vector2<Ty> v, Ty val) noexcept {
    return {v.x - val, v.y - val};
}

template <typename Ty>
vector2<Ty> operator * (vector2<Ty> v, Ty val) noexcept {
    return {v.x * val, v.y * val};
}

template <typename Ty>
vector2<Ty> operator / (vector2<Ty> v, Ty val) noexcept {
    return {v.x / val, v.y / val};
}

template <typename Ty>
Ty dot(vector2<Ty> v1, vector2<Ty> v2) noexcept {
    static_assert(::std::is_floating_point<Ty>::value, "Template parameters require floating point type.");
    return v1.x * v2.x + v1.y * v2.y;
}

template <typename Ty>
Ty cross(vector2<Ty> v1, vector2<Ty> v2) noexcept {
    static_assert(::std::is_floating_point<Ty>::value, "Template parameters require floating point type.");
    return v1.x * v2.y - v1.y * v2.x;
}

template <typename Ty>
Ty angle(vector2<Ty> v1, vector2<Ty> v2) noexcept {
    return static_cast<Ty>(::std::atan2(::gdv::dot(v1, v2), ::gdv::cross(v1, v2)));
}

template <typename Ty>
Ty length(vector2<Ty> v) noexcept {
    static_assert(::std::is_floating_point<Ty>::value, "Template parameters require floating point type.");
    return static_cast<Ty>(::std::hypot(v.x, v.y));
}

template <typename Ty>
vector2<Ty> normalize(vector2<Ty> v) noexcept {
    return (v / ::gdv::length(v));
}

template <typename Ty>
vector2<Ty> rotate(vector2<Ty> v, vector2<Ty> center, Ty angle) noexcept {
    static_assert(::std::is_floating_point<Ty>::value, "Template parameters require floating point type.");
    const Ty s = ::std::sin(angle);
    const Ty c = ::std::cos(angle);
    const Ty x = v.x - center.x;
    const Ty y = v.y - center.y;
    return {
        x * c + y * s + center.x,
        y * c - x * s + center.y
    };
}

using point = ::gdv::vector2<int>;
using vec2  = ::gdv::vector2<float>;

} // namespace gdv

#endif
