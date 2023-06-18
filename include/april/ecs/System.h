// ===============================================================================================
/**
 *   @copyright  April - Copyright (c) 2023 Henry James Purdum
 *   @file       include/april/ecs/System.h
 *   @author     Henry Purdum
 *   @date       06/16/2023
 *   @brief      ECS system impl.
 **/
// ===============================================================================================
/*
---------------------------------------------------------------------------------------------------
Date        | Author   | Description
---------------------------------------------------------------------------------------------------
06/16/2023  | HJP      | Initial Implementation
---------------------------------------------------------------------------------------------------
 */
#ifndef __APRIL_ECS_SYSTEM_H__
#define __APRIL_ECS_SYSTEM_H__

#include "core/Object.h"

namespace april
{
    namespace ecs
    {
        class System : public core::Object
        {
            public:
            System();
            ~System();
            virtual void visit();
            
            private:

        };
    }  // namespace ecs
}  // namespace april

#endif  // __APRIL_ECS_SYSTEM_H__
