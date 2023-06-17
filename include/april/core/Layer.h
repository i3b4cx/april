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
#include "core/Scene.h"

namespace april
{
    namespace core
    {
        class Layer
        {
            public:
            Layer()
            {}

            ~Layer()
            {}

            void addScene();
            void destroyScene();
            void processScenes();

            private:
            std::vector<april::core::Scene> m_scenes;
        };
    }  // namespace core
}  // namespace winnebago

#endif  // __APRIL_LAYER_H__
