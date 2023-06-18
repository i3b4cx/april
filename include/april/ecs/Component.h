// ===============================================================================================
/**
 *   @copyright  April - Copyright (c) 2023 Henry James Purdum
 *   @file       include/april/ecs/Component.h
 *   @author     Henry Purdum
 *   @date       06/16/2023
 *   @brief      ECS component impl.
 **/
// ===============================================================================================
/*
---------------------------------------------------------------------------------------------------
Date        | Author   | Description
---------------------------------------------------------------------------------------------------
06/16/2023  | HJP      | Initial Implementation
---------------------------------------------------------------------------------------------------
 */
#ifndef __APRIL_ECS_COMPONENT_H__
#define __APRIL_ECS_COMPONENT_H__

#include "core/Object.h"

namespace april
{
    namespace ecs
    {
        class Component : public core::Object
        {
            public:
            Component();
            ~Component();
        };
    }  // namespace ecs
}  // namespace april

#endif  // __APRIL_ECS_COMPONENT_H__
