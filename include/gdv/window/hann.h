#ifndef GDV_WINDOW_HANN_H_
#define GDV_WINDOW_HANN_H_

#include <cmath>
#include <gdv/constant.h>

namespace gdv {
namespace window {

template <typename Ty>
Ty hann(Ty x) {
    static constexpr Ty half = static_cast<Ty>(0.5);
    return half - half * ::std::cos(static_cast<Ty>(2) * ::gdv::pi<Ty> * x);
}

} // namespace window
} // namespace gdv

#endif
