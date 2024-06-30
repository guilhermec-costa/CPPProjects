#include "Textured_Rectangle.h"
#include "resource_managers/base_resource_manager.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

namespace sdlAPI {
Textured_Rectangle::Textured_Rectangle(
    SDL_Renderer *renderer, const char *filepath)
    : m_renderer(renderer) {
  Base_Resource_Manager::get_instance()->aloc_resource(filepath, false, renderer);
  m_texture = Base_Resource_Manager::get_instance()->get_texture(filepath);
  m_target_rect = new SDL_Rect();
  m_target_rect->x = 0;
  m_target_rect->y = 0;
  m_target_rect->w = 64;
  m_target_rect->h = 64;
}

void Textured_Rectangle::render_at_pos(int x, int y) {
  m_target_rect->x = x;
  m_target_rect->y = y;
}

void Textured_Rectangle::set_dimensions(int w, int h) {
  m_target_rect->w = w;
  m_target_rect->h = h;
}

void Textured_Rectangle::render() {
  SDL_RenderCopy(m_renderer, m_texture, NULL, m_target_rect);
}

bool Textured_Rectangle::is_colliding(Textured_Rectangle* rectB) {
  const SDL_Rect *_rectB = rectB->get_rect();
  return SDL_HasIntersection(m_target_rect, _rectB);
}
} // namespace sdlAPI
