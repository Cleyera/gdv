#ifndef GDV_TWEEN_QUAD_H_
#define GDV_TWEEN_QUAD_H_

namespace gdv {
namespace tween {

template <typename Ty>
Ty in_quad(Ty begin, Ty end, Ty ratio) noexcept {
    return (end - begin) * ratio * ratio + begin;
}

template <typename Ty>
Ty out_quad(Ty begin, Ty end, Ty ratio) noexcept {
    ratio = ratio - static_cast<Ty>(1);
    return (end - begin) * ratio * ratio + begin;
}

template <typename Ty>
Ty in_out_quad(Ty begin, Ty end, Ty ratio) noexcept {
    return ratio < static_cast<Ty>(0.5) ?
        in_quad(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5):
        (out_quad(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <typename Ty>
Ty out_in_quad(Ty begin, Ty end, Ty ratio) noexcept {
    return ratio < static_cast<Ty>(0.5) ?
        out_quad(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5):
        (in_quad(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

} // namespace tween
} // namespace gdv

#endif
