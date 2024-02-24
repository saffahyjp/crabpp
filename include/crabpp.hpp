#ifndef CRABPP_HPP
#define CRABPP_HPP

#include <concepts>
#include <ranges>
#include <type_traits>

#define let      const auto&&
#define let_mut  ::crabpp::detail::can_let_mut auto&&
#define ref      const auto&
#define ref_mut  ::crabpp::detail::not_const auto&

#define fn       auto

namespace crabpp {

namespace detail {
    template <typename T>
    concept not_const = !std::is_const_v<T>;
    template <typename T>
    concept can_let_mut = !std::is_lvalue_reference_v<T> && not_const<T>;
}

template <std::integral T>
[[nodiscard]] fn range(const T& end) {
    return std::ranges::iota_view(T(0), end);
}
template <std::integral T>
[[nodiscard]] fn range(const T& begin, const T& end) {
    return std::ranges::iota_view(begin, end);
}

}  // namespace crabpp

#endif  // CRABPP_HPP
