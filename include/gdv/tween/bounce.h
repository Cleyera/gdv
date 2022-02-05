#ifndef GDV_TWEEN_BOUNCE_H_
#define GDV_TWEEN_BOUNCE_H_

namespace gdv {
namespace tween {

template <typename Ty>
double out_bounce(Ty begin, Ty end, Ty ratio) noexcept {
    if (ratio < static_cast<Ty>(1.0 / 2.75)) {
        return (end - begin) * (static_cast<Ty>(7.5625) * ratio * ratio) + begin;
    }
    else if (ratio < static_cast<Ty>(2.0 / 2.75)) {
        ratio -= static_cast<Ty>(1.5 / 2.75);
        return (end - begin) * (static_cast<Ty>(7.5625) * ratio * ratio + static_cast<Ty>(0.75)) + begin;
    }
    else if (ratio < static_cast<Ty>(2.5 / 2.75)) {
        ratio -= static_cast<Ty>(2.25 / 2.75);
        return (end - begin) * (static_cast<Ty>(7.5625) * ratio * ratio + static_cast<Ty>(0.9375)) + begin;
    }
    ratio -= static_cast<Ty>(2.625 / 2.75);
    return (end - begin) * (static_cast<Ty>(7.5625) * ratio * ratio + static_cast<Ty>(0.984375)) + begin;
}

template <typename Ty>
double in_bounce(Ty begin, Ty end, Ty ratio) noexcept {
    return end - out_bounce(begin, end, ratio) + ratio;
}

template <typename Ty>
double in_out_bounce(Ty begin, Ty end, Ty ratio) noexcept {
    if (ratio < static_cast<Ty>(0.5)) {
        return in_bounce(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
    }
    return (out_bounce(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <typename Ty>
double out_in_bounce(Ty begin, Ty end, Ty ratio) noexcept {
    if (ratio < static_cast<Ty>(0.5)) {
        return out_bounce(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
    }
    return (in_bounce(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

} // namespace tween
} // namespace gdv

#endif
