#include "window.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>
#include <cstddef>
#include <cstring>

namespace gmcc {

const win_states Window::check_win_integrity(const SDL_Window *win) {
  if (win == NULL) {
    return win_states::COULDNT_CREATE_WINDOW;
  }
  return win_states::CREATED;
}

Window::Window()
    : m_window(NULL), 
      m_texture(NULL), 
      m_renderer(NULL), 
      m_buffer(NULL),
      m_blur_buffer(NULL),
      p_title(NULL),
      m_event(NULL) {}

Window::Window(const char *title) { p_title = title; }
bool Window::init_window() {
  m_window = SDL_CreateWindow(
              p_title,
              SDL_WINDOWPOS_UNDEFINED,
              SDL_WINDOWPOS_UNDEFINED, 
              WIN_WIDTH, WIN_HEIGHT,
              SDL_WINDOW_RESIZABLE 
  );
  if(!m_window) {
    SDL_Quit();
    return false;
  }
  return true;
}

bool Window::init_renderer() {
  // computer screens syncs from to left corner x times, dependening on the monitor
  m_renderer =
    SDL_CreateRenderer(this->m_window, -1, SDL_RENDERER_PRESENTVSYNC);
  if(!m_renderer) {
    SDL_DestroyWindow(m_window);
    SDL_Quit();
    return false;
  }
  return true;
}

bool Window::init_texture() {
  m_texture =
      SDL_CreateTexture(
              this->m_renderer,
              SDL_PIXELFORMAT_RGBA8888,
              SDL_TEXTUREACCESS_STATIC, 
              WIN_WIDTH,
              WIN_HEIGHT
    );
  if(!m_texture) {
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
    return false;
  }
  return true;
}

bool Window::init() {
  if(SDL_Init(SDL_INIT_VIDEO) < 0) return false;
  m_event = new SDL_Event();
  if(!init_window()) return false;
  if(!init_renderer()) return false;
  if(!init_texture()) return false;
  init_buffer();
  return true;
}

void Window::init_buffer() {
  m_buffer = new Uint32[WIN_WIDTH * WIN_HEIGHT];
  m_blur_buffer = new Uint32[WIN_WIDTH * WIN_HEIGHT];
  // sets value for each byte
  memset(m_buffer, 0, WIN_WIDTH * WIN_HEIGHT * sizeof(Uint32));
  memset(m_blur_buffer, 0, WIN_WIDTH * WIN_HEIGHT * sizeof(Uint32));
}

void Window::update() {
  SDL_UpdateTexture(m_texture, NULL, m_buffer, WIN_WIDTH * sizeof(Uint32));
  SDL_RenderClear(m_renderer);
  SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
  SDL_RenderPresent(m_renderer);
}

bool Window::manage_events() {
  while(SDL_PollEvent(m_event)) {
    if(m_event->type == SDL_QUIT) {
      return false;
    }
  }
  return true;
}

void Window::set_pixel_color(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
  Uint32 color = 0;
  color += red;
  color <<= 8;
  color += green;
  color <<= 8;
  color += blue;
  color <<= 8;
  // alpha value 
  color += 0xFF;
  m_buffer[(y * WIN_WIDTH) + x] = color;
}

bool Window::contains_pixel(int x, int y) {
  if(x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT) return false;
  return true;
}

bool Window::contains_pixel_xaxis(int x) {
  return (x < 0 || x >= WIN_WIDTH) ? false : true;
}

bool Window::contains_pixel_yaxis(int y) {
  return (y < 0 || y >= WIN_HEIGHT) ? false : true;
}

void Window::clear_pixels() {
  memset(m_buffer, 0, WIN_WIDTH * WIN_HEIGHT * sizeof(Uint32));
  memset(m_blur_buffer, 0, WIN_WIDTH * WIN_HEIGHT * sizeof(Uint32));
}

void Window::box_blur() {
  Uint32 *pixel_checkpoint = m_buffer;
  m_buffer = m_blur_buffer;
  m_blur_buffer = pixel_checkpoint;

  for(int y=0; y<WIN_HEIGHT; y++) {
    for(int x=0; x<WIN_WIDTH; x++) {

      int total_red_shade = 0;
      int total_green_shade = 0;
      int total_blue_shade = 0;

      for(int pixel_surrounding_row=-1; pixel_surrounding_row<=1; pixel_surrounding_row++) {
        for(int pixel_surrounding_col=-1; pixel_surrounding_col<=1; pixel_surrounding_col++) {
          int current_x = x + pixel_surrounding_col;
          int current_y = y + pixel_surrounding_row;
          if(this->contains_pixel(current_x, current_y)) {
            Uint32 current_pixel_color = m_blur_buffer[( current_y * WIN_WIDTH) + current_x];
            Uint8 pixel_color_red_shade = (current_pixel_color & 0xFF000000) >> 24;
            Uint8 pixel_color_green_shade = (current_pixel_color & 0x00FF0000) >> 16;
            Uint8 pixel_color_blue_shade = (current_pixel_color & 0x0000FF00) >> 8;

            total_red_shade += pixel_color_red_shade;
            total_green_shade += pixel_color_green_shade;
            total_blue_shade += pixel_color_blue_shade;
          }
        }
      }
      Uint8 box_red_shade_mean= total_red_shade/9;
      Uint8 box_green_shade_mean = total_green_shade/9;
      Uint8 box_blue_shade_mean = total_blue_shade/9;

      set_pixel_color(
        x, y,
        box_red_shade_mean,
        box_green_shade_mean,
        box_blue_shade_mean
      );
    }
  }
}

void Window::terminate() {
  delete [] m_buffer;
  SDL_DestroyTexture(m_texture);
  SDL_DestroyRenderer(m_renderer);
  SDL_DestroyWindow(m_window);
  SDL_Quit();
}
} // namespace gmcc
