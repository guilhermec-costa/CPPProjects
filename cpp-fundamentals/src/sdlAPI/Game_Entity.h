#pragma once

#include "Collider2D.h"
#include "TextComponent.hpp"
#include "Textured_Rectangle.h"
#include "resource_managers/base_resource_manager.h"
#include <SDL2/SDL_stdinc.h>
#include <vector>

namespace sdlAPI {
class Game_Entity {
public:
  int m_current_sprite_frame;
  bool is_active;

public:
  Game_Entity();
  Game_Entity(SDL_Renderer* renderer, std::string TAG="");
  virtual ~Game_Entity();


  inline void set_is_active(const bool status) { is_active = status; }
  bool contains_mouse(int x, int y);

  void update();
  void render();
  void render(bool move_to_next_portion);

  // set components
  void add_textured_rectangle(const char *filepath);
  void add_textured_rectangle(const char* filepath, Uint32 red, Uint32 green, Uint32 blue);
  Collider2D* add_collider2D();
  void add_text_component(const char*, int32_t size);

  // get components
  Textured_Rectangle *get_texture() const;
  Collider2D *get_collider2D(size_t idx) const; 
  std::vector<Collider2D*> get_colliders2D() const;

public:
  std::string m_TAG;

private:
  Textured_Rectangle *m_texture;
  SDL_Renderer *m_renderer;
  Text_Component* m_text;
  std::vector<Collider2D*> m_colliders2D;
};
} // namespace sdlAPI
