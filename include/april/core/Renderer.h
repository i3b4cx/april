// ===============================================================================================
/**
 *   @copyright  April - Copyright (c) 2023 Henry James Purdum
 *   @file       include/april/core/Renderer.h
 *   @author     Henry Purdum
 *   @date       06/16/2023
 *   @brief      Core renderer impl.
 **/
// ===============================================================================================
/*
---------------------------------------------------------------------------------------------------
Date        | Author   | Description
---------------------------------------------------------------------------------------------------
06/16/2023  | HJP      | Initial Implementation
---------------------------------------------------------------------------------------------------
 */
#ifndef __APRIL_CORE_RENDERER_H__
#define __APRIL_CORE_RENDERER_H__

#include "graphics/RenderStrategy.h"
#include "graphics/RenderImpl.h"
#include "graphics/RenderTarget.h"

namespace april
{
    namespace core
    {
        class Renderer
        {
            public:
            Renderer()
            {}

            ~Renderer()
            {}

            private:
            april::graphics::RenderStrategy m_strategy;
            april::graphics::RenderImpl m_impl;
            april::graphics::RenderTarget m_target;
        };
    }  // namespace core
}  // namespace april

#endif  // __APRIL_CORE_RENDERER_H__
