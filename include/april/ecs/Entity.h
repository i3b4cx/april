// ===============================================================================================
/**
 *   @copyright  April - Copyright (c) 2023 Henry James Purdum
 *   @file       include/april/ecs/Entity.h
 *   @author     Henry Purdum
 *   @date       06/16/2023
 *   @brief      ECS entity impl.
 **/
// ===============================================================================================
/*
---------------------------------------------------------------------------------------------------
Date        | Author   | Description
---------------------------------------------------------------------------------------------------
06/16/2023  | HJP      | Initial Implementation
---------------------------------------------------------------------------------------------------
 */
#ifndef __APRIL_ECS_ENTITY_H__
#define __APRIL_ECS_ENTITY_H__

#include "core/ID.h"
#include "core/Object.h"

namespace april
{
    namespace ecs
    {
        class Entity : public core::Object
        {
            public:
            Entity();
            ~Entity();

            private:
            static core::ID entityId;
        };
    }  // namespace ecs
}  // namespace april

#endif  // __APRIL_ECS_ENTITY_H__
