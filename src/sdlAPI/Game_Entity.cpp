#include "Game_Entity.h"

namespace sdlAPI {
void Game_Entity::update() {
  int entity_x = m_texture->get_x();
  int entity_y = m_texture->get_y();
  int entity_w = m_texture->get_width();
  int entity_h = m_texture->get_height();
  m_collider2D->set_absolute_position(entity_x, entity_y);
  m_collider2D->set_dimensions(entity_w, entity_h);
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

void Game_Entity::render(bool move_to_next_portion) {
    if(m_texture != nullptr) {
      if(move_to_next_portion) m_texture->render(move_to_next_portion);
      return;
    }
    m_texture->render();
}

void Game_Entity::render() {
    if (m_texture != nullptr) {
      m_texture->render();
      m_collider2D->render(m_renderer);
    }
}
}

