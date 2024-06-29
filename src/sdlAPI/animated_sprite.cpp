#include "animated_sprite.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <iostream>

namespace sdlAPI {
Animated_Sprite::Animated_Sprite(SDL_Texture *spritesheet)
    : m_spritesheet(spritesheet) {}

Animated_Sprite::~Animated_Sprite() {
  // TODO
}

void Animated_Sprite::set_sprite_dst_rect(SDL_Rect dst_rect) {
  m_dst_rect.x = dst_rect.x;
  m_dst_rect.y = dst_rect.y;
  m_dst_rect.h = dst_rect.h;
  m_dst_rect.w = dst_rect.w;
}

void Animated_Sprite::select_sprite(SDL_Rect &src_rect, int frame) {
  m_cur_frame_rect.x = src_rect.x + src_rect.w * frame;
  m_cur_frame_rect.y = src_rect.y;
  m_cur_frame_rect.h = src_rect.h;
  m_cur_frame_rect.w = src_rect.w;
}

void Animated_Sprite::render(SDL_Renderer *renderer) {
  SDL_RenderCopy(renderer, m_spritesheet, &m_cur_frame_rect, &m_dst_rect);
}
} // namespace sdlAPI
