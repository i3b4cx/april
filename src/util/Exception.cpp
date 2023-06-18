#include "util/Exception.h"

namespace april
{
    namespace util
    {
        Exception::Exception(char *msg)
            :
                m_msg(msg)
        {
        
        }
        char *Exception::what()
        {
            return m_msg;
        }
    }  // namespace util
}  // namespace april
