#ifndef GDV_WINDOW_PARZEN_H_
#define GDV_WINDOW_PARZEN_H_

#include <cmath>

namespace gdv {
namespace window {

template <typename Ty>
Ty parzen(Ty x) {
    x = ::std::abs(x * static_cast<Ty>(2));
    const Ty t = ::std::ceil(x - static_cast<Ty>(1));
    return (static_cast<Ty>(1) - static_cast<Ty>(1.5) * ::std::pow(x, 2) + static_cast<Ty>(0.75) * ::std::pow(::std::abs(x), 3)) * (static_cast<Ty>(1) - t) 
        + (static_cast<Ty>(0.25) * (static_cast<Ty>(2) - ::std::pow(::std::abs(x), 3))) * t;
}

} // namespace window
} // namespace gdv

#endif
