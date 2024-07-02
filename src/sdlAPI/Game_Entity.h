#pragma once

#include "Collider2D.h"
#include "Textured_Rectangle.h"
#include "resource_managers/base_resource_manager.h"
#include <SDL2/SDL_stdinc.h>
namespace sdlAPI {
class Game_Entity {
public:
  int m_current_sprite_frame;
  bool is_active;

public:
  Game_Entity();
  Game_Entity(SDL_Renderer* renderer);
  virtual ~Game_Entity();

  void render();
  void render(bool move_to_next_portion);

  inline Textured_Rectangle *get_texture() const { return m_texture; }
  inline Collider2D *get_collider2D() const { return m_collider2D; }
  inline void set_is_active(const bool status) { is_active = status; }
  bool contains_mouse(int x, int y);
  void add_textured_rectangle(const char *filepath);
  void add_textured_rectangle(const char* filepath, Uint32 red, Uint32 green, Uint32 blue);
  void update();

private:
  Textured_Rectangle *m_texture;
  SDL_Renderer *m_renderer;
  Collider2D *m_collider2D;
};
} // namespace sdlAPI
