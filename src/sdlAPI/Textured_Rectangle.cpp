#include "Textured_Rectangle.h"
#include "resource_managers/base_resource_manager.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>

namespace sdlAPI {
Textured_Rectangle::Textured_Rectangle(
    SDL_Renderer *renderer, const char *filepath)
    : m_renderer(renderer), m_current_portion(0),
    m_last_time_frame_updated(0) {
  Base_Resource_Manager::get_instance()->aloc_resource(filepath, false, renderer);
  m_texture = Base_Resource_Manager::get_instance()->get_texture(filepath);
  m_target_rect = new SDL_Rect();
  m_target_rect->x = 0;
  m_target_rect->y = 0;
  m_target_rect->w = 32;
  m_target_rect->h = 32;

  m_src_rect = new SDL_Rect();
  m_src_rect->x = 0;
  m_src_rect->y = 0;
  m_src_rect->w = 32;
  m_src_rect->h = 32;
}

void Textured_Rectangle::render_at_pos(int x, int y) {
  m_target_rect->x = x;
  m_target_rect->y = y;
}

void Textured_Rectangle::set_src_pos(int x, int y) {
  m_src_rect->x = x;
  m_src_rect->y = y;
}

void Textured_Rectangle::set_src_dimensions(int w, int h) {
  m_src_rect->w = w;
  m_src_rect->h = h;
}

void Textured_Rectangle::set_dst_dimensions(int w, int h) {
  m_target_rect->w = w;
  m_target_rect->h = h;
}


void Textured_Rectangle::render() {
  SDL_RenderCopy(m_renderer, m_texture, NULL, m_target_rect);
}

void Textured_Rectangle::render(bool move_to_next_portion) {
  const int frame_start = SDL_GetTicks();
  if(frame_start - m_last_time_frame_updated >= ms_between_portions) {
    m_last_time_frame_updated = frame_start;

    if(move_to_next_portion) {
      m_current_portion++;
      if(m_current_portion >= m_max_portions) {
          m_current_portion = 0;
      }
      this->set_src_pos(m_current_portion * m_sprite_frame_size, 0);
    };
  }
  SDL_RenderCopy(m_renderer, m_texture, m_src_rect, m_target_rect);
}

bool Textured_Rectangle::is_colliding(Textured_Rectangle* rectB) {
  const SDL_Rect *_rectB = rectB->get_rect();
  return SDL_HasIntersection(m_target_rect, _rectB);
}
} // namespace sdlAPI
