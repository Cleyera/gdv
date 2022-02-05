#ifndef GDV_WINDOW_GAUSS_H_
#define GDV_WINDOW_GAUSS_H_

#include <cmath>

namespace gdv {
namespace window {

template <typename Ty>
Ty gauss(Ty x, Ty deviation) {
    return ::std::exp(-(x * x) / (deviation * deviation));
}

} // namespace window
} // namespace gdv

#endif
