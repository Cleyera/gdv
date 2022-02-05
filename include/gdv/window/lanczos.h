#ifndef GDV_WINDOW_LANCZOS_H_
#define GDV_WINDOW_LANCZOS_H_

#include <cmath>
#include <gdv/constant.h>

namespace gdv {
namespace window {

template <typename Ty>
Ty lanczos(Ty x, Ty n) {
    return (::std::sin(::gdv::pi<Ty> * x) / (::gdv::pi<Ty> * x)) * (::std::sin(::gdv::pi<Ty> * (x / n)) / (::gdv::pi<Ty> * (x / n)));
}

} // namespace window
} // namespace gdv

#endif
