#include "core/Layer.h"
#include "core/Scene.h"

namespace april
{
    namespace core
    {
        ID Layer::idIndex = 0;

        Layer::Layer()
            :
                m_id(idIndex++)
        {

        }

        Layer::~Layer()
        {
        }
        
        ID Layer::id()
        {
            return m_id;
        }

        ID Layer::addScene(Scene &s)
        {
            m_scenes.push_back(s);
            return s.id();
        }

        void Layer::removeScene(ID id)
        {
            for (auto it = m_scenes.begin(); it != m_scenes.end(); ++it)
            {
                if (it->id() == id)
                    m_scenes.erase(it);
            }
        }

        void Layer::activateScene(ID id)
        {
            for (Scene &s : m_scenes)
            {
                if (s.id() == id)
                    m_activeScenes.push_back(s);
            }
        }

        std::vector<Scene> Layer::activeScenes()
        {
            return m_activeScenes;
        }
    }  // namespace core
}  // namespace april
