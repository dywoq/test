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
  template <result_kind Kind> struct result
  {
    const char *message;
    constexpr result(const char *message) noexcept : message(message) {}
    constexpr result_kind kind() noexcept { return Kind; }
  };
} // namespace dywoq::test

#endif
#endif

#endif