#include "ecs/Component.h"
#include "core/ID.h"
#include "core/Object.h"
#include "ecs/Enums.h"
#include <iostream>

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
            componentId--;
        }
        
        void Component::update()
        {

        }
    }  // namespace ecs
}  // namespace april
