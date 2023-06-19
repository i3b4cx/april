// ===============================================================================================
/**
 *   @copyright  April - Copyright (c) 2023 Henry James Purdum
 *   @file       include/april/core/ObjectPool.h
 *   @author     Henry Purdum
 *   @date       06/16/2023
 *   @brief      Core ObjectPool impl.
 **/
// ===============================================================================================
/*
---------------------------------------------------------------------------------------------------
Date        | Author   | Description
---------------------------------------------------------------------------------------------------
06/16/2023  | HJP      | Initial Implementation
---------------------------------------------------------------------------------------------------
 */
#ifndef __APRIL_CORE_OBJECT_POOL_H__
#define __APRIL_CORE_OBJECT_POOL_H__

#include "core/ID.h"
#include "util/Exception.h"
#include <array>
#include <memory>

namespace april
{
    namespace core
    {
        template<typename T>
        class ObjectPool
        {
            private:
            static const int POOL_SIZE = 25;

            public:
            ObjectPool()
            {
            
            }

            ~ObjectPool()
            {

            }

            template<typename ...Args>
            ID create(Args &&...args)
            {
                for (T &asset : m_assets)
                {
                    if (!asset.alive())
                    {
                        asset.init(std::forward<Args>(args)...);
                        return asset.id();
                    }
                }
                char *msg = (char *)"ERROR: tried to create new object, but pool was full.";
                throw util::Exception(msg);
            }

            void destroy(ID id)
            {
                for (T &asset : m_assets)
                {
                    if (asset.id() == id)
                    {
                        asset.kill();
                        return;
                    }
                }
            }

            T &find(ID id)
            {
               for (T &asset : m_assets)
                {
                    if (asset.id() == id)
                    {
                        return asset;
                    }
                }
               char *msg = (char *)"ERROR: tried to find new object, but pool was full.";
               throw util::Exception(msg);
            }

            T &findOrInsert(ID id)
            {
               for (T &asset : m_assets)
                {
                    if (asset.id() == id)
                    {
                        return asset;
                    }
                }
               T object;
               return object;
            }

            private:
            std::array<T, POOL_SIZE> m_assets;
        };
    }  // namespace core
}  // namespace april

#endif  // __APRIL_CORE_OBJECT_POOL_H__
