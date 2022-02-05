#ifndef GDV_WINDOW_NUTTALL_H_
#define GDV_WINDOW_NUTTALL_H_

#include <cmath>
#include <gdv/constant.h>

namespace gdv {
namespace window {

template <typename Ty>
Ty nuttall(Ty x) {
    return static_cast<Ty>(0.355768) 
        + static_cast<Ty>(0.487396) * ::std::cos(static_cast<Ty>(4) * ::gdv::pi<Ty> * x)
        - static_cast<Ty>(0.012604) * ::std::cos(static_cast<Ty>(6) * ::gdv::pi<Ty> * x);
}

} // namespace window
} // namespace gdv

#endif
