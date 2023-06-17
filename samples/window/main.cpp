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
