#include "Game.hpp"
#include "resource_manager.h"
#include "texture_handler.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_blendmode.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_ttf.h>
#include <cstring>
#include <iomanip>
#include <iostream>

namespace sdlAPI {

SDL_Texture *player_texture = nullptr;
SDL_Rect srcRect;
SDL_Rect dstRect;
SDL_Rect rect;
SDL_Rect a_rect;
SDL_Rect character_rect;
SDL_Surface *screen_surface = nullptr;
SDL_Surface *image = nullptr;
SDL_Rect filled_rectangle;
SDL_Texture *texture_to_fill_rectangle = nullptr;
Uint32 *filled_rectangle_pixels;
SDL_Texture *font_texture = nullptr;
SDL_Rect title;
SDL_Rect rectangle2;
SDL_Texture* pixel_player_texture = nullptr;
SDL_Rect pixel_player_rect = {200, 200, 128, 128};
SDL_Rect src_sprite_rect = {1, 1, 31, 31};
SDL_Rect dst_sprite_rect = {200, 200, 128, 128};
SDL_Texture* spritesheet = nullptr;
const char *Game::src_path = "/home/guichina/dev/CPP/src/agame/";

Game::Game() : is_running(false), window(nullptr), renderer(nullptr), m_event(nullptr) {
  resource_manager = Resource_Manager::get_instance();
  init_font_API();
  init_image_API(); 
}

Game::~Game() {
  // TODO
}

bool Game::start() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cout << "Failed to initialise SDL subsystems" << std::endl;
  }
  m_event = new SDL_Event();
  if (!create_window("my game", 800, 600))
    return false;
  if (!create_renderer())
    return false;

  screen_surface = SDL_GetWindowSurface(window);

  SDL_Surface* player_pixel_sfc = resource_manager->get_surface("/home/guichina/dev/CPP/src/sdlAPI/assets/player.bmp");
  player_pixel_sfc = resource_manager->get_surface("/home/guichina/dev/CPP/src/sdlAPI/assets/player.bmp");
  player_pixel_sfc = resource_manager->get_surface("/home/guichina/dev/CPP/src/sdlAPI/assets/player.bmp");
  pixel_player_texture = SDL_CreateTextureFromSurface(renderer, player_pixel_sfc);
  SDL_SetTextureBlendMode(player_texture, SDL_BLENDMODE_ADD);

  SDL_Surface* sprite_sfc = resource_manager->get_surface("/home/guichina/dev/CPP/src/sdlAPI/assets/player_spritesheet.bmp");
  SDL_SetColorKey(sprite_sfc, SDL_TRUE, SDL_MapRGB(sprite_sfc->format, 0xFF, 0x00, 0xCD));
  spritesheet = SDL_CreateTextureFromSurface(renderer, sprite_sfc);
  SDL_SetTextureBlendMode(spritesheet, SDL_BLENDMODE_ADD);
  SDL_FreeSurface(sprite_sfc);

  image = SDL_LoadBMP("/home/guichina/dev/CPP/src/agame/assets/player.bmp");

  SDL_FreeSurface(image);
  SDL_FreeSurface(player_pixel_sfc);
  rect.h = 64;
  rect.w = 64;
  a_rect.h = 32;
  a_rect.w = 64;
  character_rect.h = 64;
  character_rect.w = 64;
  character_rect.x = 105;
  character_rect.y = 105;

  
  filled_rectangle.h = 200;
  filled_rectangle.w = 200;
  filled_rectangle.x = 100;
  filled_rectangle.y = 100;

  rectangle2.h = 200;
  rectangle2.w = 200;
  rectangle2.x = 450;
  rectangle2.y = 300;

  title.w = 400;
  title.h = 100;
  title.x = 200;
  title.y = 300;
  texture_to_fill_rectangle = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, 200, 200);
  filled_rectangle_pixels = new Uint32[200 * 200];


  // the rectangle that can represent a portion of a texture
  srcRect.x = 0;      // x of the texture
  srcRect.y = 0;      // y of the texrure
  srcRect.w = 100;    // w of the portion from the texture
  srcRect.h = 200;    // w of the portion from the texture
  
  // the destination rectangle. The rendering target
  dstRect.x = 0;      
  dstRect.y = 0;      
  dstRect.w = 200;    
  dstRect.h = 200;    
  is_running = true;
  return true;
}

void Game::init_font_API() {
  if(TTF_Init() < 0) {
    std::cout << "Failed to initialise fonts API" << std::endl;
  }
  TTF_Font *pixeledFont = TTF_OpenFont("/home/guichina/dev/CPP/src/sdlAPI/fonts/Daydream.ttf", 16);
  SDL_Surface *text_sfc = TTF_RenderText_Solid(pixeledFont, "SNAKE GAME", {255, 255, 255});
  if(text_sfc==nullptr) {
    std::cout << TTF_GetError() << std::endl;
  }
  font_texture = SDL_CreateTextureFromSurface(renderer, text_sfc);
  SDL_FreeSurface(text_sfc);
}

void Game::init_image_API() {
  int supported_formats = IMG_INIT_JPG | IMG_INIT_PNG;
  int innited_bitmask = IMG_Init(supported_formats);
  std::cout << std::setfill('0') << std::setw(32) << std::hex << (innited_bitmask & supported_formats) << std::endl;
  if((innited_bitmask & supported_formats) != supported_formats) {
    std::cout << "SDL2_image format not available" << std::endl;
  }
}

bool Game::create_window(const char *title, Uint32 width, Uint32 height) {
  window =
      SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       width, height, SDL_WINDOW_SHOWN);

  if (!window) {
    std::cout << "Failed to create a SDL window" << std::endl;
    return false;
  }

  return true;
}

bool Game::create_renderer() {
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer) {
    std::cout << "Failed to initialise SDL renderer" << std::endl;
    return false;
  }
  return true;
}

void Game::update() {
}

void Game::render() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);

  for(int y=0; y<200; y++) {
    for(int x=0; x<200; x++) {
      if(y % 10 == 0) {
        filled_rectangle_pixels[(y * 200) + x] = 0xFF0000FF;
        continue;
      }
      filled_rectangle_pixels[(y * 200) + x] = 0x0000FFFF;
    }
  }

  SDL_UpdateTexture(texture_to_fill_rectangle, NULL, filled_rectangle_pixels, sizeof(Uint32) * 200);
  SDL_RenderCopy(renderer, player_texture, NULL, NULL);
  SDL_RenderCopy(renderer, font_texture, NULL, &title);
  SDL_RenderCopy(renderer, texture_to_fill_rectangle, &srcRect, &dstRect);
  SDL_RenderCopy(renderer, pixel_player_texture, NULL, &pixel_player_rect);
  SDL_RenderCopy(renderer, spritesheet, &src_sprite_rect, &dst_sprite_rect);
  SDL_RenderPresent(renderer);
}

void Game::treat_events() {
  mouse_buttons = SDL_GetMouseState(&xmouse, &ymouse);
  keyboard_state = SDL_GetKeyboardState(NULL);
  while (SDL_PollEvent(m_event)) {
    switch (m_event->type) {
    case SDL_QUIT:
      is_running = false;
      break;

    case SDL_MOUSEMOTION:
      break;

    case SDL_KEYDOWN:
      unsigned int key_pressed = m_event->key.keysym.sym;
      /* std::cout << (char)key_pressed << std::endl; */
      /* std::cout << m_event->key.keysym.scancode << std::endl; */
      if(m_event->key.keysym.scancode == 40) {
        /* SDL_memset(screen_surface->pixels, 0, screen_surface->pitch * screen_surface->h); */
      }
      break;
    }

    if(keyboard_state[SDL_SCANCODE_W] && keyboard_state[SDL_SCANCODE_LCTRL]) {
      /* std::cout << "ctrl + w pressed" << std::endl; */
    }

    if(m_event->button.button == SDL_BUTTON_LEFT) {
      pixel_player_rect.x = xmouse;
      pixel_player_rect.y = ymouse;
      dst_sprite_rect.x = xmouse;
    }

    if(m_event->type == SDL_MOUSEWHEEL) {
      std::cout << "mouse wheel" << std::endl;
    }

    /* SDL_UpdateWindowSurface(window); */
  }
}

void Game::set_pixel(SDL_Surface *surface, Uint8 red, Uint8 green, Uint8 blue) {
  SDL_LockSurface(surface);
  Uint8 *pixels = (Uint8*)surface->pixels;
  pixels[(ymouse * surface->pitch) + xmouse*surface->format->BytesPerPixel] = blue;
  pixels[(ymouse * surface->pitch) + xmouse*surface->format->BytesPerPixel+1] = green;
  pixels[(ymouse * surface->pitch) + xmouse*surface->format->BytesPerPixel+2] = red;
  pixels[(ymouse * surface->pitch) + xmouse*surface->format->BytesPerPixel+3] = 255;
  SDL_UnlockSurface(surface);
}

void Game::finish() {
  IMG_Quit();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

} // namespace sdlgame
