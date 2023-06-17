// ===============================================================================================
/**
 *   @copyright  Project - Copyright (c) 2023 Henry James Purdum
 *   @file       samples/window/main.cpp
 *   @author     Henry Purdum
 *   @date       06/16/2023
 *   @brief      Simple proof of concept for core window and context building.
 **/
// ===============================================================================================
/*
---------------------------------------------------------------------------------------------------
Date        | Author   | Description
---------------------------------------------------------------------------------------------------
06/16/2023  | HJP      | Initial Implementation
---------------------------------------------------------------------------------------------------
 */
#include <iostream>
#include <exception>
#include "core/Application.h"

int main()
{
    using Application = winnebago::core::Application;
    try
    {
        Application window_app;
        window_app.createWindow();
        window_app.createContext();
        window_app.run();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
