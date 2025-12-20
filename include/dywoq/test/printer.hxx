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
                 ? std::format("{:%Y-%m-%d %H:%M:%MS} ",
                               std::chrono::system_clock::now())
                 : "";
    }

    std::string result_message_str_(const result &result) noexcept
    {
      return result.message.size() == 0 ? "<no message provided>"
                                              : result.message;
    }

    std::string result_kind_str_(const result &result) noexcept
    {
      return result.kind == result_kind::success ? "[SUCCESS]" : "[FAILURE]";
    }

    std::string result_location_str_(const result &result) noexcept
    {
      auto location = result.location;
      return std::format("({} {}:{}:{})", location.function_name(),
                         location.file_name(), location.line(),
                         location.column());
    }

  public:
    printer_settings settings = {};

    printer() noexcept {}

    // Prints the test result into the console,
    // using the printer settings.
    void print(const result &result) noexcept
    {
      std::cout << result_timestamp_str_() << result_kind_str_(result) << " "
                << result_message_str_(result) << " " << result_location_str_(result) << std::endl;
    }
  };
} // namespace dywoq::test

#endif
#endif

#endif
