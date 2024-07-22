#pragma once
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

namespace sdlAPI {
class TextureHandler {
public:
  static SDL_Texture *create_texture_from_surface(const char *recurse_name,
                                                  SDL_Renderer *renderer);

  static SDL_Texture *create_texture_from_surface_with_colorkey(
      const char *recurse_name,
      SDL_Renderer *renderer,
      Uint32 exclude_color
  );
};
}; // namespace sdlAPI
