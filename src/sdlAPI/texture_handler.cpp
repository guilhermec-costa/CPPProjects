#include "texture_handler.hpp"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

namespace sdlAPI {
SDL_Texture *
TextureHandler::create_texture_from_surface(const char *recurse_name,
                                            SDL_Renderer *renderer) {
  SDL_Surface *tmp_surface = IMG_Load(recurse_name);
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, tmp_surface);
  SDL_FreeSurface(tmp_surface);
  return texture;
}

SDL_Texture *TextureHandler::create_texture_from_surface_with_colorkey(
    const char *recurse_name, SDL_Renderer *renderer, Uint32 exclude_color) {

  SDL_Surface *tmp_surface = IMG_Load(recurse_name);
  Uint8 red = (exclude_color & 0xFF0000FF) >> 24;
  Uint8 green = (exclude_color & 0x00FF00FF) >> 16;
  Uint8 blue = (exclude_color & 0x0000FFFF) >> 8;

  SDL_SetColorKey(tmp_surface, SDL_TRUE,
                  SDL_MapRGB(tmp_surface->format, red, green, blue));
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, tmp_surface);
  SDL_FreeSurface(tmp_surface);
  return texture;
}
} // namespace sdlAPI
