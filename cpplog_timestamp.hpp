#ifndef CPPLOG_TIMESTAMP_HPP_
#define CPPLOG_TIMESTAMP_HPP_

// This define must be before including "cpplog.hpp"
#define LOG_LEVEL(level, logger) cpplog::TimeStampLogMessage(__FILE__, __LINE__, (level), logger).getStream()
#include <cpplog.hpp>
#include <ctime>

namespace cpplog {
class TimeStampLogMessage : public LogMessage {
public:
  TimeStampLogMessage(const char* file,
                   unsigned int line,
                   loglevel_t level,
                   BaseLogger &logger)
  : LogMessage(file, line, level, logger, false) {
    InitLogMessage();
  }
protected:
  virtual void InitLogMessage() {
    char time_string[30];
    this->format_time(m_logData->messageTime, time_string);
    m_logData->stream
      << time_string
      << " [" << this->getLevelName(m_logData->level) << "]"
      << " (" << m_logData->fileName << " at line " << m_logData->line << ") "
    ;
  }
private:
  void format_time(time_t t, char* output) {
    struct tm *tmp;
    tmp = localtime(&t);
    strftime(output, 30, "%Y-%m-%d %H:%M:%S", tmp);
  }
};
};

#endif
