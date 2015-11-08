# cpplog with timestamp

https://github.com/andrew-d/cpplog with timestamp

## Usage

Make sure you have `cpplog.hpp` in your `#include` search path.

```cpp
// example.cpp
#include "cpplog_timestamp.hpp"

int main(void) {
  cpplog::StdErrLogger log;
  LOG_DEBUG(log) << "this" << " is debug";
  LOG_WARN(log) << "oops";
  return 0;
}
```

Then:
```
$ ./example
2015-11-08 15:11:43 [DEBUG] (example.cpp at line 5) this is debug
2015-11-08 15:11:43 [WARN] (example.cpp at line 6) oops
```
