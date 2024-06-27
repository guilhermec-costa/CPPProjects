#include "Game.hpp"
#include "texture_handler.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <cstring>
#include <iostream>

namespace sdlAPI {

SDL_Texture *player_texture = nullptr;
Uint32 *pixels = nullptr;
SDL_Rect rect;
SDL_Rect a_rect;
SDL_Rect rect2;
SDL_Surface *screen_surface = nullptr;
SDL_Surface *image = nullptr;
SDL_Texture *img_texture = nullptr;
SDL_Texture *rect2_texture = nullptr;
SDL_Surface *test_surface;
const char *Game::src_path = "/home/guichina/dev/CPP/src/agame/";

Game::Game() : is_running(false), window(nullptr), renderer(nullptr), m_event(nullptr) {}

Game::~Game() {
  // TODO
}

bool Game::start() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cout << "Failed to initialise SDL subsystems" << std::endl;
  }
  m_event = new SDL_Event();
  if (!create_window("my game", 800, 600))
    return false;
  if (!create_renderer())
    return false;

  is_running = true;
  player_texture = TextureHandler::create_texture_from_surface(
      "/home/guichina/dev/CPP/src/agame/assets/player.png", renderer);
  screen_surface = SDL_GetWindowSurface(window);
  image = SDL_LoadBMP("/home/guichina/dev/CPP/src/agame/assets/player.bmp");
  img_texture = SDL_CreateTextureFromSurface(renderer, image);
  SDL_FreeSurface(image);
  pixels = new Uint32[400 * 300];
  rect2_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, 300, 300);
  rect.h = 64;
  rect.w = 64;
  a_rect.h = 32;
  a_rect.w = 64;

  return true;
}

bool Game::create_window(const char *title, Uint32 width, Uint32 height) {
  window =
      SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       width, height, SDL_WINDOW_SHOWN);

  if (!window) {
    std::cout << "Failed to create a SDL window" << std::endl;
    return false;
  }

  return true;
}

bool Game::create_renderer() {
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer) {
    std::cout << "Failed to initialise SDL renderer" << std::endl;
    return false;
  }
  return true;
}

void Game::update() {
}

void Game::render() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);
  

  SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderDrawRect(renderer, &a_rect);

  SDL_RenderCopy(renderer, img_texture, NULL, &a_rect);

  SDL_RenderDrawLine(renderer, 100, 100, 200, 100);

  /* pixels[200*150 + 200] = 0x0000FFFF;
  SDL_UpdateTexture(rect2_texture, NULL, pixels, sizeof(Uint32) * 300);
  SDL_RenderCopy(renderer, rect2_texture, NULL, NULL); */

  SDL_RenderPresent(renderer);
}

void Game::treat_events() {
  mouse_buttons = SDL_GetMouseState(&xmouse, &ymouse);
  keyboard_state = SDL_GetKeyboardState(NULL);
  while (SDL_PollEvent(m_event)) {
    switch (m_event->type) {
    case SDL_QUIT:
      is_running = false;
      break;

    case SDL_MOUSEMOTION:
      break;

    case SDL_KEYDOWN:
      unsigned int key_pressed = m_event->key.keysym.sym;
      /* std::cout << (char)key_pressed << std::endl; */
      /* std::cout << m_event->key.keysym.scancode << std::endl; */
      if(m_event->key.keysym.scancode == 40) {
        /* SDL_memset(screen_surface->pixels, 0, screen_surface->pitch * screen_surface->h); */
      }
      break;
    }

    if(keyboard_state[SDL_SCANCODE_W] && keyboard_state[SDL_SCANCODE_LCTRL]) {
      /* std::cout << "ctrl + w pressed" << std::endl; */
    }

    if(m_event->button.button == SDL_BUTTON_LEFT) {
      /* set_pixel(screen_surface, 0, 255, 0); */
    }
    /* SDL_UpdateWindowSurface(window); */
  }
}

void Game::set_pixel(SDL_Surface *surface, Uint8 red, Uint8 green, Uint8 blue) {
  SDL_LockSurface(surface);
  Uint8 *pixels = (Uint8*)surface->pixels;
  pixels[(ymouse * surface->pitch) + xmouse*surface->format->BytesPerPixel] = blue;
  pixels[(ymouse * surface->pitch) + xmouse*surface->format->BytesPerPixel+1] = green;
  pixels[(ymouse * surface->pitch) + xmouse*surface->format->BytesPerPixel+2] = red;
  pixels[(ymouse * surface->pitch) + xmouse*surface->format->BytesPerPixel+3] = 255;
  SDL_UnlockSurface(surface);
}

void Game::finish() {
  SDL_DestroyTexture(img_texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

} // namespace sdlgame
