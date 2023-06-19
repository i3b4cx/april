// ===============================================================================================
/**
 *   @copyright  April - Copyright (c) 2023 Henry James Purdum
 *   @file       include/april/core/Registry.h
 *   @author     Henry Purdum
 *   @date       06/16/2023
 *   @brief      Core registry impl.
 **/
// ===============================================================================================
/*
---------------------------------------------------------------------------------------------------
Date        | Author   | Description
---------------------------------------------------------------------------------------------------
06/16/2023  | HJP      | Initial Implementation
---------------------------------------------------------------------------------------------------
 */
#ifndef __APRIL_CORE_REGISTRY_H__
#define __APRIL_CORE_REGISTRY_H__

#include "core/ID.h"
#include "core/Object.h"
#include "core/ObjectPool.h"
#include "ecs/Component.h"
#include "ecs/Entity.h"
#include "ecs/Enums.h"
#include "ecs/System.h"
#include "util/Exception.h"
#include <exception>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

namespace april
{
    namespace core
    {
        class Registry
        {
            public:
            Registry()
            {
            
            }

            ~Registry()
            {

            }

            template<typename T>
            static ID add(Registry &reg)
            {
                return reg.add<T>();
            }

            template<typename T>
            static void remove(int id, Registry &reg)
            {
                reg.remove<T>(id);
            }

            template<typename T>
            static T &find(int id, Registry &reg)
            {
                return reg.find<T>(id);
            }

            template<typename T>
            static void findOrInsert(int id, Registry &reg)
            {
                reg.findOrInsert<T>(id);
            }

            template<typename T>
            static void update(Registry &reg)
            {
                reg.update<T>();
            }

            private:
            template<typename T>
            ID add()
            {
                // HJP: create components and object derivative types in our scene.
                // create our typed object
                // typed objects will inheirit from one of the ecs classes and will all implement this ecs() function
                // this will tell us what kind of object we are dealing with.
                T object;
                switch (object.ecs())
                {
                    case ecs::enums::ENTITY:
                        return m_entities.create();
                        break;
                    case ecs::enums::COMPONENT:
                        return m_components.create();
                        break;
                    case ecs::enums::SYSTEM:
                        return m_systems.create();
                        break;
                    default:
                        char *msg = (char *)"ERROR: tried to create template object with invalid ecs enum.";
                        throw util::Exception(msg);
                }
                return object.id();
            }

            template<typename T>
            void remove(int id)
            {
                // HJP: remove for components and object derivative types in our scene.
                T object;
                switch (object.ecs())
                {
                    case ecs::enums::ENTITY:
                        m_entities.destroy(id);
                        break;
                    case ecs::enums::COMPONENT:
                        m_components.destroy(id);
                        break;
                    case ecs::enums::SYSTEM:
                        m_systems.destroy(id);
                        break;
                    default:
                        char *msg = (char *)"ERROR: tried to remove template object with invalid ecs enum.";
                        throw util::Exception(msg);
                }
            }

            template<typename T>
            T &find(int id)
            {
                // HJP: scene based lookup.
                T object;
                switch (object.ecs())
                {
                    case ecs::enums::ENTITY:
                        return m_entities.find(id);
                        break;
                    case ecs::enums::COMPONENT:
                        return m_components.find(id);
                        break;
                    case ecs::enums::SYSTEM:
                        return m_systems.find(id);
                        break;
                    default:
                        char *msg = (char *)"ERROR: tried to find template object with invalid ecs enum.";
                        throw util::Exception(msg);
                }
            }

            template<typename T>
            T &findOrInsert(int id)
            {
                // HJP: scene based lookup with an add builtin.
                T object;
                switch (object.ecs())
                {
                    case ecs::enums::ENTITY:
                        return m_entities.findOrInsert(id);
                        break;
                    case ecs::enums::COMPONENT:
                        return m_components.findOrInsert(id);
                        break;
                    case ecs::enums::SYSTEM:
                        return m_systems.findOrInsert(id);
                        break;
                    default:
                        char *msg = (char *)"ERROR: tried to findOrInsert template object with invalid ecs enum.";
                        throw util::Exception(msg);
                }
            }

            template<typename T>
            void update()
            {
                T object;
                object.update();
            }

            private:
            ObjectPool<ecs::Entity> m_entities;
            ObjectPool<ecs::Component> m_components;
            ObjectPool<ecs::System> m_systems;
        };
    }  // namespace core
}  // namespace winnebago

#endif  // __APRIL_CORE_REGISTRY_H__
