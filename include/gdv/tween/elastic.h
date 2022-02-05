#ifndef GDV_TWEEN_ELASTIC_H_
#define GDV_TWEEN_ELASTIC_H_

#include <cmath>

namespace gdv {
namespace tween {

template <typename Ty>
Ty in_elastic(Ty begin, Ty end, Ty ratio) noexcept {
    return (end - begin) * ::std::sin(static_cast<Ty>(13) * ::gdv::pi<Ty> * ratio) * ::std::pow(static_cast<Ty>(2), static_cast<Ty>(10) * (ratio - static_cast<Ty>(1))) + begin;
}

template <typename Ty>
float out_elastic(Ty begin, Ty end, Ty ratio) noexcept {
    return (end - begin) * ::std::sin(static_cast<Ty>(13) * ::gdv::pi<Ty> * ratio) * ::std::pow(static_cast<Ty>(2), static_cast<Ty>(-10) * ratio) + begin;
}

template <typename Ty>
float in_out_elastic(Ty begin, Ty end, Ty ratio) noexcept {
    return ratio < static_cast<Ty>(0.5) ?
        in_elastic(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5):
        (out_elastic(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <typename Ty>
float out_in_elastic(Ty begin, Ty end, Ty ratio) noexcept {
    return ratio < static_cast<Ty>(0.5) ?
        out_elastic(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5):
        (in_elastic(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

} // namespace tween
} // namespace gdv

#endif
