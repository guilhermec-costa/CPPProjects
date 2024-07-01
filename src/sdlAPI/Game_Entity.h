#pragma once

#include "Collider2D.h"
#include "Textured_Rectangle.h"
#include "resource_managers/base_resource_manager.h"
namespace sdlAPI {
class Game_Entity {
public:
  int m_current_sprite_frame;
  bool is_active;

public:
  Game_Entity() : m_texture(nullptr), m_current_sprite_frame(0){};

  Game_Entity(Textured_Rectangle *texture, SDL_Renderer *renderer)
      : m_texture(texture), m_renderer(renderer), m_current_sprite_frame(0){};

  Game_Entity(const char *assetpath, SDL_Renderer *renderer)
      : m_renderer(renderer), m_current_sprite_frame(0) {
    m_texture = new Textured_Rectangle(m_renderer, assetpath);
    m_collider2D = new Collider2D();
  }
  virtual ~Game_Entity();

  void render();
  void render(bool move_to_next_portion);

  inline Textured_Rectangle *get_texture() const { return m_texture; }
  inline Collider2D *get_collider2D() const { return m_collider2D; }
  inline void set_is_active(const bool status) { is_active = status; }
  bool contains_mouse(int x, int y);
  void update();

private:
  Textured_Rectangle *m_texture;
  SDL_Renderer *m_renderer;
  Collider2D* m_collider2D;
};
} // namespace sdlAPI
