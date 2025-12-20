#ifndef _DYWOQ_TEST_RUNNER_HXX
#define _DYWOQ_TEST_RUNNER_HXX

#ifdef __cplusplus
#if __cplusplus >= 202002LL
#include "category.hxx"
#include "printer.hxx"
#include <atomic>
#include <iostream>
#include <vector>

namespace dywoq::test
{
  // Represents the test categories runner.
  class runner
  {
  private:
    std::vector<category> categories_;
    std::atomic_bool working_;
    printer_settings printer_settings_;

  public:
    runner() noexcept {}

    // Adds the category.
    // If the runner is currently working, the function does nothing.
    void add(const category &c) noexcept
    {
      if (working_.load())
      {
        return;
      }
      categories_.push_back(c);
    }

    // Returns the printer settings.
    printer_settings &printer_settings() noexcept { return printer_settings_; }

    int run() noexcept
    {
      if (categories_.empty())
      {
        std::cout << "No test categories to run, skipping (exit code 0)"
                  << std::endl;
        return 0;
      }

      int code = 0;
      for (auto &category : categories_)
      {
        std::cout << "\"" << category.name() << "\": Running tests"
                  << std::endl;
        int given_code = category.run(printer_settings_, 0);
        if (given_code != 0 && code == 0)
        {
          code = 1;
        }
        std::cout << std::endl;
      }

      std::cout << "Finished running test categories (exit code " << code << ")" << std::endl;

      return code;
    }
  };
} // namespace dywoq::test

#endif
#endif

#endif
