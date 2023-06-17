// ===============================================================================================
/**
 *   @copyright  Project - Copyright (c) 2023 Henry James Purdum
 *   @file       include/winnebago/core/Window.h
 *   @author     Henry Purdum
 *   @date       06/16/2023
 *   @brief      Core window impl.
 **/
// ===============================================================================================
/*
---------------------------------------------------------------------------------------------------
Date        | Author   | Description
---------------------------------------------------------------------------------------------------
06/16/2023  | HJP      | Initial Implementation
---------------------------------------------------------------------------------------------------
 */
#ifndef __WINNEBAGO_WINDOW_H__
#define __WINNEBAGO_WINDOW_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_video.h>
#include <string>

namespace winnebago
{
    namespace core
    {
        class Window
        {
            public:
            Window(std::string name, int x, int y, int width, int height, Uint32 flags);

            SDL_Window *window();

            ~Window();

            private:
            SDL_Window *m_window;
        };
    }
}

#endif  // __WINNEBAGO_WINDOW_H__
