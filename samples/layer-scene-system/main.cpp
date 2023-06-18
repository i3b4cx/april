#include <iostream>
#include <exception>
#include "core/Application.h"
#include "core/Layer.h"
#include "core/Scene.h"
#include "systems/RenderSystem.h"

int main()
{
    using Application  = april::core::Application;
    using Layer        = april::core::Layer;
    using Scene        = april::core::Scene;

    try
    {
        Application app;
        app.createWindow();
        app.createContext();

        Layer firstLayer;
        Scene firstScene;
        firstLayer.addScene(firstScene);
        firstLayer.activateScene(firstScene.id());
        app.addLayer(firstLayer);
        app.activateLayer(firstLayer.id());

        app.run();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
