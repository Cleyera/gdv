#ifndef GDV_TWEEN_CUBIC_H_
#define GDV_TWEEN_CUBIC_H_

namespace gdv {
namespace tween {

template <typename Ty>
Ty in_cubic(Ty begin, Ty end, Ty ratio) noexcept {
    return (end - begin) * ratio * ratio * ratio + begin;
}

template <typename Ty>
Ty out_cubic(Ty begin, Ty end, Ty ratio) noexcept {
    ratio = ratio - static_cast<Ty>(1);
    return (end - begin) * ratio * ratio * ratio + begin;
}

template <typename Ty>
Ty in_out_cubic(Ty begin, Ty end, Ty ratio) noexcept {
    return ratio < static_cast<Ty>(0.5) ?
        in_cubic(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5):
        (out_cubic(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <typename Ty>
Ty out_in_cubic(Ty begin, Ty end, Ty ratio) noexcept {
    return ratio < static_cast<Ty>(0.5) ?
        out_cubic(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5):
        (in_cubic(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

} // namespace tween
} // namespace gdv

#endif
