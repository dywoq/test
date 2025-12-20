#ifndef _DYWOQ_TEST_RESULT_HXX
#define _DYWOQ_TEST_RESULT_HXX

#ifdef __cplusplus
#if __cplusplus >= 202002LL

namespace dywoq::test
{
  // Represents the result kind.
  enum class result_kind
  {
    success,
    failure
  };

  // Represents the test case result.
  struct result
  {
    result_kind kind;
    const char *message;
    constexpr result(const char *message, result_kind kind) noexcept
        : message(message), kind(kind)
    {
    }
  };
} // namespace dywoq::test

#endif
#endif

#endif