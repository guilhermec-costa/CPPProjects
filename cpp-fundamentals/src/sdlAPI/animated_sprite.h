#pragma once
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
namespace sdlAPI {
class Animated_Sprite {
public:
  Animated_Sprite(SDL_Texture* spritesheet);
  virtual ~Animated_Sprite();
  void set_sprite_dst_rect(SDL_Rect rect);
  void select_sprite(SDL_Rect& rect, int frame);
  void render(SDL_Renderer *renderer);
  /* void render(SDL_Rect& src, SDL_Rect&dst); */
private:
  SDL_Rect m_cur_frame_rect;
  SDL_Rect m_dst_rect; 
  SDL_Texture* m_spritesheet;
public:

};
}
