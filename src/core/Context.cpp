#include "core/Context.h"
#include <SDL2/SDL_video.h>

namespace winnebago
{
    namespace core
    {
        Context::Context(Window &w)
        {
            SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
            SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
            SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

            SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
            SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
            SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
            SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
            SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

            m_glContext = SDL_GL_CreateContext(w.window());
        }

        Context::~Context()
        {
            SDL_GL_DeleteContext(m_glContext);
        }
    }  // namespace core
}  // namespace winnebago
