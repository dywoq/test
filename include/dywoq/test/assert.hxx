#ifndef _DYWOQ_TEST_ASSERT_HXX
#define _DYWOQ_TEST_ASSERT_HXX

#include <source_location>
#ifdef __cplusplus
#if __cplusplus >= 202002LL
#include "result.hxx"

namespace dywoq::test
{
  // Returns `result` instance based on condition.
  // If condition is false, the function returns instance with
  // `result_kind::failure` kind, otherwise, instance is returned with given
  // location only.
  inline result assert(bool condition, const char *message,
                       const std::source_location &location) noexcept
  {
    if (!condition)
    {
      return {message, result_kind::failure, location};
    }
    return {location};
  }
} // namespace dywoq::test

#endif
#endif

#endif
