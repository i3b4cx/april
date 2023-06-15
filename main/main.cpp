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

#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include "core/Context.h"
#include "core/Window.h"

int main()
{
    winnebago::core::Window window = winnebago::core::Window("winnebago_test_1", 0, 0, 640, 240, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    winnebago::core::Context context = winnebago::core::Context(window);
    SDL_Event e;
    while(e.type != SDL_QUIT)
    {
        SDL_PollEvent(&e);

        glClearColor(0.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(window.window());
    }
    context.~Context();
    window.~Window();
    SDL_Quit();
    return 0;
}
