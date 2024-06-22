#ifndef WINDOW_H_
#define WINDOW_H_

#include <SDL2/SDL_events.h>
#include <iostream>
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
  Uint32 *m_blur_buffer;
  SDL_Event *m_event;
  const char *p_title;

private:
  bool init_window();
  bool init_renderer();
  bool init_texture();
  void init_buffer();

public:
  const static int WIN_WIDTH = 1360;
  const static int WIN_HEIGHT = 768;

public:
  Window();
  Window(const char *title);
  const static win_states check_win_integrity(const SDL_Window *win);
  bool init();
  void terminate();
  bool manage_events();
  void set_pixel_color(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
  bool contains_pixel(int x, int y);
  bool contains_pixel_xaxis(int x);
  bool contains_pixel_yaxis(int y);
  void box_blur();
  void update();
  void clear_pixels();
};
} // namespace gmcc

#endif
