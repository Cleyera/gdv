#ifndef GDV_TWEEN_LINER_H_
#define GDV_TWEEN_LINER_H_

namespace gdv {
namespace tween {

template <typename Ty>
Ty linear(Ty begin, Ty end, Ty ratio) noexcept {
    return (end - begin) * ratio + begin;
}

} // namespace tween
} // namespace gdv

#endif
