#include "core/Object.h"
#include "ecs/Enums.h"
#include <iostream>

namespace april
{
    namespace core
    {
        ID Object::objectId = 0;

        Object::Object()
            :
                m_id(objectId++),
                m_alive(false),
                m_type(ecs::enums::Enums::OBJECT)
        {
            
        }

        Object::~Object()
        {
            objectId--;
        }

        void Object::init()
        {
            m_alive = true;
        }

        ID Object::id()
        {
            return m_id;
        }

        bool Object::alive()
        {
            return m_alive;
        }

        void Object::kill()
        {
            m_alive = false;
        }

        ecs::enums::Enums Object::ecs()
        {
            return m_type;
        }

        void Object::update()
        {

        }
    }  // namespace core
}  // namespace april
