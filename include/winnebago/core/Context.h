// ===============================================================================================
/**
 *   @copyright  Project - Copyright (c) 2023 Henry James Purdum
 *   @file       include/winnebago/core/Context.h
 *   @author     Henry Purdum
 *   @date       06/16/2023
 *   @brief      Core context impl.
 **/
// ===============================================================================================
/*
---------------------------------------------------------------------------------------------------
Date        | Author   | Description
---------------------------------------------------------------------------------------------------
06/16/2023  | HJP      | Initial Implementation
---------------------------------------------------------------------------------------------------
 */
#ifndef __WINNEBAGO_CONTEXT_H__
#define __WINNEBAGO_CONTEXT_H__

#include <SDL2/SDL.h>
#include "core/Window.h"

namespace winnebago
{
    namespace core
    {
        class Context
        {
            public:
            Context(Window &w);

            ~Context();

            private:
            SDL_GLContext m_glContext;
        };
    }
}

#endif  // __WINNEBAGO_CONTEXT_H__
