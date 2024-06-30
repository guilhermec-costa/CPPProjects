#include "Game.hpp"
#include "Game_Entity.h"
#include "Textured_Rectangle.h"
#include "animated_sprite.h"
#include "resource_managers/base_resource_manager.h"
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
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>
#include <cstring>
#include <iostream>

namespace sdlAPI {

SDL_Surface *screen_surface = nullptr;
SDL_Texture *font_texture = nullptr;
SDL_Rect title = {100, 80, 600, 100};
SDL_Texture *spritesheet = nullptr;
Animated_Sprite *animated_sprite = nullptr;
Game_Entity* entity1 = nullptr;
Game_Entity* entity2 = nullptr;

Game::Game()
    : is_running(false), 
      window(nullptr),  
      renderer(nullptr), 
      m_event(nullptr) {
  m_event = new SDL_Event();
}

Game::~Game() {
  // TODO
}

bool Game::start() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cout << "Failed to initialise SDL subsystems" << std::endl;
  }
  screen_surface = SDL_GetWindowSurface(window);
  if (!create_window("my game", 800, 600)) return false;
  if (!create_renderer()) return false;
  init_font_API();
  init_image_API();

  Base_Resource_Manager::get_instance()->aloc_resource("/home/guichina/dev/CPP/src/sdlAPI/assets/player_spritesheet.png", true, renderer);
  spritesheet = Base_Resource_Manager::get_instance()->get_texture("/home/guichina/dev/CPP/src/sdlAPI/assets/player_spritesheet.png");
  animated_sprite = new Animated_Sprite(spritesheet);

  SDL_Rect sprite_dst_rect = {800 / 2 - 256, 600 / 2, 128, 128};
  animated_sprite->set_sprite_dst_rect(sprite_dst_rect);
  
  entity1 = new Game_Entity("/home/guichina/dev/CPP/src/sdlAPI/assets/player.png", renderer);
  const SDL_Rect ent1_pos = { 100, 100, 64, 64};
  const SDL_Rect ent2_pos = { 100, 200, 128, 128};
  entity1->get_texture()->render_at_pos(ent1_pos.x, ent1_pos.y);
  entity1->get_texture()->set_dimensions(ent1_pos.w, ent1_pos.h);
  entity2 = new Game_Entity("/home/guichina/dev/CPP/src/sdlAPI/assets/player.png", renderer);
  entity2->get_texture()->render_at_pos(ent2_pos.x, ent2_pos.y);
  entity2->get_texture()->set_dimensions(ent2_pos.w, ent2_pos.h);

  is_running = true;
  return true;
}

void Game::init_font_API() {
  if (TTF_Init() < 0) {
    std::cout << "Failed to initialise fonts API" << std::endl;
  }
  TTF_Font *pixeledFont =
      TTF_OpenFont("/home/guichina/dev/CPP/src/sdlAPI/fonts/Daydream.ttf", 16);
  SDL_Surface *text_sfc =
      TTF_RenderText_Solid(pixeledFont, "A NAKED MAN", {255, 255, 255});
  if (text_sfc == nullptr) {
    std::cout << TTF_GetError() << std::endl;
  }
  font_texture = SDL_CreateTextureFromSurface(renderer, text_sfc);
  SDL_FreeSurface(text_sfc);
}

void Game::init_image_API() {
  int supported_formats = IMG_INIT_JPG | IMG_INIT_PNG;
  int innited_bitmask = IMG_Init(supported_formats);
  if ((innited_bitmask & supported_formats) != supported_formats) {
    std::cout << "SDL2_image format not available" << std::endl;
  }
}

bool Game::create_window(const char *title, Uint32 width, Uint32 height) {
  window = SDL_CreateWindow(
                    title, SDL_WINDOWPOS_CENTERED,
                    SDL_WINDOWPOS_CENTERED, width, 
                    height, SDL_WINDOW_SHOWN
          );

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

void Game::update() {}

void Game::render() {
  std::cout << SDL_GetTicks() << std::endl;
  int frame_start = SDL_GetTicks();
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);
  static int cur_frame = 0;
  SDL_Rect spritesheet_portion = {0, 0, 32, 32};
  animated_sprite->select_sprite(spritesheet_portion, cur_frame);
  animated_sprite->render(renderer);
  if (SDL_GetTicks() % 500 == 0) {
    cur_frame++;
  }
  if (cur_frame % 22 == 0) {
    cur_frame = 0;
  }

  entity1->render();
  entity2->render();
  SDL_RenderPresent(renderer);
  
  int frame_elapsed_time = SDL_GetTicks() - frame_start;
  if(frame_elapsed_time < perfect_ms_between_frames) {
    SDL_Delay(perfect_ms_between_frames - frame_elapsed_time);
  }
  frame_counter++;
  if(frame_counter == m_max_framerate) {
    frame_counter = 0;
  }
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
      if (m_event->key.keysym.scancode == 40) {
      }
      break;
    }

    if (keyboard_state[SDL_SCANCODE_W] && keyboard_state[SDL_SCANCODE_LCTRL]) {
      /* std::cout << "ctrl + w pressed" << std::endl; */
    }

    if (m_event->button.button == SDL_BUTTON_LEFT) {
      if(entity1->contains_mouse(this->get_xmouse(), this->get_ymouse())) {
        entity1->set_is_active(true);
      } else {
        entity1->set_is_active(false);
      }
    }

    if (m_event->type == SDL_MOUSEWHEEL) {
      std::cout << "mouse wheel" << std::endl;
    }

    if(m_event->type  == SDL_MOUSEMOTION) {
      if(entity1->is_active) {
        entity1->get_texture()->render_at_pos(xmouse, ymouse);
      }
    }

    /* SDL_UpdateWindowSurface(window); */
  }
}

void Game::set_pixel(SDL_Surface *surface, Uint8 red, Uint8 green, Uint8 blue) {
  SDL_LockSurface(surface);
  Uint8 *pixels = (Uint8 *)surface->pixels;
  pixels[(ymouse * surface->pitch) + xmouse * surface->format->BytesPerPixel] = blue;
  pixels[(ymouse * surface->pitch) + xmouse * surface->format->BytesPerPixel + 1] = green;
  pixels[(ymouse * surface->pitch) + xmouse * surface->format->BytesPerPixel + 2] = red;
  pixels[(ymouse * surface->pitch) + xmouse * surface->format->BytesPerPixel + 3] = 255;
  SDL_UnlockSurface(surface);
}

void Game::finish() {
  IMG_Quit();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

} // namespace sdlAPI
