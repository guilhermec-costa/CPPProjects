#include "Game.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <iostream>
namespace sdlgame {
int main() {
  const int FPS = 60;
  const int ms_between_frame_update = 1 / FPS * 1000; 
  //    1 frame / 16.66ms

  Uint32 frame_start;
  int render_frame_time;

  Game game;
  game.start();
  while (game.get_state()) {
    frame_start = SDL_GetTicks();
    game.treat_events();
    game.update();
    game.render();
    render_frame_time = SDL_GetTicks() - frame_start;
    if(ms_between_frame_update > render_frame_time) {
      SDL_Delay(ms_between_frame_update - render_frame_time);
    }
  }

  return 0;
}
} // namespace sdlgame
