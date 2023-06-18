#include "core/Scene.h"
#include "core/ID.h"
#include "ecs/System.h"
#include <memory>

namespace april
{
    namespace core
    {
        ID Scene::idIndex = 0;

        Scene::Scene()
            :
                m_id(idIndex++)
        {
        
        }

        Scene::~Scene()
        {
        
        }

        ID Scene::id()
        {
            return m_id;
        }


        void Scene::update()
        {
            m_registry.update();
        }
    }  // namespace core
}  // namespace april
