
//! @file golden_section_search.hpp

#ifndef CP_LIBRARY_GOLDEN_SECTION_SEARCH_HPP
#define CP_LIBRARY_GOLDEN_SECTION_SEARCH_HPP

#include <cassert>
#include <cmath>
#include <type_traits>
#include <utility>

#ifndef CP_LIBRARY_ASSERT
//! @brief Assert macro
#  define CP_LIBRARY_ASSERT(...) assert(__VA_ARGS__)
#  define CP_LIBRARY_ASSERT_NOT_DEFINED
#endif

namespace lib {

//! @brief Function to find the maximum or minimum value of a convex function f(x) when x is in [a, b]
//! @tparam minimize Set to true if you want to minimize the f(x), otherwise set to false.
//! @tparam RealType type of x (deduced from parameters)
//! @tparam Func type of f (deduced from parameters)
//! @param low lower bound (a)
//! @param high upper bound (b)
//! @param f function to minimize or maximize
//! @param diff acceptable error
//! @return std::pair { argmin(f(x)), min(f(x)) } (or argmax & max)
//! @note time complexity: O(log((high - low) / diff * (time needed to calculate f(x))))
template <bool minimize, typename RealType, typename Func>
[[nodiscard]] auto golden_section_search(RealType low, RealType high, const Func& f, const RealType diff = 1e-9L) {
  using F_ResType = decltype(f(std::declval<RealType>()));
  CP_LIBRARY_ASSERT(low <= high);

  using std::sqrt;
  const RealType phi        = (1 + sqrt(RealType(5.0L))) / 2;
  const RealType phi_plus_1 = phi + 1;

  RealType mid_low     = (low * phi + high) / phi_plus_1;
  RealType mid_high    = (low + high * phi) / phi_plus_1;
  F_ResType score_low  = f(mid_low);
  F_ResType score_high = f(mid_high);

  while (high - low > diff) {
    if (minimize ^ (score_low < score_high)) {
      low        = mid_low;
      mid_low    = mid_high;
      score_low  = score_high;
      mid_high   = (low + high * phi) / phi_plus_1;
      score_high = f(mid_high);
    } else {
      high       = mid_high;
      mid_high   = mid_low;
      score_high = score_low;
      mid_low    = (low * phi + high) / phi_plus_1;
      score_low  = f(mid_low);
    }
  }

  return std::pair {low, score_low};
}

}  // namespace lib

#ifdef CP_LIBRARY_ASSERT_NOT_DEFINED
#  undef CP_LIBRARY_ASSERT
#  undef CP_LIBRARY_ASSERT_NOT_DEFINED
#endif

#endif  // CP_LIBRARY_GOLDEN_SECTION_SEARCH_HPP
