#ifndef GDV_WINDOW_SINE_H_
#define GDV_WINDOW_SINE_H_

#include <cmath>
#include <gdv/constant.h>

namespace gdv {
namespace window {

template <typename Ty>
Ty sine(Ty x) {
    return ::std::sin(::gdv::pi<Ty> * x);
}

} // namespace window
} // namespace gdv

#endif
