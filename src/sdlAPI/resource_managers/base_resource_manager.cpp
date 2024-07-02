#include "base_resource_manager.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <iostream>

namespace sdlAPI {
void Base_Resource_Manager::aloc_resource(const char *filepath) {
  auto surface = m_surfaces.find(filepath);
  if (surface != nullptr) {
    std::cout << "Resource is already allocated" << std::endl;
  }
  SDL_Surface* tmp_sfc = IMG_Load(filepath);
  m_surfaces.insert(std::make_pair(filepath, tmp_sfc));
}

SDL_Surface* Base_Resource_Manager::get_resource(const char *filepath) const {
  const auto rsc_surface = m_surfaces.find(filepath);
  if(rsc_surface != m_surfaces.end()) {
    return m_surfaces.at(filepath);
  }
  std::cout << "Texture is not allocated. First, allocate it" << std::endl;
  return nullptr;
}
} // namespace sdlAPI
