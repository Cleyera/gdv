#ifndef GDV_VIEWPORT_H_
#define GDV_VIEWPORT_H_

#include <type_traits>
#include <gdv/math/matrix4x4.h>
#include <gdv/math/vector2.h>

namespace gdv {

template <typename Ty>
struct viewport {
    static_assert(std::is_integral<Ty>::value || std::is_floating_point<Ty>::value, "invalid template parameter.");

    viewport() noexcept
        : x{}, y{}, w{}, h{} {}

    viewport(Ty x, Ty y, Ty w, Ty h) noexcept
        : x{x}, y{y}, w{w}, h{h} {}

    viewport(vector2<Ty> pt, Ty w, Ty h) noexcept
        : x{pt.x}, y{pt.y}, w{w}, h{h} {}

    viewport(rect<Ty> r) noexcept
        : x{r.left + r.Width() / static_cast<Ty>(2)}
        , y{r.bottom + r.Height() / static_cast<Ty>(2)}
        , x{r.width()}
        , x{r.height()} {}

    viewport(const viewport<Ty> &v) noexcept
        : x{v.x}, y{v.y}, w{v.w}, h{v.h} {}

    viewport<Ty> operator = (const viewport<Ty> &v) noexcept {
        x = v.x;
        y = v.y;
        w = v.w;
        h = v.h;
        return *this;
    }

    Ty left()    const noexcept {return x - w / static_cast<Ty>(2);}

    Ty right()   const noexcept {return x + w / static_cast<Ty>(2);}

    Ty bottom()  const noexcept {return y - h / static_cast<Ty>(2);}

    Ty top()     const noexcept {return y + h / static_cast<Ty>(2);}

    Ty x;
    Ty y;
    Ty w;
    Ty h;
};

namespace column_major {

template <typename Ty>
matrix4x4<Ty> to_matrix(viewport<Ty> v) {
    static constexpr Ty _0 = static_cast<Ty>(0);
    static constexpr Ty _1 = static_cast<Ty>(1);
    static constexpr Ty _2 = static_cast<Ty>(2);
    return {
        v.w / _2, _0, _0, v.x + v.w / _2,
        _0, v.h / _2, _0, v.y + v.h / _2,
        _0, _0, _1, _0,
        _0, _0, _0, _1
    };
}

} // nemspace column_major

namespace row_major {

template <typename Ty>
matrix4x4<Ty> to_matrix(viewport<Ty> v) {
    static constexpr Ty _0 = static_cast<Ty>(0);
    static constexpr Ty _1 = static_cast<Ty>(1);
    static constexpr Ty _2 = static_cast<Ty>(2);
    return {
        v.w / _2, _0, _0, _0,
        _0, v.h / _2, _0, _0,
        _0, _0, _1, _0,
        v.x + v.w / _2, v.y + v.h / _2, _0, _1
    };
}

} // namespace row_major
} // namespace gdv

#endif
