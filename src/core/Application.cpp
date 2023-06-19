#include "core/Application.h"
#include "SDL_video.h"
#include "core/Layer.h"
#include "core/Registry.h"
#include "ecs/Entity.h"
#include "ecs/System.h"
#include "util/Exception.h"

namespace april
{
    namespace core
    {
        Application::Application()
            :
                m_name(""),
                m_x(0),
                m_y(0),
                m_width(640),
                m_height(240),
                m_sdlFlags(SDL_INIT_VIDEO),
                m_windowFlags(SDL_WINDOW_OPENGL),
                m_running(true),
                m_window(nullptr),
                m_context(nullptr)
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
                        return;
                        break;
                    default:
                        break;
                }

                for (Layer &l : m_activeLayers)
                {
                    for (Scene &s : l.activeScenes())
                    {
                        s.update();
                    }
                }

                SDL_GL_SwapWindow(m_window->window());
            }
        }
        
        void Application::quit()
        {
            m_running = false;
            SDL_Quit();
            delete m_context;
            delete m_window;
        }

        ID Application::addLayer(Layer &l)
        {
            m_layers.push_back(l);
            return l.id();
        }

        void Application::removeLayer(ID id)
        {
            for (auto it = m_layers.begin(); it != m_layers.end(); ++it)
            {
                if (it->id() == id)
                    m_layers.erase(it);
            }
        }

        void Application::activateLayer(ID id)
        {
            for (Layer &l : m_layers)
            {
                if (l.id() == id)
                    m_activeLayers.push_back(l);
            }
        }
    }  // namespace core
}  // namespace april
