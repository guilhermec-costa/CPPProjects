#include "Game_Entity.h"

namespace sdlAPI {
void Game_Entity::update() {
}

Game_Entity::~Game_Entity() {
}

bool Game_Entity::contains_mouse(int xmouse, int ymouse) {
  const SDL_Rect *current_entity_rectangle = this->get_texture()->get_rect();
  int current_entity_x = current_entity_rectangle->x, current_entity_y = current_entity_rectangle->y;
  if(xmouse >= current_entity_x && xmouse <= (current_entity_x + current_entity_rectangle->w) &&
     ymouse >= current_entity_y && ymouse <= current_entity_y + current_entity_rectangle->h) {
    return true;
  }
  return false;
}
}

