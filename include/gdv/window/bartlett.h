#ifndef GDV_WINDOW_BARTLETT_H_
#define GDV_WINDOW_BARTLETT_H_

#include <cmath>

namespace gdv {
namespace window {

template <typename Ty>
Ty bartlett(Ty x) {
    return static_cast<Ty>(1) - static_cast<Ty>(2) * ::std::abs(x - static_cast<Ty>(0.5));
}

} // namespace window
} // namespace gdv

#endif
