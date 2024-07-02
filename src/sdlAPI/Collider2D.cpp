#include "Collider2D.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>

namespace sdlAPI {
Collider2D::Collider2D() {
  m_collider_rectangle = new SDL_Rect();
  m_collider_rectangle->x = 0;
  m_collider_rectangle->y = 0;
  m_collider_rectangle->w = 0;
  m_collider_rectangle->h = 0;
  m_outline_color = nullptr;
}

bool Collider2D::is_colliding(Collider2D &collider) {
  if(m_collider_rectangle != nullptr) {
    const SDL_Rect rectB = *collider.m_collider_rectangle;
    return SDL_HasIntersection(m_collider_rectangle, &rectB);
  }
  return false;
};

Collider2D::~Collider2D() {}
void Collider2D::update() {}

int Collider2D::get_x() const {
  return this->m_collider_rectangle->x;
}

int Collider2D::get_y() const {
  return this->m_collider_rectangle->y;
}

void Collider2D::set_absolute_position(int x, int y) {
  m_collider_rectangle->x = x;
  m_collider_rectangle->y = y;
}

void Collider2D::set_dimensions(int w, int h) {
  m_collider_rectangle->h = h;
  m_collider_rectangle->w = w;
}

void Collider2D::render(SDL_Renderer* renderer) {
  if(m_outline_color != nullptr) {
    SDL_SetRenderDrawColor(
        renderer, 
        (*m_outline_color & 0xFF0000FF) >> 24,
        (*m_outline_color & 0x00FF00FF) >> 16,
        (*m_outline_color & 0x0000FFFF) >> 8,
        SDL_ALPHA_OPAQUE
    );
    SDL_RenderDrawRect(renderer, m_collider_rectangle);
  } else {
    std::cout << "Must add a outline color around in the collider" << std::endl;
  }
}

void Collider2D::set_outline(Uint8 red, Uint8 green, Uint8 blue) {
  m_outline_color = new Uint32;
  *m_outline_color = 0;
  *m_outline_color += red;
  *m_outline_color <<= 8;
  *m_outline_color += green;
  *m_outline_color <<= 8;
  *m_outline_color += blue;
  *m_outline_color <<= 8;
  *m_outline_color += 0xFF;
}
} // namespace sdlAPI
