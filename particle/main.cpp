#include "main.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_video.h>
#include <cstring>
#include <iostream>
#include "window.h"

namespace gmcc {
int run() {
  Window *window = new Window("Particle Explosion");
  if(!window->init()) {
    std::cout << "failed to initialize SDL" << std::endl;
  };

  while(true) {
    if(!window->manage_events()) break;
    window->update();
  }
  
  window->terminate();

  return 0;
}

} 
