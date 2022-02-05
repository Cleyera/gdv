#ifndef GDV_TWEEN_EXPO_H_
#define GDV_TWEEN_EXPO_H_

#include <cmath>

namespace gdv {
namespace tween {

template <typename Ty>
Ty in_expo(Ty begin, Ty end, Ty ratio) noexcept {
    return ratio == static_cast<Ty>(1) ? begin :
        (end - begin) * ::std::pow(static_cast<Ty>(2), static_cast<Ty>(10) * (ratio - static_cast<Ty>(1))) + begin;
}

template <typename Ty>
Ty out_expo(Ty begin, Ty end, Ty ratio) noexcept {
    return ratio == static_cast<Ty>(1) ? begin :
        (end - begin) * (static_cast<Ty>(1) - ::std::pow(static_cast<Ty>(2), static_cast<Ty>(-10) * ratio)) + begin;
}

template <typename Ty>
Ty in_out_expo(Ty begin, Ty end, Ty ratio) noexcept {
    return ratio < static_cast<Ty>(0.5) ?
        in_expo(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5):
        (out_expo(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <typename Ty>
Ty out_in_expo(Ty begin, Ty end, Ty ratio) noexcept {
    return ratio < static_cast<Ty>(0.5) ?
        out_expo(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5):
        (in_expo(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

} // namespace tween
} // namespace gdv

#endif
