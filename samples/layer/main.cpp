#include <iostream>
#include <exception>
#include "core/Application.h"
#include "core/Layer.h"
#include "core/Scene.h"

int main()
{
    using Application = april::core::Application;
    using Layer       = april::core::Layer;
    using Scene       = april::core::Scene;

    try
    {
        Application app;
        app.createWindow();
        app.createContext();

        Layer firstlayer;
        std::cout << firstlayer.id();
        Layer secondLayer;
        std::cout << secondLayer.id();

        Scene firstScene;
        std::cout << firstScene.id();
        Scene secondScene;
        std::cout << secondScene.id();
        
        firstlayer.addScene(firstScene);
        secondLayer.addScene(secondScene);

        app.addLayer(firstlayer);
        app.addLayer(secondLayer);
        
        app.run();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
