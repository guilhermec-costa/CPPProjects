#pragma once

#include "Textured_Rectangle.h"
#include <SDL2/SDL_rect.h>
namespace sdlAPI {
class Collider2D {
public:
  Collider2D();
  ~Collider2D();
  bool is_colliding(Collider2D &collider);
  void update();
  void set_absolute_position(int x, int y);
  void set_dimensions(int w, int h);
  int get_x() const;
  int get_y() const;

private:
  SDL_Rect m_collider_rectangle;
};
} // namespace sdlAPI
