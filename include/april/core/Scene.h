// ===============================================================================================
/**
 *   @copyright  April - Copyright (c) 2023 Henry James Purdum
 *   @file       include/april/core/Scene.h
 *   @author     Henry Purdum
 *   @date       06/16/2023
 *   @brief      Core scene impl.
 **/
// ===============================================================================================
/*
---------------------------------------------------------------------------------------------------
Date        | Author   | Description
---------------------------------------------------------------------------------------------------
06/16/2023  | HJP      | Initial Implementation
---------------------------------------------------------------------------------------------------
 */
#ifndef __APRIL_CORE_SCENE_H__
#define __APRIL_CORE_SCENE_H__

#include "core/ID.h"
#include "core/Registry.h"
#include "core/Renderer.h"
#include "ecs/System.h"
#include <memory>

namespace april
{
    namespace core
    {
        class Scene
        {
            public:
            Scene();

            ~Scene();
            
            ID id();
            Registry &registry();
            
            void update();

            private:
            static ID idIndex;
            ID m_id;
            Registry m_registry;
            Renderer m_renderer;
        };
    }  // namespace core
}  // namespace winnebago

#endif  // __APRIL_CORE_SCENE_H__
