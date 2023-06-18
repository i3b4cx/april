// ===============================================================================================
/**
 *   @copyright  April - Copyright (c) 2023 Henry James Purdum
 *   @file       include/april/core/Object.h
 *   @author     Henry Purdum
 *   @date       06/16/2023
 *   @brief      Core Object impl.
 **/
// ===============================================================================================
/*
---------------------------------------------------------------------------------------------------
Date        | Author   | Description
---------------------------------------------------------------------------------------------------
06/16/2023  | HJP      | Initial Implementation
---------------------------------------------------------------------------------------------------
 */
#ifndef __APRIL_CORE_OBJECT_H__
#define __APRIL_CORE_OBJECT_H__

#include "core/ID.h"
namespace april
{
    namespace core
    {
        class Object
        {
            public:
            Object();
            ~Object();

            ID id();
            bool alive();

            private:
            ID m_id;
            bool m_alive;
        };
    }  // namespace core
}  // namespace april

#endif  // __APRIL_CORE_OBJECT_H__
