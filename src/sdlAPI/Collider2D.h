#pragma once

// a collider is just a bounding box that lives arround some texture
// a collider has x, y, w and h properties so the texture
// the collider exists so the responsability of detecting a collision does not have to be at the texture
// but, for this to work, the properties of the collider have to be at the same position as the texture that it represents
#include "Textured_Rectangle.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
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
  void render(SDL_Renderer* renderer);

private:
  SDL_Rect m_collider_rectangle;
};
} // namespace sdlAPI
