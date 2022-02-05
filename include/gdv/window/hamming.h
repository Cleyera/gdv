#ifndef GDV_WINDOW_HAMMING_H_
#define GDV_WINDOW_HAMMING_H_

#include <cmath>
#include <gdv/constant.h>

namespace gdv {
namespace window {

template <typename Ty>
Ty hamming(Ty x) {
    return static_cast<Ty>(0.54) - static_cast<Ty>(0.46) * ::std::cos(static_cast<Ty>(2) * ::gdv::pi<Ty> * x);
}

} // namespace window
} // namespace gdv

#endif
