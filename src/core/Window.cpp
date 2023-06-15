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

#include "core/Window.h"

namespace winnebago
{
    namespace core
    {
        Window::Window(std::string title, int x, int y, int width, int height, Uint32 flags)
        {
            SDL_Init(SDL_INIT_EVERYTHING);
            m_flags = flags;
            m_window = SDL_CreateWindow(title.c_str(), x, y, width, height, m_flags);
        }

        Window::~Window()
        {
            SDL_DestroyWindow(m_window);
        }

        SDL_Window *Window::window()
        {
            return m_window;
        }
    }
}
