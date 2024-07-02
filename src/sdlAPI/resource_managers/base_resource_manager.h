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
    return &instance;
  };
  
  // blocks all kinds of new instances creations
  Base_Resource_Manager(const Base_Resource_Manager&) = delete;
  void operator=(const Base_Resource_Manager&) = delete;

  SDL_Surface*get_resource(const char *) const;
  void aloc_resource(const char *filepath);

private:
  Base_Resource_Manager() {};
  std::unordered_map<const char *, SDL_Surface*> m_surfaces;
};
} // namespace sdlAPI
