#include "base_resource_manager.h"
#include "../texture_handler.hpp"
#include <SDL2/SDL_render.h>
#include <iostream>

namespace sdlAPI {
void Base_Resource_Manager::aloc_resource(const char *rsc_path, const bool consider_colorkey, SDL_Renderer* renderer) {
  auto rsc_texture = m_textures.find(rsc_path);
  if (rsc_texture != nullptr) {
    std::cout << "Resource is already allocated" << std::endl;
  }
  
  SDL_Texture* texture;
  if(consider_colorkey) {
    texture = TextureHandler::create_texture_from_surface_with_colorkey(rsc_path, renderer, 0xEF00FFFF);
  } else {
    texture = TextureHandler::create_texture_from_surface(rsc_path, renderer);
  }
  m_textures.insert(std::make_pair(rsc_path, texture));
}

SDL_Texture* Base_Resource_Manager::get_texture(const char *rsc_path) const {
  const auto rsc_texture = m_textures.find(rsc_path);
  if(rsc_texture != m_textures.end()) {
    return m_textures.at(rsc_path);
  }
  std::cout << "Texture is not allocated. First, allocate it" << std::endl;
  return nullptr;
}
} // namespace sdlAPI
