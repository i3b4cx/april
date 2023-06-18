#include "ecs/Entity.h"
#include "core/ID.h"
#include "ecs/Enums.h"

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

        }
    }  // namespace ecs
}  // namespace april
