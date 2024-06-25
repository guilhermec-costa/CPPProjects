#include "Game.hpp"
#include "texture_handler.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <cstring>
#include <iostream>

namespace sdlgame {

SDL_Texture *player_texture = nullptr;
SDL_Rect rect;
SDL_Surface *screen_surface = nullptr;
SDL_Surface *image = nullptr;
SDL_Texture *texture = nullptr;
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
  SDL_UpdateWindowSurface(window);
  rect.h = 64;
  rect.w = 64;

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
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
  if (!renderer) {
    std::cout << "Failed to initialise SDL renderer" << std::endl;
    return false;
  }
  return true;
}

void Game::update() {
}

void Game::render() {
  /* SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, player_texture, NULL, &rect);
  SDL_RenderPresent(renderer); */
}

void Game::treat_events() {
  mouse_buttons = SDL_GetMouseState(&xmouse, &ymouse);
  const Uint8 *keyboard_state = SDL_GetKeyboardState(NULL);
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
      break;
    }

    if(keyboard_state[SDL_SCANCODE_W] && keyboard_state[SDL_SCANCODE_LCTRL]) {
      /* std::cout << "ctrl + w pressed" << std::endl; */
    }
    if(m_event->button.button == SDL_BUTTON_LEFT) {
      SDL_LockSurface(screen_surface);
      std::cout << "left button pressed" << std::endl;
      // direct access to screen pixels
      SDL_memset(screen_surface->pixels, 0xFFFF0000, screen_surface->h/3 * screen_surface->pitch);
      SDL_UnlockSurface(screen_surface);
      SDL_UpdateWindowSurface(window);
    }
  }
}

void Game::finish() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

} // namespace sdlgame
