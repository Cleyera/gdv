#ifndef GDV_WINDOW_BALCKMAN_HARRIS_H_
#define GDV_WINDOW_BALCKMAN_HARRIS_H_

#include <cmath>
#include <gdv/constant.h>

namespace gdv {
namespace window {

template <typename Ty>
Ty blackman_harris(Ty x) {
    return static_cast<Ty>(0.35875) 
        - static_cast<Ty>(0.48829) * ::std::cos(static_cast<Ty>(2) * ::gdv::pi<Ty> * x)
        + static_cast<Ty>(0.14128) * ::std::cos(static_cast<Ty>(4) * ::gdv::pi<Ty> * x)
        - static_cast<Ty>(0.01168) * ::std::cos(static_cast<Ty>(6) * ::gdv::pi<Ty> * x);
}

} // namespace window
} // namespace gdv

#endif
