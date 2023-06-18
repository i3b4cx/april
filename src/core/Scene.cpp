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
            for (std::shared_ptr<ecs::System> s : m_systems)
            {
                s->visit();
            }
        }
    }  // namespace core
}  // namespace april
