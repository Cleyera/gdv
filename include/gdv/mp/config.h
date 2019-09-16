#ifndef GDV_CONFIG_H_
#define GDV_CONFIG_H_

#include <type_traits>

#ifdef __cpp_variable_templates
#   define GDV_MP_ENABLE_VARIABLE_TEMPLATES
#endif // __cpp_variable_templates

#ifdef __cpp_lib_void_t
#   define GDV_VOID_T ::std::void_t
#else
namespace gdv {
namespace mp {
template <typename...> using void_t = void;
} // namespace mp
} // namespace gdv
#   define GDV_VOID_T ::gdv::mp::void_t
#endif // __cpp_lib_void_t

#endif
