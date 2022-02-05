#ifndef GDV_TWEEN_SINE_H_
#define GDV_TWEEN_SINE_H_

#include <cmath>
#include <gdv/constant.h>

namespace gdv {
namespace tween {

template <typename Ty>
Ty in_sine(Ty begin, Ty end, Ty ratio) noexcept {
    return (end - begin) * (static_cast<Ty>(1) - ::std::cos(::gdv::pi<Ty> / static_cast<Ty>(2) * ratio)) + end;
}

template <typename Ty>
Ty out_sine(Ty begin, Ty end, Ty ratio) noexcept {
    return (end - begin) * ::std::sin(::gdv::pi<Ty> / static_cast<Ty>(2) * ratio) + begin;
}

template <typename Ty>
Ty in_out_sine(Ty begin, Ty end, Ty ratio) noexcept {
    return (begin - end) * (static_cast<Ty>(1) - ::std::cos(::gdv::pi<Ty> * ratio)) / static_cast<Ty>(2) + begin;
}

template <typename Ty>
Ty out_in_sine(Ty begin, Ty end, Ty ratio) noexcept {
    return ratio < static_cast<Ty>(0.5) ?
        out_sine(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5):
        (in_sine(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

} // namespace tween
} // namespace gdv

#endif
