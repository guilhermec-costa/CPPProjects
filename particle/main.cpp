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
    for(int y=0; y<Window::WIN_HEIGHT; y++) {
      for(int x=0; x < Window::WIN_WIDTH; x++) {
        window->set_pixel_color(x, y, 255, 0, 0);
      }
    }
    window->set_pixel_color(400, 300, 255, 255, 255);
    window->update();
    if(!window->manage_events()) break;
  }
  
  window->terminate();

  return 0;
}

} 
