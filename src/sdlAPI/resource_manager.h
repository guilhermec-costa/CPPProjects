#pragma once
#include <SDL2/SDL_surface.h>
#include <iostream>
#include <unordered_map>

namespace sdlAPI {
class Resource_Manager {
private:
  Resource_Manager();
  Resource_Manager(Resource_Manager const&);
  void operator=(Resource_Manager const&);
  std::unordered_map<const std::string, SDL_Surface*> m_surfaces;
public:
  static Resource_Manager* get_instance();
  SDL_Surface* get_surface(const std::string) const;
};
} // namespace sdlAPI
