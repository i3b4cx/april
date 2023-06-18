// ===============================================================================================
/**
 *   @copyright  April - Copyright (c) 2023 Henry James Purdum
 *   @file       include/april/systems/RenderSystem.h
 *   @author     Henry Purdum
 *   @date       06/16/2023
 *   @brief      System for managing render components.
 **/
// ===============================================================================================
/*
---------------------------------------------------------------------------------------------------
Date        | Author   | Description
---------------------------------------------------------------------------------------------------
06/16/2023  | HJP      | Initial Implementation
---------------------------------------------------------------------------------------------------
 */
#ifndef __APRIL_SYSTEMS_RENDER_SYSTEM_H__
#define __APRIL_SYSTEMS_RENDER_SYSTEM_H__

#include "ecs/System.h"

namespace april
{
    namespace systems
    {
        class RenderSystem : public ecs::System
        {
            public:
            RenderSystem();
            ~RenderSystem();

            void visit();
        };
    }  // namespace systems
}  // namespace april

#endif  // __APRIL_SYSTEMS_RENDER_SYSTEM_H__
