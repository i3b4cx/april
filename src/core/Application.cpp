#include "core/Application.h"
#include "SDL_video.h"

namespace april
{
    namespace core
    {
        Application::Application()
            :
                m_window(nullptr),
                m_context(nullptr),
                m_name(""),
                m_x(0),
                m_y(0),
                m_width(640),
                m_height(240),
                m_sdlFlags(SDL_INIT_VIDEO),
                m_windowFlags(SDL_WINDOW_OPENGL),
                m_running(true)
        {
            init();
        }

        Application::~Application()
        {
            quit();
        }
        
        const Application &Application::name(std::string name)
        {
            m_name = name;
            return *this;
        }
        
        const Application &Application::x(int x)
        {
            m_x = x;
            return *this;
        }
        
        const Application &Application::y(int y)
        {
            m_y = y;
            return *this;
        }
        
        const Application &Application::width(int width)
        {
            m_width = width;
            return *this;
        }
        
        const Application &Application::height(int height)
        {
            m_height = height;
            return *this;
        }
        
        const Application &Application::sdlFlags(Uint32 flags)
        {
            m_sdlFlags = flags;
            return *this;
        }
        
        const Application &Application::windowFlags(Uint32 flags)
        {
            m_windowFlags = flags;
            return *this;
        }
        
        void Application::init()
        {
            SDL_Init(m_sdlFlags);
        }
        
        void Application::createWindow()
        {
            if (m_window == nullptr)
                m_window = new Window(m_name, m_x, m_y, m_width, m_height, m_windowFlags);
        }
        
        void Application::createContext()
        {
            if (m_window == nullptr)
                createWindow();
            if (m_context == nullptr)
                m_context = new Context(*m_window);
        }
        
        void Application::run()
        {
            SDL_Event e;
            while(m_running)
            {
                SDL_PollEvent(&e);
                switch(e.type)
                {
                    case SDL_QUIT:
                        quit();
                        break;
                    default:
                        break;
                }

                // HJP: update loop here

                // HJP: render loop here

                SDL_GL_SwapWindow(m_window->window());
            }
        }
        
        void Application::quit()
        {
            m_running = false;
            delete m_context;
            delete m_window;
            SDL_Quit();
        }   
    }  // namespace core
}  // namespace april
