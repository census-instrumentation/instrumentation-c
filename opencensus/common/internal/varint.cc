// Copyright 2019, OpenCensus Authors
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

#include <cstdint>
#include <string>

#include "absl/strings/string_view.h"
#include "opencensus/common/internal/varint.h"

namespace opencensus {
namespace common {

void AppendVarint(unsigned int i, std::string* out) {
  do {
    // Encode 7 bits.
    uint8_t c = i & 0x7F;
    i = i >> 7;
    if (i != 0) {
      c |= 0x80;
    }
    out->push_back(c);
  } while (i != 0);
}

bool ParseVarint(absl::string_view* input, int* out) {
  absl::string_view s = *input;
  int i = 0;
  uint8_t c;
  do {
    if (s.empty()) {
      return false;  // Too short.
    }
    c = s[0];
    s = s.substr(1);
    i = (i << 7) | (c & 0x7F);
  } while (c & 0x80);
  *input = s;
  *out = i;
  return true;
}

}  // namespace common
}  // namespace opencensus
