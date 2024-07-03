#pragma once

#include "resource_managers/base_resource_manager.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
namespace sdlAPI {
class Textured_Rectangle {
public:
  Textured_Rectangle(SDL_Renderer *renderer, const char*filepath);
  Textured_Rectangle(SDL_Renderer *renderer, const char* filepath, Uint32 red, Uint32 blue, Uint32 green);
  Textured_Rectangle(SDL_Renderer* renderer, SDL_Surface* src_surface, const char*filepath);
  void render_at_pos(int x, int y);
  void set_src_pos(int x, int y);
  void set_dst_dimensions(int w, int h);
  void set_src_dimensions(int w, int h);
  inline void set_sprite_frame_size(int pixels) { m_sprite_frame_size = pixels; }
  void render();
  void render(bool move_to_next_portion);
  const SDL_Rect* get_rect() const { return m_target_rect; }
  void inline set_ms_between_portions(int ms) { ms_between_portions = ms; }
  void inline set_max_portions(const int portions) { m_max_portions = portions; }
  SDL_Texture* get_texture() const { return m_texture; }
  int get_x() const;
  int get_y() const;
  int get_width() const;
  int get_height() const;
  SDL_Renderer* get_renderer() const;
private:
  SDL_Rect* m_target_rect;
  SDL_Rect* m_src_rect;
  SDL_Renderer* m_renderer;
  SDL_Texture* m_texture;
  int ms_between_portions;
  int m_current_portion;
  int m_max_portions;
  int m_sprite_frame_size;
  int m_last_time_frame_updated;
  void init_defaults();
};
}
