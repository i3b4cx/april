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

            void update();
            
            // HJP: going to need to add on ObjectID type for readability.
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
            static void getOrInsert(int id, Registry &reg)
            {
                reg.getOrInsert<T>(id);
            }

            template<typename T>
            static void find(int id, Registry &reg)
            {
                reg.find<T>(id);
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
                switch(object.ecs())
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
                switch(object.ecs())
                {
                    case ecs::enums::ENTITY:
                        m_entities.remove(id);
                        break;
                    case ecs::enums::COMPONENT:
                        m_components.remove(id);
                        break;
                    case ecs::enums::SYSTEM:
                        m_systems.remove(id);
                        break;
                    default:
                        char *msg = (char *)"ERROR: tried to remove template object with invalid ecs enum.";
                        throw util::Exception(msg);
                }
            }

            template<typename T>
            void getOrInsert(int id)
            {
                // HJP: scene based lookup with an add builtin.
            }

            template<typename T>
            void find(int id)
            {
                // HJP: scene based lookup.
            }

            void createEntity()
            {
                // HJP: create an entity in our scene.
                //m_entities[m_entityId++].create();
            }

            void destroyEntity(ID entityID)
            {
                // HJP: destroy an entity in our scene.
            }

            void createComponent()
            {
                // HJP: create an entity in our scene.
                //m_components[m_componentId++].create();
            }

            void destroyComponent()
            {
                // HJP: destroy an entity in our scene.
            }

            void createSystem()
            {
                // HJP: create an entity in our scene.
                //m_systems[m_systemId++].create();
            }

            void destroySystem()
            {
                // HJP: destroy an entity in our scene.
            }

            private:
            // map: asset reference id -> asset object pools
            ObjectPool<ecs::Entity> m_entities;
            ObjectPool<ecs::Component> m_components;
            ObjectPool<ecs::System> m_systems;
        };
    }  // namespace core
}  // namespace winnebago

#endif  // __APRIL_CORE_REGISTRY_H__
