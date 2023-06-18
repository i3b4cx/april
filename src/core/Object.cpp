#include "core/Object.h"
#include "ecs/Enums.h"

namespace april
{
    namespace core
    {
        ID Object::idIndex = 0;

        Object::Object()
            :
                m_alive(false),
                m_id(idIndex++),
                m_type(ecs::enums::Enums::OBJECT)
        {
            
        }

        Object::~Object()
        {

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
    }  // namespace core
}  // namespace april
