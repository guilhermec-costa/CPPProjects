#ifndef WINDOW_H_
#define WINDOW_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

namespace gmcc {

enum win_states { COULDNT_CREATE_WINDOW, CREATED };

class Window {
private:
  SDL_Window *m_window;
  SDL_Renderer *m_renderer;
  SDL_Texture *m_texture;
  Uint32 *m_buffer;
  const char *p_title;

private:
  bool init_window();
  bool init_renderer();
  bool init_texture();

public:
  const static int WIN_WIDTH = 800;
  const static int WIN_HEIGHT = 600;
  const static win_states check_win_integrity(const SDL_Window *win);

public:
  Window();
  Window(const char *title);
  bool init();
};
} // namespace gmcc

#endif
