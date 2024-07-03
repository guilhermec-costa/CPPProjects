#include "TextComponent.hpp"
#include "Textured_Rectangle.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <iostream>

namespace sdlAPI {
Text_Component::Text_Component(SDL_Renderer* renderer, std::string fontpath, uint32_t size): m_font(nullptr) {
  m_font = TTF_OpenFont(fontpath.c_str(), size);
  m_fontpath = fontpath;
  if(m_font == nullptr) {
    std::cout << "Failed to load font from: " << fontpath << std::endl;
  }
  SDL_Surface* tmp_surface = TTF_RenderText_Solid(m_font, NULL, { 255, 255, 255});
  m_font_texture = new Textured_Rectangle(renderer, tmp_surface, fontpath.c_str());
  m_last_surface = tmp_surface; 
}

void Text_Component::render() {
  m_font_texture->render();
}

Textured_Rectangle* Text_Component::get_texture() const {
  return m_font_texture;
}

void Text_Component::set_font_size(uint32_t size) {
  SDL_FreeSurface(m_last_surface);
  m_font_size = size;
  m_font = TTF_OpenFont(m_fontpath.c_str(), m_font_size);
  SDL_Surface* tmp_surface = TTF_RenderText_Solid(m_font, NULL, { 255, 255, 255});
  m_font_texture = new Textured_Rectangle(m_font_texture->get_renderer(), tmp_surface, m_fontpath.c_str());
  m_last_surface = tmp_surface; 
}

void Text_Component::set_text(const char* text) {
  SDL_FreeSurface(m_last_surface);
  m_text = text;
  SDL_Surface* tmp_surface = TTF_RenderText_Solid(m_font, m_text, { 255, 255, 255});
  m_font_texture = new Textured_Rectangle(m_font_texture->get_renderer(), tmp_surface, m_fontpath.c_str());
  m_last_surface = tmp_surface;
}
}
