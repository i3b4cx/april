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
#ifndef __APRIL_REGISTRY_H__
#define __APRIL_REGISTRY_H__

#include <vector>

namespace april
{
    namespace core
    {
        class Registry
        {
            public:
            Registry()
            {}

            ~Registry()
            {}
            
            // HJP: going to need to add on ObjectID type for readability.
            template<typename T>
            static void add(int id, Registry &reg)
            {
                // HJP: this requires a templatable object pool management system.
            }

            template<typename T>
            static void remove(int id, Registry &reg)
            {
                // HJP: this requires a templatable object pool management system.
            }

            template<typename T>
            static void getOrInsert(int id, Registry &reg)
            {
                // HJP: this requires a templatable object pool management system.
            }

            template<typename T>
            static void createEntity();

            template<typename T>
            static void destroyEntity();

            private:
            // asset reference table
            // templated map of object type -> corresponding object pool
        };
    }  // namespace core
}  // namespace winnebago

#endif  // __APRIL_REGISTRY_H__
