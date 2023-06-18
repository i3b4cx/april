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

            static std::shared_ptr<ObjectPool<T>> instance()
            {
                if (m_instance  == nullptr)
                    m_instance = std::make_shared<ObjectPool<T>()>();
                return m_instance;
            }

            std::array<T, POOL_SIZE> assets()
            {
                return m_assets;
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
                return -1;
            }

            void remove(ID id)
            {
                for (int i = 0; i < POOL_SIZE; i++)
                {
                    if (m_assets[i].id() == id)
                    {
                        m_assets[i].kill();
                        return;
                    }
                }
            }

            private:
            std::array<T, POOL_SIZE> m_assets;
            static std::shared_ptr<ObjectPool<T>> m_instance;
        };
    }  // namespace core
}  // namespace april

#endif  // __APRIL_CORE_OBJECT_POOL_H__
