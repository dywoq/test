#ifndef _DYWOQ_TEST_INFO_HXX
#define _DYWOQ_TEST_INFO_HXX

#include <cstdint>
#ifdef __cplusplus
#if __cplusplus >= 202002LL

namespace dywoq::test {
  // Represents the information collected during running tests
  // and available after running them.
  struct info {
    bool has_failures = false;
    std::uint32_t failures_count = 0;
  };
} // namespace dywoq::test

#endif
#endif

#endif