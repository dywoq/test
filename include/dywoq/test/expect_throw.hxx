#ifndef _DYWOQ_TEST_EXPECT_THROW_HXX
#define _DYWOQ_TEST_EXPECT_THROW_HXX

#ifdef __cplusplus
#if __cplusplus >= 202002LL
#include <utility>
#include <functional>

namespace dywoq::test
{
#ifdef __cpp_exceptions
  // Expects the function with given arguments to throw an exception.
  // If no exceptions were caught, returns false.
  template <typename ExceptionT, typename Fn, typename... Args>
  bool expect_throw(Fn &&fn, Args &&...args)
  {
    try
    {
      std::invoke(std::forward<Fn>(fn), std::forward<Args>(args)...);
    }
    catch (const ExceptionT &)
    {
      return true;
    }
    catch (...)
    {
      return false;
    }
    return false;
  }
#endif
} // namespace dywoq::test

#endif
#endif

#endif
