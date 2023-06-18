#include "core/Scene.h"
#include "core/ID.h"

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
            for (ecs::System &s : m_systems)
                s.visit();
        }
    }  // namespace core
}  // namespace april
