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

#ifndef _DYWOQ_TEST_INFO_HXX
#define _DYWOQ_TEST_INFO_HXX

#ifdef __cplusplus

#  if __cplusplus >= 202002LL
#include <atomic>

namespace dywoq::test {
inline namespace __v1 {
// Contains the information that is collected during tests
// and available after running them.
struct info {
  std::atomic_bool has_failures = false;
  std::atomic_uint32_t failures_count = 0;

  info() noexcept = default;
};
}
} // namespace dywoq::test

#  endif
#endif

#endif
