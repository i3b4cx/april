#include <iostream>
#include <exception>
#include "core/Application.h"

int main()
{
    using Application = april::core::Application;
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
