#include "main.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include "window.h"

namespace particle {
int run() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL init failed" << std::endl;
    return 1;
  }
  
  const char *title = "sdl2";
  SDL_Window *window = SDL_CreateWindow(
                          title,
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          Window::WIN_WIDTH,
                          Window::WIN_HEIGHT,
                          SDL_WINDOW_SHOWN                        
                      );

  win_states win_state = Window::check_win_integrity(window);
  if(win_state == win_states::COULDNT_CREATE_WINDOW) return 2;
  
  SDL_Event event;
  bool quit = false;
  while(!quit) {
    while(SDL_PollEvent(&event)) {
      if(event.type == SDL_QUIT) {
        std::cout << "quiting" << std::endl;
        quit = true;
      }
    }
  }
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
} // namespace particle
