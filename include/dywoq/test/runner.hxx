#ifndef _DYWOQ_TEST_RUNNER_HXX
#define _DYWOQ_TEST_RUNNER_HXX

#ifdef __cplusplus
#if __cplusplus >= 202002LL
#include "function_t.hxx"
#include "info.hxx"
#include "printer.hxx"
#include "result.hxx"
#include <atomic>
#include <iostream>
#include <vector>

namespace dywoq::test
{
  // Represents the test runner.
  class runner
  {
  private:
    std::vector<function_t> tests_;
    std::atomic_bool working_;
    info info_;
    printer printer_;

  public:
   runner() noexcept {}

    // Adds new test function.
    // In a case the test runner is currently working, the function does
    // nothing.
    void add(function_t test) noexcept
    {
      if (working_.load())
      {
        return;
      }
      tests_.push_back(test);
    }

    // Returns the printer settings.
    printer_settings &printer_settings() noexcept { return printer_.settings; }

    // Returns the info that's collected during running tests.
    info &info() noexcept { return info_; }

    // Turns on working flag, and begins running added tests synchronously,
    // printing their result into the console.
    // Depending on the result of tests, `run` returns either 0 as success or 1
    // as failure.
    int run() noexcept
    {
      working_.store(true);
      int code = 0;
      for (auto &test : tests_)
      {
        auto result = test();
        printer_.print(result);
        if (result.kind == result_kind::failure)
        {
          info_.has_failures = true;
          info_.failures_count.store(info_.failures_count.load() + 1);
          code = 1;
        }
      }
      working_.store(false);

      if (info_.has_failures)
      {
        std::cout << "Detected failures, returning code 1 [Amount: "
                  << info_.failures_count.load() << "]" << std::endl;
      }

      return code;
    }
  };
} // namespace dywoq::test

#endif
#endif

#endif
