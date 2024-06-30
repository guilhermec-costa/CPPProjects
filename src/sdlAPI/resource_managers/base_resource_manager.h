#pragma once

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <unordered_map>
#include <iostream>
namespace sdlAPI {
class Base_Resource_Manager {
public:
  static Base_Resource_Manager* get_instance() {
    static Base_Resource_Manager instance;
    std::cout << &instance << std::endl;
    return &instance;
  };
  
  // blocks all kinds of new instances creations
  Base_Resource_Manager(const Base_Resource_Manager&) = delete;
  void operator=(const Base_Resource_Manager&) = delete;

  SDL_Texture *get_texture(const char *) const;
  void aloc_resource(const char *, bool consider_colorkey, SDL_Renderer* renderer);

private:
  Base_Resource_Manager() {};
  std::unordered_map<const char *, SDL_Texture *> m_textures;
};
} // namespace sdlAPI
