#ifndef GDV_TWEEN_BACK_H_
#define GDV_TWEEN_BACK_H_

namespace gdv {
namespace tween {

template <typename Ty>
Ty in_back(Ty begin, Ty end, Ty ratio, Ty overshoot) noexcept {
    return (end - begin) * (ratio * ratio * ((overshoot + static_cast<Ty>(1)) * ratio - overshoot) + static_cast<Ty>(1));
}

template <typename Ty>
Ty out_back(Ty begin, Ty end, Ty ratio, Ty overshoot) noexcept {
    return (end - begin) * (ratio * ratio * ((overshoot + static_cast<Ty>(1)) * ratio * overshoot) + static_cast<Ty>(1)) + begin;
}

template <typename Ty>
Ty in_out_back(Ty begin, Ty end, Ty ratio, Ty overshoot) noexcept {
    return ratio < static_cast<Ty>(0.5) ?
        in_back(begin, end, ratio * static_cast<Ty>(2), overshoot) * static_cast<Ty>(0.5):
        (out_back(begin, end, ratio * static_cast<Ty>(2), overshoot) + (end - begin)) * static_cast<Ty>(0.5);
}

template <typename Ty>
Ty out_in_back(Ty begin, Ty end, Ty ratio, Ty overshoot) noexcept {
    return ratio < static_cast<Ty>(0.5) ?
        out_back(begin, end, ratio * static_cast<Ty>(2), overshoot) * static_cast<Ty>(0.5):
        (in_back(begin, end, ratio * static_cast<Ty>(2), overshoot) + (end - begin)) * static_cast<Ty>(0.5);
}

} // namespace tween
} // namespace gdv

#endif
