#include "ecs/System.h"
#include "core/ID.h"
#include "ecs/Enums.h"

namespace april
{
    namespace ecs
    {
        core::ID System::systemId = 0;

        System::System()
        {
            m_id = systemId++;
            m_type = enums::SYSTEM;
        }

        System::~System()
        {

        }
    }  // namespace ecs
}  // namespace april
