// ===============================================================================================
/**
 *   @copyright  April - Copyright (c) 2023 Henry James Purdum
 *   @file       include/april/core/Layer.h
 *   @author     Henry Purdum
 *   @date       06/16/2023
 *   @brief      Core layer impl.
 **/
// ===============================================================================================
/*
---------------------------------------------------------------------------------------------------
Date        | Author   | Description
---------------------------------------------------------------------------------------------------
06/16/2023  | HJP      | Initial Implementation
---------------------------------------------------------------------------------------------------
 */
#ifndef __APRIL_LAYER_H__
#define __APRIL_LAYER_H__

#include <vector>
#include "core/ID.h"
#include "core/Scene.h"

namespace april
{
    namespace core
    {
        class Layer
        {
            public:
            Layer();

            ~Layer();
            
            ID id();
            ID addScene(Scene &s);
            void removeScene(ID id);
            void activateScene(ID id);

            std::vector<Scene> activeScenes();

            private:
            static ID idIndex;
            ID m_id;
            std::vector<Scene> m_scenes;
            std::vector<Scene> m_activeScenes;
        };
    }  // namespace core
}  // namespace winnebago

#endif  // __APRIL_LAYER_H__
