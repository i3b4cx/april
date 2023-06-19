// ===============================================================================================
/**
 *   @copyright  April - Copyright (c) 2023 Henry James Purdum
 *   @file       include/april/core/Object.h
 *   @author     Henry Purdum
 *   @date       06/16/2023
 *   @brief      Core Object impl.
 **/
// ===============================================================================================
/*
---------------------------------------------------------------------------------------------------
Date        | Author   | Description
---------------------------------------------------------------------------------------------------
06/16/2023  | HJP      | Initial Implementation
---------------------------------------------------------------------------------------------------
 */
#ifndef __APRIL_CORE_OBJECT_H__
#define __APRIL_CORE_OBJECT_H__

#include "core/ID.h"
#include "ecs/Enums.h"
namespace april
{
    namespace core
    {
        class Object
        {
            public:
            Object();
            ~Object();

            void init();
            ID id();
            bool alive();
            void kill();
            ecs::enums::Enums ecs();

            virtual void update();

            protected:
            static ID objectId;
            ID m_id;
            bool m_alive;
            ecs::enums::Enums m_type;
        };
    }  // namespace core
}  // namespace april

#endif  // __APRIL_CORE_OBJECT_H__
