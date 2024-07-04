#include "Game.hpp"
#include "Collider2D.h"
#include "Game_Entity.h"
#include "ISound.h"
#include "TextComponent.hpp"
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
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>

namespace sdlAPI {

SDL_Surface *screen_surface = nullptr;
SDL_Texture *font_texture = nullptr;
SDL_Rect title = {500, 80, 200, 100};
Game_Entity* entity1 = nullptr;
Game_Entity* entity2 = nullptr;
Game_Entity* entity3 = nullptr;
Game_Entity* entity4 = nullptr;
Game_Entity* entity5 = nullptr;
SDL_Sound* collision_sound = nullptr;
Text_Component* font = nullptr;
Textured_Rectangle* tilemap_texture = nullptr;

int tilemap[25][19];
SDL_Rect tiles[25][19];
SDL_Rect select_tile1 = { 0, 0, 32, 32 };
SDL_Rect select_tile2 = { 32, 0, 32, 32 };
SDL_Rect select_tile3 = { 0, 32, 32, 32 };
SDL_Rect select_tile4 = { 32, 32, 32, 32 };
std::vector<Game_Entity*> entities;

Uint32 print_something(Uint32 interval, void *param) {
  std::cout << "Hello" << std::endl;
  return 0;
}

Game::Game()
    : is_running(false), 
      window(nullptr),  
      renderer(nullptr), 
      m_event(nullptr) {
  m_event = new SDL_Event();
}
// header file in its ESSENCE

Game::~Game() {
  delete m_event;
  for(auto entity: entities) {
    delete entity;
  }
}

bool Game::start() {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0) {
    std::cout << "Failed to initialise SDL subsystems" << std::endl;
  }
  if (TTF_Init() < 0) {
    std::cout << "Failed to initialise fonts API" << std::endl;
  }
  screen_surface = SDL_GetWindowSurface(window);
  collision_sound = new SDL_Sound("/home/guichina/dev/CPP/src/sdlAPI/assets/sounds/collide.wav");
  collision_sound->setup_device();

  if (!create_window("my game", 800, 600)) return false;
  if (!create_renderer()) return false;
  init_image_API();
  srand(time(NULL));

  
  font = new Text_Component(renderer, "/home/guichina/dev/CPP/src/sdlAPI/assets/fonts/Lato-Regular.ttf", 14);
  font->set_text("churros");
  font->get_texture()->render_at_pos(150, 400);
  font->get_texture()->set_dst_dimensions(250, 128);


  entity1 = new Game_Entity(renderer, "Entity 1");
  entity1->add_textured_rectangle("/home/guichina/dev/CPP/src/sdlAPI/assets/images/player.png");
  const SDL_Rect ent1_pos = { 5, 5, 64, 64};
  entity1->get_texture()->render_at_pos(ent1_pos.x, ent1_pos.y);
  entity1->get_texture()->set_dst_dimensions(ent1_pos.w, ent1_pos.h);
  entity1->add_collider2D()->set_outline(255, 0, 0);
  entity1->add_collider2D()->set_outline(255, 0, 255);
  entity1->add_collider2D()->set_outline(0, 225, 255);

  const SDL_Rect ent2_pos = { 100, 20, 128, 128};
  entity2 = new Game_Entity(renderer);
  entity2->add_textured_rectangle("/home/guichina/dev/CPP/src/sdlAPI/assets/images/player.png");
  entity2->get_texture()->render_at_pos(ent2_pos.x, ent2_pos.y);
  entity2->get_texture()->set_dst_dimensions(ent2_pos.w, ent2_pos.h);
  entity2->add_collider2D()->set_outline(255, 255, 255);

  const SDL_Rect ent3_pos = { 200, 250, 128, 128};
  entity3 = new Game_Entity(renderer, "Entity 3");
  entity3->add_textured_rectangle("/home/guichina/dev/CPP/src/sdlAPI/assets/images/player_spritesheet.png", 0xEF, 0, 0xFF);
  entity3->get_texture()->set_src_pos(0, 0);
  entity3->get_texture()->set_src_dimensions(32, 32);
  entity3->get_texture()->set_max_portions(23);
  entity3->get_texture()->set_ms_between_portions(100);
  entity3->get_texture()->set_sprite_frame_size(32);
  entity3->get_texture()->render_at_pos(ent3_pos.x, ent3_pos.y);
  entity3->get_texture()->set_dst_dimensions(ent3_pos.w, ent3_pos.h);
  entity3->add_collider2D()->set_outline(0, 255, 255);

  const SDL_Rect ent4_pos = { 500, 100, 128, 128};
  entity4 = new Game_Entity(renderer, "Entity 4");
  entity4->add_textured_rectangle("/home/guichina/dev/CPP/src/sdlAPI/assets/images/player_spritesheet.png", 0xEF, 0, 0xFF);
  entity4->get_texture()->set_src_pos(0, 0);
  entity4->get_texture()->set_src_dimensions(32, 32);
  entity4->get_texture()->set_max_portions(23);
  entity4->get_texture()->set_ms_between_portions(2000);
  entity4->get_texture()->set_sprite_frame_size(32);
  entity4->get_texture()->render_at_pos(ent4_pos.x, ent4_pos.y);
  entity4->get_texture()->set_dst_dimensions(ent4_pos.w, ent4_pos.h);
  entity4->add_collider2D()->set_outline(0, 255, 255);

  entity5 = new Game_Entity(renderer);
  entity5->add_textured_rectangle("/home/guichina/dev/CPP/src/sdlAPI/assets/images/kong.png", 0xEF, 0, 0xFF);
  entity5->get_texture()->set_src_pos(0, 0);
  entity5->get_texture()->set_dst_dimensions(64, 64);
  entity5->get_texture()->render_at_pos(400, 300);
  entity5->get_texture()->set_dst_dimensions(128, 128);
  entity5->add_collider2D()->set_outline(120, 255, 0);
  entity5->add_collider2D()->set_outline(120, 120, 255);

  tilemap_texture = new Textured_Rectangle(renderer, "/home/guichina/dev/CPP/src/sdlAPI/assets/images/tilemap.png");
  for(int x=0; x<25; x++) {
    for(int y=0; y<19; y++) {
      tilemap[x][y] = rand() % 4 + 1;
    }
  }

  for(int x=0; x<25; x++) {
    for(int y=0; y<19; y++) {
      tiles[x][y].x = x*32;
      tiles[x][y].y = y*32;
      tiles[x][y].w = 32;
      tiles[x][y].h = 32;
    }
  }


  entities.push_back(entity1);
  entities.push_back(entity2);
  entities.push_back(entity3);
  entities.push_back(entity4);
  entities.push_back(entity5);
  
  // each src_rect to get from the whole texture 


  SDL_AddTimer(7000, print_something, (char*)"teste");

  is_running = true;
  return true;
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
  entity1->get_collider2D(0)->set_absolute_position(entity1->get_texture()->get_x(), entity1->get_texture()->get_y());
  entity1->get_collider2D(0)->set_dimensions(entity1->get_texture()->get_width(), entity1->get_texture()->get_height());
  entity1->get_collider2D(1)->set_absolute_position(entity1->get_texture()->get_x(), entity1->get_texture()->get_y());
  entity1->get_collider2D(1)->set_dimensions(entity1->get_texture()->get_width()/2, entity1->get_texture()->get_height()/2);
  entity1->get_collider2D(2)->set_absolute_position(entity1->get_texture()->get_x() + entity1->get_texture()->get_width()/2, entity1->get_texture()->get_y() + entity1->get_texture()->get_height()/2);
  entity1->get_collider2D(2)->set_dimensions(entity1->get_texture()->get_width()/2, entity1->get_texture()->get_height()/3);

  entity2->get_collider2D(0)->set_absolute_position(entity2->get_texture()->get_x(), entity2->get_texture()->get_y());
  entity2->get_collider2D(0)->set_dimensions(entity2->get_texture()->get_width(), entity2->get_texture()->get_height());

  entity3->get_collider2D(0)->set_absolute_position(entity3->get_texture()->get_x(), entity3->get_texture()->get_y());
  entity3->get_collider2D(0)->set_dimensions(entity3->get_texture()->get_width(), entity3->get_texture()->get_height());

  entity4->get_collider2D(0)->set_absolute_position(entity4->get_texture()->get_x(), entity4->get_texture()->get_y());
  entity4->get_collider2D(0)->set_dimensions(entity4->get_texture()->get_width(), entity4->get_texture()->get_height());

  entity5->get_collider2D(0)->set_absolute_position(entity5->get_texture()->get_x(), entity5->get_texture()->get_y());
  entity5->get_collider2D(0)->set_dimensions(entity5->get_texture()->get_width(), entity5->get_texture()->get_height());
  entity5->get_collider2D(1)->set_absolute_position(entity5->get_texture()->get_x(), entity5->get_texture()->get_y());
  entity5->get_collider2D(1)->set_dimensions(entity5->get_texture()->get_width()*3, entity5->get_texture()->get_height());
}

void Game::render() {
  int frame_start = SDL_GetTicks();
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);

  for(int x=0; x<25; x++) {
    for(int y=0; y<19; y++) {
      switch(tilemap[x][y]) {
        case 1: {
          SDL_RenderCopy(renderer, tilemap_texture->get_texture(), &select_tile1, &tiles[x][y]);
          break;
        }
        case 2: {
          SDL_RenderCopy(renderer, tilemap_texture->get_texture(), &select_tile2, &tiles[x][y]);
          break;
        }
        case 3: {
          SDL_RenderCopy(renderer, tilemap_texture->get_texture(), &select_tile3, &tiles[x][y]);
          break;
        }
        case 4: {
          SDL_RenderCopy(renderer, tilemap_texture->get_texture(), &select_tile4, &tiles[x][y]);
          break;
        }
      }
    }
  }

  font->render();
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

    if(m_event->type == SDL_MOUSEMOTION) {
      for(Game_Entity* entity : entities) {
        if(entity->is_active) {
          entity->get_texture()->render_at_pos(xmouse, ymouse);
        }
      }
    }

    if(m_event->button.button == SDL_BUTTON_LEFT && m_event->type == SDL_MOUSEBUTTONDOWN) {
      for(Game_Entity* entity : entities) {
        if(entity->is_active) {
          for(Collider2D* collider: entity->get_colliders2D()) {
            if(collider->is_colliding(*entity1->get_collider2D(2))) {
              collision_sound->play_sound();
            }
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
  IMG_Quit();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

} // namespace sdlAPI
