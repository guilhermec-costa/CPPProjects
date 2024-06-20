#include "main.h"
#include <SDL2/SDL.h>
#include <iostream>

namespace particle {
int run() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL init failed" << std::endl;
    return 1;
  }
  std::cout << "SDL init succeeded" << std::endl;
  SDL_Quit();
  return 0;
}
} // namespace particle
