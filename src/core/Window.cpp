#include "core/Window.h"

namespace april
{
    namespace core
    {
        Window::Window(std::string title, int x, int y, int width, int height, Uint32 flags)
        {
            m_window = SDL_CreateWindow(title.c_str(), x, y, width, height, flags);
        }

        Window::~Window()
        {
            SDL_DestroyWindow(m_window);
        }

        SDL_Window *Window::window()
        {
            return m_window;
        }
    }  // namespace core
}  // namespace april
