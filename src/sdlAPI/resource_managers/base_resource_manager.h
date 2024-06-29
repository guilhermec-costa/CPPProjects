#pragma once

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <unordered_map>
namespace sdlAPI {
class Base_Resource_Manager {
public:
  Base_Resource_Manager(SDL_Renderer *const renderer) : m_renderer(renderer){};

private:
  Base_Resource_Manager(const Base_Resource_Manager &);
  std::unordered_map<const char *, SDL_Texture *> m_textures;
  SDL_Renderer *m_renderer;

protected:
  virtual void include_resource(const char *);
  virtual void sfc_to_texture(const SDL_Surface *sfc);
  virtual SDL_Texture *get_texture() const;
};
} // namespace sdlAPI
