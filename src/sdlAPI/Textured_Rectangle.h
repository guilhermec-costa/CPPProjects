#pragma once

#include "resource_managers/base_resource_manager.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
namespace sdlAPI {
class Textured_Rectangle {
public:
  Textured_Rectangle(SDL_Renderer *renderer, const char*filepath, Base_Resource_Manager* base_resource_manager);
  void render_at(const SDL_Rect&);
  void render();
private:
  SDL_Rect* m_target_rect;
  bool is_colliding(const SDL_Rect *B);
  SDL_Renderer* m_renderer;
  SDL_Texture* m_texture;
  Base_Resource_Manager* m_resource_manager;
  const SDL_Rect* get_rect() const { return m_target_rect; }
};
}
