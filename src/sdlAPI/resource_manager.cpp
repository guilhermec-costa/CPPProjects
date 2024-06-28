#include "resource_manager.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_surface.h>
#include <utility>

namespace sdlAPI {
void Resource_Manager::operator=(Resource_Manager const &) {}

Resource_Manager *Resource_Manager::get_instance() {
  Resource_Manager *s_instance = new Resource_Manager();
  return s_instance;
}

SDL_Surface *Resource_Manager::get_surface(const std::string resource_name) const {
  auto sfc = m_surfaces.find(resource_name);
  if (sfc != m_surfaces.end()) {
    return m_surfaces.at(resource_name);
  }

  SDL_Surface *new_sfc = SDL_LoadBMP(resource_name.c_str());
  if (new_sfc != nullptr) {
    m_surfaces.insert(std::make_pair<std::string, SDL_Surface*>(resource_name, new_sfc));
  }
  return new_sfc;
}
} // namespace sdlAPI
