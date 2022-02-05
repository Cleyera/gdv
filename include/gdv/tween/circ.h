#ifndef GDV_TWEEN_CIRC_H_
#define GDV_TWEEN_CIRC_H_

#include <cmath>

namespace gdv {
namespace tween {

template <typename Ty>
Ty in_circ(Ty begin, Ty end, Ty ratio) noexcept {
    return (end - begin) * (static_cast<Ty>(1) - ::std::sqrt(static_cast<Ty>(1) - ratio * ratio));
}

template <typename Ty>
Ty out_circ(Ty begin, Ty end, Ty ratio) noexcept {
    return (end - begin) * ::std::sqrt(static_cast<Ty>(1) - ratio * ratio) + begin;
}

template <typename Ty>
Ty in_out_circ(Ty begin, Ty end, Ty ratio) noexcept {
    return ratio < static_cast<Ty>(0.5) ?
        in_circ(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5):
        (out_circ(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <typename Ty>
Ty out_in_circ(Ty begin, Ty end, Ty ratio) noexcept {
    return ratio < static_cast<Ty>(0.5) ?
        out_circ(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5):
        (in_circ(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

} // namespace tween
} // namespace gdv

#endif
