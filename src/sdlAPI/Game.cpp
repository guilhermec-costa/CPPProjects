#include "Game.hpp"
#include "Game_Entity.h"
#include "Textured_Rectangle.h"
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
#include <vector>

namespace sdlAPI {

SDL_Surface *screen_surface = nullptr;
SDL_Texture *font_texture = nullptr;
SDL_Rect title = {100, 80, 600, 100};
Game_Entity* entity1 = nullptr;
Game_Entity* entity2 = nullptr;
Game_Entity* entity3 = nullptr;
Game_Entity* entity4 = nullptr;
Game_Entity* entity5 = nullptr;
std::vector<Game_Entity*> entities;

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

  
  entity1 = new Game_Entity(renderer);
  entity1->add_textured_rectangle("/home/guichina/dev/CPP/src/sdlAPI/assets/player.png");
  const SDL_Rect ent1_pos = { 5, 5, 64, 64};
  entity1->get_texture()->render_at_pos(ent1_pos.x, ent1_pos.y);
  entity1->get_texture()->set_dst_dimensions(ent1_pos.w, ent1_pos.h);

  const SDL_Rect ent2_pos = { 100, 20, 128, 128};
  entity2 = new Game_Entity(renderer);
  entity2->add_textured_rectangle("/home/guichina/dev/CPP/src/sdlAPI/assets/player.png");
  entity2->get_texture()->render_at_pos(ent2_pos.x, ent2_pos.y);
  entity2->get_texture()->set_dst_dimensions(ent2_pos.w, ent2_pos.h);

  entity3 = new Game_Entity(renderer);
  entity3->add_textured_rectangle("/home/guichina/dev/CPP/src/sdlAPI/assets/player_spritesheet.png", 0xEF, 0, 0xFF);
  entity3->get_texture()->set_src_pos(0, 0);
  entity3->get_texture()->set_src_dimensions(32, 32);
  entity3->get_texture()->set_max_portions(23);
  entity3->get_texture()->set_ms_between_portions(100);
  entity3->get_texture()->set_sprite_frame_size(32);
  entity3->get_texture()->set_dst_dimensions(128, 128);
  entity3->get_texture()->render_at_pos(180, 200);

  entity4 = new Game_Entity(renderer);
  entity4->add_textured_rectangle("/home/guichina/dev/CPP/src/sdlAPI/assets/player_spritesheet.png", 0xEF, 0, 0xFF);
  entity4->get_texture()->set_src_pos(0, 0);
  entity4->get_texture()->set_src_dimensions(32, 32);
  entity4->get_texture()->set_max_portions(23);
  entity4->get_texture()->set_ms_between_portions(2000);
  entity4->get_texture()->set_sprite_frame_size(32);
  entity4->get_texture()->render_at_pos(300, 250);
  entity4->get_texture()->set_dst_dimensions(128, 128);

  entity5 = new Game_Entity(renderer);
  entity5->add_textured_rectangle("/home/guichina/dev/CPP/src/sdlAPI/assets/kong.png", 0xEF, 0, 0xFF);
  entity5->get_texture()->set_src_pos(0, 0);
  entity5->get_texture()->set_dst_dimensions(64, 64);
  entity5->get_texture()->render_at_pos(400, 300);
  entity5->get_texture()->set_dst_dimensions(128, 128);

  entities.push_back(entity1);
  entities.push_back(entity2);
  entities.push_back(entity3);
  entities.push_back(entity4);
  entities.push_back(entity5);

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

void Game::update() {
  entity1->update();
  entity2->update();
  entity3->update();
  entity4->update();
  entity5->update();
}

void Game::render() {
  int frame_start = SDL_GetTicks();
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);

  entity1->render();
  entity2->render();
  entity3->render(true);
  entity4->render(true);
  entity5->render();
  SDL_RenderPresent(renderer);
  
  int frame_elapsed_time = SDL_GetTicks() - frame_start;
  if(frame_elapsed_time < perfect_ms_between_frames) {
    SDL_Delay(perfect_ms_between_frames - frame_elapsed_time);
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

    if (m_event->button.button == SDL_BUTTON_RIGHT) {
      for(auto entity : entities) {
        if(entity->contains_mouse(get_xmouse(), get_ymouse())) {
          entity->set_is_active(true);
        } else {
          entity->set_is_active(false);
        }
      }
    }

    if (m_event->type == SDL_MOUSEWHEEL) {
      std::cout << "mouse wheel" << std::endl;
    }

    if(m_event->button.button == SDL_BUTTON_LEFT) {
      for(auto entity : entities) {
        if(entity->is_active) {
          entity->get_texture()->render_at_pos(xmouse, ymouse);
          if(entity->get_collider2D()->is_colliding(*entities.at(1)->get_collider2D())) {
            std::cout << "Active entity colliding with another entity" << std::endl;
          } else {
            std::cout << "Not Active entity not colliding with another entity" << std::endl;
          }
        }
      }
    }
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
  for(auto entity: entities) {
    delete entity;
  }
  IMG_Quit();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

} // namespace sdlAPI
