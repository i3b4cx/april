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
#ifndef __WINNEBAGO_APPLICATION_H__
#define __WINNEBAGO_APPLICATION_H__

#include "SDL_video.h"
#include "SDL_events.h"
#include "core/Window.h"
#include "core/Context.h"

namespace winnebago
{
    namespace core
    {
        class Application
        {
            public:
            Application();
            ~Application();
            const Application &name(std::string name);
            const Application &x(int x);
            const Application &y(int y);
            const Application &width(int width);
            const Application &height(int height);
            const Application &sdlFlags(Uint32 flags);
            const Application &windowFlags(Uint32 flags);
            void init();
            void createWindow();
            void createContext();
            void run();
            void quit();

            private:
            Window *m_window;
            Context *m_context;
            std::string m_name;
            int m_x;
            int m_y;
            int m_width;
            int m_height;
            Uint32 m_sdlFlags;
            Uint32 m_windowFlags;
            bool m_running;
        };
    }  // namespace core
}  // namespace winnebago

#endif  // __WINNEBAGO_APPLICATION_H__