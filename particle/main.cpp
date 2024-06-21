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
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL init failed" << std::endl;
    return 1;
  }
  
  /* Window *pWindow = new Window("Particle Explosion");
  pWindow->init(); */
  SDL_Window *window = SDL_CreateWindow(
                          title,
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          Window::WIN_WIDTH,
                          Window::WIN_HEIGHT,
                          SDL_WINDOW_SHOWN                        
                      );

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
  // memset(allBytes, eachByteValue, quantityOfBytesToChangeValue);
  memset(buf1, 0, Window::WIN_WIDTH * Window::WIN_HEIGHT * sizeof(Uint32));

  // accessing a single Uint32 memory slot, which contains 4 bytes, one byte for each color,
  // one byte being from 0 to 255 in int

  for(int i=0; i<Window::WIN_WIDTH * Window::WIN_HEIGHT; i++) {
    buf1[i] = 0xFFFF00FF;
  }
  buf1[258000] = 0x0000FFFF;

  while(!quit) {
    while(SDL_PollEvent(&event)) {
      if(event.type == SDL_QUIT) {
        quit = true;
      }
    }
    SDL_UpdateTexture(texture,NULL, buf1, Window::WIN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
  }

  delete [] buf1;
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}

} 
