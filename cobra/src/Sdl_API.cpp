#include "Sdl_API.h"
#include "Logger.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "cobra_events.h"

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

	m_event_src = new SDL_Event();

	setup_window("my window", NULL, NULL, 800, 600);
	get_metadata().set_game_state(Game_State::RUNNING);
	init_event_handlers();
	std::cout << "SDL API started" << std::endl;
}

void Sdl_API::init_event_handlers()
{
	Cobra_EVENTS.quit_event = _quit_event;
}

void Sdl_API::setup_window(const char* title, int x, int y, int w, int h)
{
	if (x == NULL) x = SDL_WINDOWPOS_CENTERED;
	if (y == NULL) y = SDL_WINDOWPOS_CENTERED;
	m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
	if (m_window == nullptr) {
		is_health = false;
		Logger::s_get_instance().log_err("Failed to created SDL window");
	}
}

void Sdl_API::render()
{
	std::cout << "rendering frames" << std::endl;
}

void Sdl_API::terminate()
{
	Cobra_EVENTS.quit_event();
	get_metadata().set_game_state(Game_State::TERMINATED);
}

void Sdl_API::update()
{
	std::cout << "updating game state" << std::endl;
}

void Sdl_API::handle_events()
{
	while (SDL_PollEvent(m_event_src))
	{
		switch (m_event_src->type)
		{
		case SDL_QUIT:
			terminate();
		}
	}
}
