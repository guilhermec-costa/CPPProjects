#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>

namespace sdlAPI {
class Game {
private:
  bool is_running;
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Event *m_event;
  Uint32 mouse_buttons;
  int ymouse, xmouse;
  const Uint8 *keyboard_state;
  int m_max_framerate;
  int perfect_ms_between_frames;
  int frame_counter;

public:
  Game();
  virtual ~Game();
  bool start();
  void finish();
  bool create_window();
  bool create_window(const char *title, Uint32, Uint32 ypos, Uint32 width,
                     Uint32 height);
  bool create_window(const char *title, Uint32 width, Uint32 height);
  bool create_window(const char *title);
  bool create_renderer();
  void init_font_API();
  void init_image_API();
  void init_audio_API();
  void render();
  void update();
  void treat_events();
  void set_pixel(SDL_Surface *surface, Uint8 red, Uint8 green, Uint8 blue);
  inline int get_xmouse() const { return xmouse; }
  inline int get_ymouse() const { return ymouse; }
  bool get_state() const { return is_running; };
  const static char *src_path;
  inline void set_max_framerate(const int framerate) {
    m_max_framerate = framerate;
    perfect_ms_between_frames = 1000 / m_max_framerate; 
  };
  inline int get_framerate() const { return m_max_framerate; }
};
} // namespace sdlAPI
#endif
