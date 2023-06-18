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
#ifndef __APRIL_SCENE_H__
#define __APRIL_SCENE_H__

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
            
            void update();

            private:
            static ID idIndex;
            ID m_id;
            april::core::Registry m_registry;
            april::core::Renderer m_renderer;
        };
    }  // namespace core
}  // namespace winnebago

#endif  // __APRIL_SCENE_H__
