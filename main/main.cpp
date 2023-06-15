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

#include <SDL2/SDL_render.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <GL/gl.h>

int main()
{
    std::cout << "Hello World!" << std::endl;
    SDL_GetNumRenderDrivers();
    return 0;
}
