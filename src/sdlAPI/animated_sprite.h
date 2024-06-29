#pragma once
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
namespace sdlAPI {
class Animated_Sprite {
public:
  Animated_Sprite(const char *const sprite_path);
  virtual ~Animated_Sprite();
  void render();
  void render(SDL_Rect& src, SDL_Rect&dst);
private:
  SDL_Texture* complete_texture;
  const char* sprite_path;
};
}
