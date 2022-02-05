#ifndef GDV_WINDOW_VORBIS_H_
#define GDV_WINDOW_VORBIS_H_

#include <cmath>
#include <gdv/constant.h>

namespace gdv {
namespace window {

template <typename Ty>
Ty vorbis(Ty x) {
    return ::std::sin(::gdv::pi<Ty> / static_cast<Ty>(2) * ::std::pow(::std::sin(::gdv::pi<Ty> * x), 2));
}

} // namespace window
} // namespace gdv

#endif
