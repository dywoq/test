#ifndef _DYWOQ_TEST_FUNCTION_T_HXX
#define _DYWOQ_TEST_FUNCTION_T_HXX

#ifdef __cplusplus
#if __cplusplus >= 202002LL
#include "fwd.hxx"
#include "result.hxx"
#include <functional>

namespace dywoq::test
{
  // Represents the test function.
  using function_t = std::function<const result()>;
} // namespace dywoq::test

#endif
#endif

#endif
