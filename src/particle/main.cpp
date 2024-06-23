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
  const double HALF_SCREEN_WIDTH = Window::WIN_WIDTH/2.0;
  const double HALF_SCREEN_HEIGHT = Window::WIN_HEIGHT/2.0;
   
  while(true) {
    const int elapsed = SDL_GetTicks();
    particle_orchestrator.move_particles_based_on_elapsed(elapsed);
    unsigned char red = (unsigned char)((1 + cos(elapsed * 0.001)) * 128);
    unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0021)) * 128);
    unsigned char blue= (unsigned char)((1 + sin(elapsed * 0.0031)) * 128);

    const Particle *const p_particle = particle_orchestrator.get_particles();
    for(int i=0; i<Particle_Orchestrator::N_PARTICLES; i++) {
      Particle particle = p_particle[i];
      int x = (particle.m_x + 1) * HALF_SCREEN_WIDTH;
      int y = particle.m_y * HALF_SCREEN_WIDTH + HALF_SCREEN_HEIGHT;
      if(window->contains_pixel(x, y)) {
        window->set_pixel_color(x, y, red, green, blue);
      }
    }
    window->box_blur();
    window->update();
    if(!window->manage_events()) break;
  }
  
  window->terminate();

  return 0;
}

} 
