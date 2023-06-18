#include "ecs/Component.h"
#include "core/ID.h"
#include "core/Object.h"
#include "ecs/Enums.h"

namespace april
{
    namespace ecs
    {
        core::ID Component::componentId = 0;

        Component::Component()
        {
            m_id = componentId++;
            m_type = enums::COMPONENT;
        }

        Component::~Component()
        {

        }

    }  // namespace ecs
}  // namespace april
