#pragma once

#include "base_resource_manager.h"
#include <SDL2/SDL_render.h>
namespace sdlAPI {
class Sprite_Resource_Manager : Base_Resource_Manager {
public:
  Sprite_Resource_Manager(SDL_Renderer* renderer): Base_Resource_Manager(renderer) {};
  void include_resource(const char*) override;
};
}
