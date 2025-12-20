#ifndef _DYWOQ_TEST_PRINTER_HXX
#define _DYWOQ_TEST_PRINTER_HXX

#ifdef __cplusplus
#if __cplusplus >= 202002LL
#include "result.hxx"
#include <atomic>
#include <chrono>
#include <iostream>
#include <string>

namespace dywoq::test
{
  // Represents the printer settings.
  struct printer_settings
  {
    std::atomic_bool show_timestamp = false;

    printer_settings() noexcept {}
    printer_settings(const printer_settings &other) noexcept
    {
      show_timestamp.store(other.show_timestamp.load());
    }

    printer_settings &operator=(const printer_settings &other) noexcept
    {
      show_timestamp.store(other.show_timestamp.load());
      return *this;
    }
  };

  // Represents the test results printer.
  class printer
  {
  private:
    std::string result_timestamp_str_() noexcept
    {
      return settings.show_timestamp.load()
                 ? std::format("{:%Y-%m-%d %H:%M:%S} ",
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
      if (result.kind == result_kind::success)
      {
        return "[SUCCESS]";
      }
      return "[FAILURE]";
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

    printer(const printer &other) noexcept = default;

    // Prints the test result into the console,
    // using the printer settings.
    void print(const result &result) noexcept
    {
      std::cout << result_timestamp_str_() << result_kind_str_(result) << " "
                << result_message_str_(result) << " "
                << result_location_str_(result) << std::endl;
    }

    // Prints the test result along with the category name into the console,
    // using the printer settings.
    void print(const std::string &category_name, const result &result) noexcept
    {
      std::cout << "\"" << category_name << "\": " << result_timestamp_str_()
                << result_kind_str_(result) << " "
                << result_message_str_(result) << " "
                << result_location_str_(result) << std::endl;
    }
  };
} // namespace dywoq::test

#endif
#endif

#endif
