#include "Game.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_image.h>
#include <iostream>

namespace sdlgame {

SDL_Texture* player_texture = nullptr;
SDL_Rect rect;
const char* Game::src_path = "/home/guichina/dev/CPP/src/agame/";

Game::Game() : is_running(false), window(NULL), renderer(NULL), m_event(NULL) {}

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
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  is_running = true;
  
  SDL_Surface* surface = IMG_Load("/home/guichina/dev/CPP/src/agame/assets/player.png");
  player_texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);
  return true;
}

bool Game::create_window(const char *title, Uint32 width, Uint32 height) {
  window = SDL_CreateWindow(
                       title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       width, height, SDL_WINDOW_SHOWN
  );

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
  rect.h = 64;
  rect.w = 64;
  rect.x += 1;
}

void Game::render() {
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, player_texture, NULL, &rect);
  SDL_RenderPresent(renderer);
}

void Game::treat_events() {
  while (SDL_PollEvent(m_event)) {
    switch (m_event->type) {
    case SDL_QUIT: {
      std::cout << "Finishing game" << std::endl;
      this->finish();
    }
    }
  }
}

void Game::finish() { 
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  is_running = false;
}

} // namespace sdlgame
