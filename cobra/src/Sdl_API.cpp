#include "Sdl_API.h"
#include "Logger.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

Sdl_API::Sdl_API()
	: m_window(nullptr)
{
	if (SDL_Init(COBRA_SUBSYSTEMS) != 0)
	{
		Logger::s_get_instance().log_err("Failed to initialize SDL Video Subsystems");
	}

	if (TTF_Init() != 0)
	{
		Logger::s_get_instance().log_err("Failed to initialize SDL_TTF system");
	}

	setup_window("my window", 800, 600);
	get_metadata().set_game_state(Game_State::RUNNING);
	std::cout << "SDL API started" << std::endl;
}

void Sdl_API::setup_window(const char* title, int w, int h)
{
	m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
}

void Sdl_API::play()
{
	std::cout << "playing sound" << std::endl;
}

void Sdl_API::render()
{
	std::cout << "rendering frames" << std::endl;
}

void Sdl_API::terminate()
{
	std::cout << "terminating game" << std::endl;
}

void Sdl_API::update()
{
	std::cout << "updating game state" << std::endl;
}

void Sdl_API::event_cb()
{
	std::cout << "managing events callback" << std::endl;
}
