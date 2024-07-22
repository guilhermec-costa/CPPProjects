#pragma once
#include <SDL2/SDL_surface.h>
#include <iostream>
#include <unordered_map>

namespace sdlAPI {
class Resource_Manager {
private:
  Resource_Manager();
  Resource_Manager(Resource_Manager const&);
  Resource_Manager* operator=(Resource_Manager const&rhs);
  std::unordered_map<std::string, SDL_Surface*> m_surfaces;
public:
  static Resource_Manager* get_instance();
  SDL_Surface* get_surface(const std::string) ;
};
} // namespace sdlAPI
