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
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Event* m_event;
  Uint32 mouse_buttons;
  int ymouse, xmouse;
  const Uint8* keyboard_state;
  
public:
  Game();
  virtual ~Game();
  bool start();
  void finish();
  bool create_window();
  bool create_window(const char* title, Uint32 , Uint32 ypos, Uint32 width, Uint32 height);
  bool create_window(const char* title, Uint32 width, Uint32 height);
  bool create_window(const char* title);
  bool create_renderer();
  void init_font_API();
  void render();
  void update();
  void treat_events();
  void set_pixel(SDL_Surface* surface, Uint8 red, Uint8 green, Uint8 blue);
  bool get_state() const { return is_running; };
  const static char* src_path;
};
} // namespace sdlgame
#endif
