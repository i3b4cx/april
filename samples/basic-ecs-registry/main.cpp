#include <exception>
#include <iostream>
#include "core/Application.h"
#include "core/ID.h"
#include "core/Layer.h"
#include "core/Registry.h"
#include "core/Scene.h"
#include "ecs/Entity.h"
#include "ecs/System.h"

int main()
{
    using Application  = april::core::Application;
    using Layer        = april::core::Layer;
    using Scene        = april::core::Scene;
    using Registry     = april::core::Registry;

    try
    {
        Application app;
        app.createWindow();
        app.createContext();
        Layer firstLayer;
        Scene firstScene;
        april::core::ID id = Registry::add<april::ecs::Entity>(firstScene.registry());
        april::core::ID id2 = Registry::add<april::ecs::System>(firstScene.registry());
        Registry::remove<april::ecs::Entity>(id, firstScene.registry());
        Registry::remove<april::ecs::System>(id2, firstScene.registry());
        april::core::ID id3 = Registry::add<april::ecs::Entity>(firstScene.registry());
        Registry::remove<april::ecs::Entity>(id3, firstScene.registry());
        std::cout << id << id2 << id3 << std::endl;
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
