#pragma once
#include "Game.hpp"
namespace sdlgame {
class Game_Object {
private:
  int xpos;
  int ypos;
  SDL_Texture *obj_texture;
};
} // namespace sdlgame
