#ifndef GDV_WINDOW_BALCKMAN_NUTTALL_H_
#define GDV_WINDOW_BALCKMAN_NUTTALL_H_

#include <cmath>
#include <gdv/constant.h>

namespace gdv {
namespace window {

template <typename Ty>
Ty blackman_nuttall(Ty x) {
    return static_cast<Ty>(0.3635819) 
        - static_cast<Ty>(0.4891775) * ::std::cos(static_cast<Ty>(2) * ::gdv::pi<Ty> * x)
        + static_cast<Ty>(0.1365995) * ::std::cos(static_cast<Ty>(4) * ::gdv::pi<Ty> * x)
        - static_cast<Ty>(0.0106411) * ::std::cos(static_cast<Ty>(6) * ::gdv::pi<Ty> * x);
}

} // namespace window
} // namespace gdv

#endif
