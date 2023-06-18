#include "core/Object.h"

namespace april
{
    namespace core
    {
        Object::Object()
        {

        }

        Object::~Object()
        {

        }

        ID Object::id()
        {
            return m_id;
        }

        bool Object::alive()
        {
            return m_alive;
        }
    }  // namespace core
}  // namespace april
