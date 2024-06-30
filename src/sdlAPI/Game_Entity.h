#pragma once

#include "Textured_Rectangle.h"
#include "resource_managers/base_resource_manager.h"
namespace sdlAPI {
class Game_Entity {
public:
  Game_Entity() : m_texture(nullptr){};

  Game_Entity(Textured_Rectangle *texture, SDL_Renderer *renderer)
      : m_texture(texture), m_renderer(renderer){};

  Game_Entity(const char *assetpath, SDL_Renderer *renderer)
      : m_renderer(renderer) {
    m_texture = new Textured_Rectangle(m_renderer, assetpath);
  }
  virtual ~Game_Entity();
  inline void render() {
    if (m_texture != nullptr) {
      m_texture->render();
    }
  }
  void update();

  inline Textured_Rectangle* get_texture() const { return m_texture; }

private:
  Textured_Rectangle *m_texture;
  SDL_Renderer *m_renderer;
};
} // namespace sdlAPI
