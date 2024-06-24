#pragma once
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

namespace sdlgame {
class TextureHandler {
public:
  static SDL_Texture* create_texture_from_surface(
    const char* recurse_name,
    SDL_Renderer* renderer
  );
};
}; // namespace sdlgame
