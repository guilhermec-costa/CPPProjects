#include "Game.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <iostream>

namespace sdlgame {

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
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  is_running = true;
  return true;
}

bool Game::create_window(const char *title, Uint32 width, Uint32 height) {
  SDL_Window *new_window =
      SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       width, height, SDL_WINDOW_SHOWN);

  if (!new_window) {
    std::cout << "Failed to create a SDL window" << std::endl;
    return false;
  }

  window = new_window;
  return true;
}

bool Game::create_renderer() {
  SDL_Renderer *new_renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
  if (!new_renderer) {
    std::cout << "Failed to initialise SDL renderer" << std::endl;
    return false;
  }
  renderer = new_renderer;
  return true;
}

void Game::update() {
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}

void Game::treat_events() {
  while (SDL_PollEvent(m_event)) {
    std::cout << m_event->type << std::endl;
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
