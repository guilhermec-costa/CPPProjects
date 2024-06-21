#include "window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <cstddef>

namespace gmcc {

const win_states Window::check_win_integrity(const SDL_Window *win) {
  if (win == NULL) {
    return win_states::COULDNT_CREATE_WINDOW;
  }
  return win_states::CREATED;
}

Window::Window()
    : m_window(NULL), m_texture(NULL), m_renderer(NULL), m_buffer(NULL),
      p_title(NULL) {}

Window::Window(const char *title) { p_title = title; }
bool Window::init_window() {
  m_window = SDL_CreateWindow(
              p_title,
              SDL_WINDOWPOS_UNDEFINED,
              SDL_WINDOWPOS_UNDEFINED, 
              WIN_WIDTH, WIN_HEIGHT,
              SDL_WINDOW_SHOWN
  );
  if(!m_window) {
    SDL_Quit();
    return false;
  }
  return true;
}

bool Window::init_renderer() {
  m_renderer =
    SDL_CreateRenderer(this->m_window, -1, SDL_RENDERER_PRESENTVSYNC);
  if(!m_renderer) {
    SDL_DestroyWindow(m_window);
    SDL_Quit();
    return false;
  }
  return true;
}

bool Window::init_texture() {
  m_texture =
      SDL_CreateTexture(
              this->m_renderer,
              SDL_PIXELFORMAT_RGBA8888,
              SDL_TEXTUREACCESS_STATIC, 
              WIN_WIDTH,
              WIN_HEIGHT
    );
  return m_texture ? true : false;
}

bool Window::init() {
  if(!init_window()) {

  };
  if(!init_renderer()) return false;
  if(!init_texture()) return false;
  return true;
}
} // namespace gmcc
