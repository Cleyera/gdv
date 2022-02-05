#ifndef GDV_WINDOW_BALCKMAN_NUTTALL_H_
#define GDV_WINDOW_BALCKMAN_NUTTALL_H_

#include <cmath>
#include <gdv/constant.h>

namespace gdv {
namespace window {

template <typename Ty>
Ty flat_top(Ty x) {
    return static_cast<Ty>(1) 
        - static_cast<Ty>(1.93)  * ::std::cos(static_cast<Ty>(2) * ::gdv::pi<Ty> * x)
        + static_cast<Ty>(1.29)  * ::std::cos(static_cast<Ty>(4) * ::gdv::pi<Ty> * x)
        - static_cast<Ty>(0.388) * ::std::cos(static_cast<Ty>(6) * ::gdv::pi<Ty> * x)
        + static_cast<Ty>(0.032) * ::std::cos(static_cast<Ty>(8) * ::gdv::pi<Ty> * x);
}

} // namespace window
} // namespace gdv

#endif
