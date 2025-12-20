#ifndef _DYWOQ_TEST_RESULT_HXX
#define _DYWOQ_TEST_RESULT_HXX

#ifdef __cplusplus
#if __cplusplus >= 202002LL
#include <source_location>
#include <string>

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
    std::string message;
    result_kind kind;
    std::source_location location;

    result(std::source_location location) noexcept
        : message(""), kind(result_kind::success), location(location)
    {
    }

    result(const std::string &message,
           const std::source_location &location) noexcept
        : message(message), kind(result_kind::success), location(location)
    {
    }

    result(const std::string &message, result_kind kind,
           const std::source_location &location) noexcept
        : message(message), kind(kind), location(location)
    {
    }

    result(result_kind kind, const std::source_location &location)
        : message(""), kind(kind), location(location)
    {
    }
  };
} // namespace dywoq::test

#endif
#endif

#endif
