#ifndef GDV_EULER_H_
#define GDV_EULER_H_

#include <type_traits>

namespace gdv {

template <typename Ty>
struct euler {
    static_assert(std::is_integral<Ty>::value || std::is_floating_point<Ty>::value, "invalid template parameter.");

    constexpr euler() noexcept
        : x{}, y{}, z{} {}

    constexpr euler(Ty x, Ty y, Ty z) noexcept
        : x{x}, y{y}, z{z} {}

    constexpr euler(const euler<Ty> &e) noexcept
        : x{e.x}, y{e.y}, z{e.z} {}

    euler<Ty>& operator = (const euler<Ty> &e) noexcept = default;

    Ty x;
    Ty y;
    Ty z;
};

} // namespace gdv

#endif
