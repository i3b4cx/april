// ===============================================================================================
/**
 *   @copyright Project - Copyright (c) 2023 Henry Purdum, Inc.
 *   @file       main/main.cpp
 *   @author     Henry Purdum
 *   @date       06/01/2023
 *   @brief      A brief template file
 *   @remarks    A brief template file
 **/
// ===============================================================================================
/*
---------------------------------------------------------------------------------------------------
Date        | Author   | Description
---------------------------------------------------------------------------------------------------
00/00/0000  | HJP      | Initial Implementation
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