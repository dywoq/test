#ifndef _DYWOQ_TEST_PRINTER_HXX
#define _DYWOQ_TEST_PRINTER_HXX

#ifdef __cplusplus
#if __cplusplus >= 202002LL
#include "result.hxx"
#include <atomic>
#include <chrono>
#include <cstring>
#include <iostream>
#include <string>

namespace dywoq::test
{
  // Represents the printer settings.
  // WARNING: You can't change these settings during running tests.
  struct printer_settings
  {
    std::atomic_bool show_timestamp = false;

    constexpr printer_settings() noexcept {}
  };

  // Represents the test results printer.
  class printer
  {
  private:
    std::string result_timestamp_str_() noexcept
    {
      return settings.show_timestamp.load()
                 ? std::format("{:%Y-%m-%d %H:%M:%S}",
                               std::chrono::system_clock::now())
                 : "";
    }

    template <result_kind Kind>
    const char *result_message_str_(const result<Kind> &result) noexcept
    {
      return std::strlen(result.message) == 0 ? "<no message provided>"
                                              : result.message;
    }

    template <result_kind Kind> std::string result_kind_str_() noexcept
    {
      return Kind == result_kind::success ? "[SUCCESS]" : "[FAILURE]";
    }

  public:
    printer_settings settings = {};

    constexpr printer() noexcept {}

    // Prints the test result into the console,
    // using the printer settings.
    template <result_kind Kind> void print(const result<Kind> &result) noexcept
    {
      std::cout << result_timestamp_str_() << " " << result_kind_str_<Kind>()
                << result_message_str_(result) << std::endl;
    }
  };
} // namespace dywoq::test

#endif
#endif

#endif
