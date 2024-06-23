#include "Game.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_video.h>
#include <iostream>
namespace sdlgame {
int main() {
  Game game;
  game.start();
  while (game.get_state()) {
    game.treat_events();
  }
  return 0;
}
} // namespace sdlgame
