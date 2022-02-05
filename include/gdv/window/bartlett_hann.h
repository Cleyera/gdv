#ifndef GDV_WINDOW_BARTLETT_HANN_H_
#define GDV_WINDOW_BARTLETT_HANN_H_

#include <cmath>
#include <gdv/constant.h>

namespace gdv {
namespace window {

template <typename Ty>
Ty bartlett_hann(Ty x) {
    return static_cast<Ty>(0.64)
        - static_cast<Ty>(0.48) * ::std::abs(x - static_cast<Ty>(0.5))
        - static_cast<Ty>(0.38) * ::std::cos(static_cast<Ty>(2) * ::gdv::pi<Ty> * x);
}

} // namespace window
} // namespace gdv

#endif
