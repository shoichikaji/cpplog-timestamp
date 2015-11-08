/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Shoichi Kaji
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
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
