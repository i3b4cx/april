// ===============================================================================================
/**
 *   @copyright  April - Copyright (c) 2023 Henry James Purdum
 *   @file       include/april/core/Context.h
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
#ifndef __APRIL_CORE_CONTEXT_H__
#define __APRIL_CORE_CONTEXT_H__

#include <SDL2/SDL.h>
#include "core/Window.h"

namespace april
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
    }  // namespace core
}  // namespace april

#endif  // __APRIL_CORE_CONTEXT_H__
