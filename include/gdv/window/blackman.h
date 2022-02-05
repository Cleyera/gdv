#ifndef GDV_WINDOW_BLACKMAN_H_
#define GDV_WINDOW_BLACKMAN_H_

#include <cmath>
#include <gdv/constant.h>

namespace gdv {
namespace window {

template <typename Ty>
Ty blackman(Ty x) {
    return static_cast<Ty>(0.42) 
        - static_cast<Ty>(0.50) * ::std::cos(static_cast<Ty>(2) * ::gdv::pi<Ty> * x) 
        + static_cast<Ty>(0.08) * ::std::cos(static_cast<Ty>(4) * ::gdv::pi<Ty> * x);
}

} // namespace window
} // namespace gdv

#endif
