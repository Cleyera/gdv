#ifndef GDV_WINDOW_AKAIKE_H_
#define GDV_WINDOW_AKAIKE_H_

#include <cmath>
#include <gdv/constant.h>

namespace gdv {
namespace window {

template <typename Ty>
Ty akaike(Ty x) {
    return static_cast<Ty>(0.625) 
        + static_cast<Ty>(0.5) * ::std::cos(static_cast<Ty>(2) * ::gdv::pi<Ty> * x)
        - static_cast<Ty>(0.125) * ::std::cos(static_cast<Ty>(4) * ::gdv::pi<Ty> * x);
}

} // namespace window
} // namespace gdv

#endif
