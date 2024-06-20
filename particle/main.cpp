#include "main.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_video.h>
#include <cstring>
#include <iostream>
#include "window.h"

namespace gmcc {
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
  // computer screens syncs from to left corner x times, dependening on the monitor
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
  if(renderer == NULL) { 
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 3;
  }
  SDL_Texture *texture = SDL_CreateTexture(
                                           renderer,
                                           SDL_PIXELFORMAT_RGBA8888,
                                           SDL_TEXTUREACCESS_STATIC,
                                           Window::WIN_WIDTH,
                                           Window::WIN_HEIGHT
                                          );
  if(texture == NULL ) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 4;
  }
  
  // reserves enough memory to manipulate all the pixels on the screen
  Uint32 *buf1 = new Uint32[Window::WIN_WIDTH * Window::WIN_HEIGHT];
  memset(buf1, 0xFF, Window::WIN_WIDTH * Window::WIN_HEIGHT * sizeof(Uint32));

  SDL_UpdateTexture(texture, NULL, buf1, Window::WIN_WIDTH * sizeof(Uint32));
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);

  while(!quit) {
    while(SDL_PollEvent(&event)) {
      if(event.type == SDL_QUIT) {
        std::cout << "quiting" << std::endl;
        quit = true;
      }
    }
  }
  delete [] buf1;
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}

} 
