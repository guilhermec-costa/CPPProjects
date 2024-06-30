#include "Textured_Rectangle.h"
#include "resource_managers/base_resource_manager.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

namespace sdlAPI {
Textured_Rectangle::Textured_Rectangle(
    SDL_Renderer *renderer, const char *filepath,
    Base_Resource_Manager *base_resource_manager)
    : m_renderer(renderer), m_resource_manager(base_resource_manager) {
  m_resource_manager->aloc_resource(filepath, false);
  m_texture = m_resource_manager->get_texture(filepath);
  m_target_rect = new SDL_Rect();
}

void Textured_Rectangle::render_at(const SDL_Rect &A) {
  m_target_rect->h = A.h;
  m_target_rect->w = A.w;
  m_target_rect->x = A.x;
  m_target_rect->y = A.y;
}

void Textured_Rectangle::render() {
  SDL_RenderCopy(m_renderer, m_texture, NULL, m_target_rect);
}

bool Textured_Rectangle::is_colliding(const SDL_Rect *rectB) {
  const SDL_Rect *rectA = this->get_rect();
  return SDL_HasIntersection(rectA, rectB);
}
} // namespace sdlAPI
