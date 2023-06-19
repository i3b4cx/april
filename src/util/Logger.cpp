#include "util/Logger.h"
#include "util/Exception.h"
#include <iostream>
#include <sstream>

namespace april
{
    namespace util
    {
        Logger::Logger(LogType type)
            :
                m_type(type)
        {
            switch (type)
            {
                case LogType::DEBUG:
                    break;
                case LogType::SYSTEM:
                    m_fs.open("/var/log/syslog");
                    break;
                case LogType::FATAL:
                    break;
                default:
                    char *msg = (char *)"ERROR: failed to create logger.";
                    throw Exception(msg);
            }
        }

        Logger::Logger(LogType type, std::string filepath)
            :
                m_type(type)
        {
            switch (type)
            {
                case LogType::INFO:
                    m_fs.open(filepath);
                    break;
                case LogType::SYSTEM:
                    m_fs.open(filepath);
                    break;
                default:
                    char *msg = (char *)"ERROR: failed to create logger.";
                    throw Exception(msg);
            } 
        }

        std::ostream& Logger::get()
        {
            if (m_type == DEBUG || m_type == FATAL)
                return std::cout;
            else
                return m_fs;
        }
    }  // namespace util
}  // namespace april
