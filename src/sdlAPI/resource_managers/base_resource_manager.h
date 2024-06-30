#pragma once

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <unordered_map>
namespace sdlAPI {
class Base_Resource_Manager {
public:
  Base_Resource_Manager(SDL_Renderer *renderer) : m_renderer(renderer){};
  SDL_Texture *get_texture(const char *) const;
  void aloc_resource(const char *, bool consider_colorkey);

private:
  std::unordered_map<const char *, SDL_Texture *> m_textures;
  SDL_Renderer *m_renderer;
};
} // namespace sdlAPI
