// ===============================================================================================
/**
 *   @copyright  April - Copyright (c) 2023 Henry James Purdum
 *   @file       include/april/util/Logger.h
 *   @author     Henry Purdum
 *   @date       06/16/2023
 *   @brief      Utility for logging and debugging.
 **/
// ===============================================================================================
/*
---------------------------------------------------------------------------------------------------
Date        | Author   | Description
---------------------------------------------------------------------------------------------------
06/16/2023  | HJP      | Initial Implementation
---------------------------------------------------------------------------------------------------
 */
#ifndef __APRIL_UTIL_LOGGER_H__
#define __APRIL_UTIL_LOGGER_H__

#include <fstream>

namespace april
{
    namespace util
    {
        enum LogType
        {
            INFO,       // used to log messages to a local output file
            DEBUG,      // used to log messages to standard output.
            SYSTEM,     // used to log messages to syslog.
            FATAL       // used to log messages to messages that result in program exit.
        };

        class Logger
        {
            public:
            Logger(LogType type);
            Logger(LogType type, std::string filepath);
            ~Logger();

            std::ostream& get();

            private:
            LogType m_type;
            std::fstream m_fs;
        };
    }  // namespace util
}  // namespace april

#endif  // __APRIL_UTIL_LOGGER_H__
