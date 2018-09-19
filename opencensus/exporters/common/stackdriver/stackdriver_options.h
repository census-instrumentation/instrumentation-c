// Copyright 2018, OpenCensus Authors
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

#ifndef OPENCENSUS_EXPORTERS_COMMON_STACKDRIVER_STACKDRIVER_OPTIONS_H_
#define OPENCENSUS_EXPORTERS_COMMON_STACKDRIVER_STACKDRIVER_OPTIONS_H_

#include <string>

namespace opencensus {
namespace exporters {
namespace common {

struct StackdriverOptions {
  // The Stackdriver project ID to use.
  std::string project_id;

  // Used by the stats exporter, the opencensus_task is used to uniquely
  // identify the task in Stackdriver. The recommended format is
  // "{LANGUAGE}-{PID}@{HOSTNAME}". If PID is not available, a random number may
  // be used.
  std::string opencensus_task;
};

}  // namespace common
}  // namespace exporters
}  // namespace opencensus

#endif  // OPENCENSUS_EXPORTERS_COMMON_STACKDRIVER_STACKDRIVER_OPTIONS_H_
