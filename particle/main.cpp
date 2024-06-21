#include "main.h"
#include <SDL2/SDL_timer.h>
#include <ctime>
#include <iostream>
#include "particle_orchestrator.h"
#include "window.h"
#include <math.h>
#include <stdlib.h>

namespace gmcc {
int run() {
  srand(time(NULL));
  Window *window = new Window("Particle Explosion");
  if(!window->init()) {
    std::cout << "failed to initialize SDL" << std::endl;
  };

  Particle_Orchestrator particle_orchestrator;

  while(true) {
    const int elapsed = SDL_GetTicks();
    unsigned char red = (unsigned char)((1 + cos(elapsed * 0.001)) * 128);
    unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0021)) * 128);
    unsigned char blue= (unsigned char)((1 + sin(elapsed * 0.0031)) * 128);

    /* for(int y=0; y<Window::WIN_HEIGHT; y++) {
      for(int x=0; x < Window::WIN_WIDTH; x++) {
        window->set_pixel_color(x, y, red, green, blue);
      }
    } */
    const Particle *const p_particle = particle_orchestrator.get_particles();
    for(int i=0; i<Particle_Orchestrator::N_PARTICLES; i++) {
      Particle particle = p_particle[i];
      int x = (particle.m_x + 1) * Window::WIN_WIDTH/2;
      int y = (particle.m_y + 1) * Window::WIN_HEIGHT/2;
      window->set_pixel_color(x, y, red, green, blue);
    }
    window->update();
    if(!window->manage_events()) break;
  }
  
  window->terminate();

  return 0;
}

} 
