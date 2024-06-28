#include "texture_handler.hpp"
#include <iostream>

using std::cout, std::endl;
namespace sdlAPI {
SDL_Texture *TextureHandler::create_texture_from_surface(const char *recurse_name, SDL_Renderer *renderer) {
    SDL_Surface* tmp_surface = IMG_Load(recurse_name);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tmp_surface);
    SDL_FreeSurface(tmp_surface);
    return texture;
}
}
