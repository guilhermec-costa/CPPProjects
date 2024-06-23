#include "Game.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <iostream>

namespace sdlgame {

Game::Game(): 
  is_running(false),
  window(NULL),
  renderer(NULL),
  m_event(NULL) {}

Game::~Game() {
  //TODO
}

void Game::start() {
  if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cout << "Failed to initialise SDL subsystems" << std::endl;
  }
  m_event = new SDL_Event();
  create_window("my game", 800, 600);
  is_running = true;
}

bool Game::create_window(const char* title, Uint32 width, Uint32 height) {
  SDL_Window *window = 
      SDL_CreateWindow(
        title, 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        width, height, 
        SDL_WINDOW_SHOWN
  );

  if(!window) {
    std::cout << "Failed to create a SDL window" << std::endl;
    return false;
  }

  return true;
}

void Game::treat_events() {
  while(SDL_PollEvent(m_event)) {
    switch (m_event->type) {
      case SDL_QUIT: {
        std::cout << "Finishing game" << std::endl;
        this->stop();
      } 
    }
  }
}

void Game::stop() {
  is_running = false;
}

}
