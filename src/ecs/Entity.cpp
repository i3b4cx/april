#include "ecs/Entity.h"
#include "core/ID.h"
#include "ecs/Enums.h"
#include <iostream>

namespace april
{
    namespace ecs
    {
        core::ID Entity::entityId = 0;

        Entity::Entity()
        {
            m_id = entityId++;
            m_type = enums::ENTITY;
        }

        Entity::~Entity()
        {
            entityId--;
        }

        void Entity::update()
        {

        }
    }  // namespace ecs
}  // namespace april
