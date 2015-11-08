#include "cpplog_timestamp.hpp"

int main(void) {
  cpplog::StdErrLogger log;
  LOG_DEBUG(log) << "this" << " is debug";
  LOG_WARN(log) << "oops";
  return 0;
}
