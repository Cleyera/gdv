#ifndef GDV_TYPE_LIST_H_
#define GDV_TYPE_LIST_H_

#include <type_traits>

namespace gdv {
namespace mp {

template <typename... Args>
struct type_list {
    using type = type_list<Args...>;
};

} // namespace mp
} // namespace gdv

#endif
