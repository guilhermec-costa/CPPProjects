#ifndef TEXT_COMPONENT_H
#define TEXT_COMPONENT_H

#include "Textured_Rectangle.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include <cstdint>
#include <string>
namespace sdlAPI {
class Text_Component {
public:
  Text_Component(SDL_Renderer* renderer, std::string fontpath, uint32_t size=14);
  ~Text_Component();
  void set_font_size(uint32_t size);
  void set_text(const char*);
  void render();
  Textured_Rectangle* get_texture() const;
private:
  SDL_Rect m_target_rectangle;
  Textured_Rectangle* m_font_texture;
  SDL_Surface* m_last_surface;
  uint32_t m_font_size;
  TTF_Font* m_font;
  const char* m_text;
  std::string m_fontpath;
};
}
#endif
