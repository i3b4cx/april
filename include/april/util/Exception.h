// ===============================================================================================
/**
 *   @copyright  April - Copyright (c) 2023 Henry James Purdum
 *   @file       include/april/util/Exception.h
 *   @author     Henry Purdum
 *   @date       06/16/2023
 *   @brief      Utility for custom exception handling.
 **/
// ===============================================================================================
/*
---------------------------------------------------------------------------------------------------
Date        | Author   | Description
---------------------------------------------------------------------------------------------------
06/16/2023  | HJP      | Initial Implementation
---------------------------------------------------------------------------------------------------
 */
#ifndef __APRIL_UTIL_EXCEPTION_H__
#define __APRIL_UTIL_EXCEPTION_H__

#include <exception>
#include <string>

namespace april
{
    namespace util
    {
        class Exception : public std::exception
        {
            public:
            Exception(char *msg);

            char *what();

            private:
            char *m_msg;
        };
    }  // namespace util
}  // namespace april

#endif  // __APRIL_UTIL_EXCEPTION_H__
