#ifndef _DYWOQ_TEST_CATEGORY_HXX
#define _DYWOQ_TEST_CATEGORY_HXX

#ifdef __cplusplus
#if __cplusplus >= 202002LL
#include "function_t.hxx"
#include "info.hxx"
#include "printer.hxx"
#include <atomic>
#include <string>
#include <vector>

namespace dywoq::test
{
  // Represents the tests category.
  class category
  {
  private:
    std::string name_;
    std::vector<function_t> tests_;
    std::atomic_bool working_;

    info info_ = {};
    printer printer_ = {};

  public:
    category(const std::string &name) noexcept : name_(name) {}

    // Adds the test to the category.
    // If the category is currently working, the function does nothing.
    void add(const function_t &test) noexcept
    {
      if (working_.load())
      {
        return;
      }
      tests_.push_back(test);
    }

    // Runs the tests categories, reporting any test results
    // into the console.
    // Depending on the result of tests, `run` returns either 0 as success or 1
    // as failure.
    int run() noexcept
    {

      working_.store(true);
      int code = 0;
      for (auto &test : tests_)
      {
        auto result = test();
        printer_.print(name_, result);
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
        std::cout << name_ << ": Detected" << info_.failures_count.load()
                  << " failures, returning code 1" << std::endl;
      }
      else
      {
        std::cout << name_ << ": No failures detected" << std::endl;
      }
      return code;
    }
  };
} // namespace dywoq::test

#endif
#endif

#endif
