#include "base_resource_manager.h"
#include "../texture_handler.hpp"
#include <SDL2/SDL_render.h>
#include <iostream>

namespace sdlAPI {
void Base_Resource_Manager::include_resource(const char *rsc_path) {
  const auto rsc_texture = m_textures.find(rsc_path);
  if (rsc_texture != nullptr) {
    std::cout << "Resource is already allocated" << std::endl;
  }

  SDL_Texture* texture = TextureHandler::create_texture_from_surface(rsc_path, m_renderer);
  m_textures.insert(std::make_pair(rsc_path, texture));
}
} // namespace sdlAPI
