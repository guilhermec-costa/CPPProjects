#include <iostream>
#include <SDL2/SDL.h>
namespace agame {
int main() {
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "failed to initialize sdl video subsystem" << std::endl;
  }
  std::cout << "agame" << std::endl;
  return 0;
}
} // namespace agame
