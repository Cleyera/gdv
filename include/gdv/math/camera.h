#ifndef GDV_CAMERA_H_
#define GDV_CAMERA_H_

#include <gdv/math/transform.h>
#include <gdv/math/vector3.h>
#include <gdv/math/matrix4x4.h>

namespace gdv {

template <typename Ty>
struct camera {

    enum class mode : int {
        perspective = 0,
        orthogonal = 1,
    };

  camera() noexcept
    : mode{}
    , position{}
    , destination{}
    , up{}
    , left{}
    , right{}
    , bottom{}
    , top{}
    , near{}
    , far{}{}

    camera(
        mode mode,
        vector3<Ty> position,
        vector3<Ty> destination,
        Ty left,
        Ty right,
        Ty bottom,
        Ty top,
        Ty near,
        Ty far) noexcept
        : mode{mode}
        , position{position}
        , destination{destination}
        , up{static_cast<Ty>(0), static_cast<Ty>(1), static_cast<Ty>(0)}
        , left{left}
        , right{right}
        , bottom{bottom}
        , top{top}
        , near{near}
        , far{far}{}

    camera(
        mode mode,
        vector3<Ty> position,
        vector3<Ty> destination,
        Ty width,
        Ty height,
        Ty near,
        Ty far) noexcept
        : mode{mode}
        , position{position}
        , destination{destination}
        , up{static_cast<Ty>(0), static_cast<Ty>(1), static_cast<Ty>(0)}
        , left{-width / static_cast<Ty>(2)}
        , right{width / static_cast<Ty>(2)}
        , bottom{-height / static_cast<Ty>(2)}
        , top{height / static_cast<Ty>(2)}
        , near{near}
        , far{far}{}

    camera(
        mode mode,
        vector3<Ty> position,
        vector3<Ty> destination,
        vector3<Ty> up,
        Ty left,
        Ty right,
        Ty bottom,
        Ty top,
        Ty near,
        Ty far) noexcept
        : mode{mode}
        , position{position}
        , destination{destination}
        , up{up}
        , left{left}
        , right{right}
        , bottom{bottom}
        , top{top}
        , near{near}
        , far{far}{}

    camera(
        mode mode,
        vector3<Ty> position,
        vector3<Ty> destination,
        vector3<Ty> up,
        Ty width,
        Ty height,
        Ty near,
        Ty far) noexcept
        : mode{mode}
        , position{position}
        , destination{destination}
        , up{up}
        , left{-width / static_cast<Ty>(2)}
        , right{width / static_cast<Ty>(2)}
        , bottom{-height / static_cast<Ty>(2)}
        , top{height / static_cast<Ty>(2)}
        , near{near}
        , far{far}{}

    camera(
        vector3<Ty> position,
        vector3<Ty> destination,
        vector3<Ty> up,
        Ty fovy,
        Ty aspect,
        Ty near,
        Ty far) noexcept
        : mode{mode::perspective}
        , position{position}
        , destination{destination}
        , up{up}
        , left{}
        , right{}
        , bottom{}
        , top{}
        , near{near}
        , far{far} {
            Ty width = (near / std::tan(fovy / static_cast<Ty>(2))) / static_cast<Ty>(2);
            Ty height = width / aspect;
            top	    = -height;
            bottom  =  height;
            left	= -width;
            right	=  width;
        }

    camera(const camera<Ty> &c) noexcept
        : mode{c.mode}
        , position{c.position}
        , destination{c.destination}
        , up{c.up}
        , left{c.left}
        , right{c.right}
        , bottom{c.bottom}
        , top{c.top}
        , near{c.near}
        , far{c.far}{}

    camera& operator = (const camera<Ty> &c) noexcept {
        mode        = c.mode;
        position    = c.position;
        destination = c.destination;
        up          = c.up;
        left        = c.left;
        right       = c.right;
        bottom      = c.bottom;
        top         = c.top;
        near        = c.near;
        far         = c.far;
        return *this;
    }

    void set_width(Ty width) noexcept {
        left    = -width / static_cast<Ty>(2);
        right   =  width / static_cast<Ty>(2);
    }

    void set_height(Ty height) noexcept {
        top     = height / static_cast<Ty>(2);
        bottom  = height / static_cast<Ty>(2);
    }

    void set_near_far(Ty near, Ty far) noexcept {
        near    = near;
        far     = far;
    }

    void set_rect(Ty left, Ty right, Ty bottom, Ty top) noexcept {
        left    = left;
        right   = right;
        bottom  = bottom;
        top     = top;
    }

    Ty get_width() const noexcept {return right - left;}

    Ty get_height() const noexcept {return top - bottom;}

    mode        mode;
    vector3<Ty> position;
    vector3<Ty> destination;
    vector3<Ty> up;
    Ty          left;
    Ty          right;
    Ty          bottom;
    Ty          top;
    Ty          near;
    Ty          far; 
};

namespace row_major {
namespace right_hand {
namespace {
template <typename Ty>
constexpr matrix4x4<Ty>(*projection_func[])(Ty, Ty, Ty, Ty) noexcept {perspective, orthogonal};
}

template <typename Ty>
matrix4x4<Ty> projection(camera<Ty> c) noexcept {
    return projection_func<Ty>[(int)c.mode](c.get_width(), c.get_height(), c.near, c.far);
}

template <typename Ty>
matrix4x4<Ty> view(camera<Ty> c) noexcept {
    return look_at(c.position, c.destination, c.up);
}

template <typename Ty>
matrix4x4<Ty> to_matrix(camera<Ty> c) noexcept {
    return view(c) * projection(c);
}

template <typename Ty>
matrix4x4<Ty> operator * (camera<Ty> c, matrix4x4<Ty> m) noexcept {
    return to_matrix(c) * m;
}

template <typename Ty>
matrix4x4<Ty> operator * (matrix4x4<Ty> m, camera<Ty> c) noexcept {
    return m * to_matrix(c);
}

template <typename Ty>
vector3<Ty> operator * (vector3<Ty> v, camera<Ty> c) noexcept {
	return to_matrix(c) * v;
}

}// namespace right_hand

namespace left_hand {
namespace {
template <typename Ty>
constexpr matrix4x4<Ty>(*projection_func[])(Ty, Ty, Ty, Ty) noexcept {perspective, orthogonal};
}

template <typename Ty>
matrix4x4<Ty> projection(camera<Ty> c) noexcept {
    return projection_func<Ty>[(int)c.mode](c.get_width(), c.get_height(), c.near, c.far);
}

template <typename Ty>
matrix4x4<Ty> view(camera<Ty> c) noexcept {
    return look_at(c.position, c.destination, c.up);
}

template <typename Ty>
matrix4x4<Ty> to_matrix(camera<Ty> c) noexcept {
	return view(c) * projection(c);
}

template <typename Ty>
matrix4x4<Ty> operator * (camera<Ty> c, matrix4x4<Ty> m) noexcept {
    return to_matrix(c) * m;
}

template <typename Ty>
matrix4x4<Ty> operator * (matrix4x4<Ty> m, camera<Ty> c) noexcept {
    return m * to_matrix(c);
}

template <typename Ty>
vector3<Ty> operator * (vector3<Ty> v, camera<Ty> c) noexcept {
    return to_matrix(c) * v;
}

} // namespace left_hand
} // namespace row_major

namespace column_major {
namespace right_hand {
namespace {
template <typename Ty>
constexpr matrix4x4<Ty>(*projection_func[])(Ty, Ty, Ty, Ty) noexcept {perspective, orthogonal};
}

template <typename Ty>
matrix4x4<Ty> projection(camera<Ty> c) noexcept {
    return projection_func<Ty>[(int)c.mode](c.get_width(), c.get_height(), c.near, c.far);
}

template <typename Ty>
matrix4x4<Ty> view(camera<Ty> c) noexcept {
    return look_at(c.position, c.destination, c.up);
}

template <typename Ty>
matrix4x4<Ty> to_matrix(camera<Ty> c) noexcept {
    return projection(c) * view(c);
}

template <typename Ty>
matrix4x4<Ty> operator * (camera<Ty> c, matrix4x4<Ty> m) noexcept {
    return to_matrix(c) * m;
}

template <typename Ty>
matrix4x4<Ty> operator * (matrix4x4<Ty> m, camera<Ty> c) noexcept {
    return m * to_matrix(c);
}

template <typename Ty>
vector3<Ty> operator * (camera<Ty> c, vector3<Ty> v) noexcept {
    return to_matrix(c) * v;
}

} // namespace right_hand

namespace left_hand {
namespace {
template <typename Ty>
constexpr matrix4x4<Ty>(*projection_func[])(Ty, Ty, Ty, Ty) noexcept {perspective, orthogonal};
}

template <typename Ty>
matrix4x4<Ty> projection(camera<Ty> c) noexcept {
    return projection_func<Ty>[(int)c.mode](c.get_width(), c.get_height(), c.near, c.far);
}

template <typename Ty>
matrix4x4<Ty> view(camera<Ty> c) noexcept {
    return look_at(c.position, c.destination, c.up);
}

template <typename Ty>
matrix4x4<Ty> to_matrix(camera<Ty> c) noexcept {
    return projection(c) * view(c);
}

template <typename Ty>
matrix4x4<Ty> operator * (camera<Ty> c, matrix4x4<Ty> m) noexcept {
    return to_matrix(c) * m;
}

template <typename Ty>
matrix4x4<Ty> operator * (matrix4x4<Ty> m, camera<Ty> c) noexcept {
    return m * to_matrix(c);
}

template <typename Ty>
vector3<Ty> operator * (camera<Ty> c, vector3<Ty> v) noexcept {
    return to_matrix(c) * v;
}

} // namespace left_hand
} // namespavce column_major
} // namespace gdv

#endif
