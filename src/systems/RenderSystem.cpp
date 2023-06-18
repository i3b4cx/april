#include "systems/RenderSystem.h"
#include <iostream>

namespace april
{
    namespace systems
    {
        RenderSystem::RenderSystem()
        {
        
        }

        RenderSystem::~RenderSystem()
        {
        
        }

        void RenderSystem::visit()
        {
            std::cout << "SIMPLE RENDER SYSTEM TEST" << std::endl;
        }
    }  // namespace systems
}  // namespace april
