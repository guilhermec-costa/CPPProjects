#include "animated_sprite.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

namespace sdlAPI {
Animated_Sprite::Animated_Sprite(SDL_Texture* spritsheet):
  m_spritsheet(spritsheet),
  m_dst_rect({}),
  m_cur_frame_rect({})
  {}

Animated_Sprite::~Animated_Sprite() {
  //TODO
}

void Animated_Sprite::set_sprite_dst_rect(SDL_Rect& dst_rect) {
  m_dst_rect.x = dst_rect.x;
  m_dst_rect.y = dst_rect.y;
  m_dst_rect.h = dst_rect.h;
  m_dst_rect.w = dst_rect.w;
}

void Animated_Sprite::select_frame(SDL_Rect& src_rect, int frame) {
  m_cur_frame_rect.x = src_rect.x + src_rect.w*frame;
}
}
