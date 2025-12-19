// Copyright 2025 dywoq
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _DYWOQ_TEST_RESULT_HXX
#define _DYWOQ_TEST_RESULT_HXX

#ifdef __cplusplus
#if __cplusplus >= 202002LL
#include <cstdint>
#include <string>

namespace dywoq::test {
  inline namespace __v1 {

    // Represents the result kind.
    enum class result_kind : std::int8_t { error, success };

    // Represents the test case result params.
    struct result_params {
      std::string message;
    };

    // Represents the test case result.
    // During initializing, take a note that default constructor
    // automatically sets the result kind to `result_kind::success`.
    class result {
    private:
      result_params params_;
      result_kind kind_;

    public:
      result() noexcept : params_({}), kind_(result_kind::success) {}
      result(result_params params, result_kind kind) noexcept : params_(params) {}
      [[nodiscard]] constexpr result_kind kind() noexcept { return kind_; }
      [[nodiscard]] const result_params &params() noexcept { return params_; }
    };

  } // namespace __v1
} // namespace dywoq::test

#endif
#endif

#endif
