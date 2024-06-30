#pragma once

#include "Textured_Rectangle.h"
#include "resource_managers/base_resource_manager.h"
namespace sdlAPI {
class Game_Entity {
public:
  Game_Entity(): m_texture(nullptr) {};
  Game_Entity(Textured_Rectangle* texture, SDL_Renderer* renderer): 
      m_texture(texture), m_renderer(renderer) {};
  Game_Entity(const char* assetpath, SDL_Renderer* renderer):
    m_renderer(renderer) {
    m_texture = new Textured_Rectangle(renderer, assetpath);
  }
  virtual ~Game_Entity();
  inline void render() {
    m_texture->render();
  }

  void set_initial_pos(int x, int y) {
    const SDL_Rect dst_rect = {x, y, 64, 64};
    m_texture->render_at(dst_rect);
  };
private:
  Textured_Rectangle* m_texture;
  SDL_Renderer* m_renderer;
};
} // namespace sdlAPI
