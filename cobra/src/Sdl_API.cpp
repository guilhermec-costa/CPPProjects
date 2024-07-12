#include "Sdl_API.h"
#include "Logger.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "asset_manager.h"


Sdl_API::Sdl_API()
	: m_window(nullptr), m_event_src(new SDL_Event())
{
	init_subsystems();
	get_metadata().set_game_state(Game_State::RUNNING);
	init_event_handlers();
	setup_renderer(SDL_RENDERER_ACCELERATED);
	m_integrity = HEALTH;
	std::string msg = "SDL API started";
	Logger::s_get_instance().log(msg);
	Asset_Manager::get_instance().load_asset("C:\\Users\\guico\\source\\repos\\cpp-fundamentals\\cobra\\assets\\foods.png");
}

void Sdl_API::init_event_handlers()
{
	m_events.quit_event = _quit_event;
}

void Sdl_API::init_subsystems()
{
	if (SDL_Init(COBRA_SUBSYSTEMS) != 0)
	{
		m_integrity = NOT_HEALTH;
		std::string msg = "Failed to initalize SDL Video Subsystems";
		Logger::s_get_instance().log_err(msg);
	}

	if (TTF_Init() != 0)
	{
		m_integrity = NOT_HEALTH;
		std::string msg = "Failed to initialize SDL Font system";
		Logger::s_get_instance().log_err(msg);
	}
}

void Sdl_API::setup_window(const char* title, int x, int y, int w, int h)
{
	if (x == NULL) x = SDL_WINDOWPOS_CENTERED;
	if (y == NULL) y = SDL_WINDOWPOS_CENTERED;
	m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
	if (m_window == nullptr) {
		m_integrity = NOT_HEALTH;
		std::string message;
		message += "Failed to created SDL window. Message -> ";
		message.append(SDL_GetError());
		Logger::s_get_instance().log_err(message);
	}
}

void Sdl_API::setup_renderer(SDL_RendererFlags flags)
{
	if (flags == NULL) flags = SDL_RENDERER_PRESENTVSYNC;
	if (m_window == nullptr) return;
	m_renderer = SDL_CreateRenderer(m_window, -1, flags);
	if (m_renderer == nullptr) {
		m_integrity = NOT_HEALTH;
		std::string message;
		message += "Failed to created SDL Renderer. Message -> ";
		message.append(SDL_GetError());
		Logger::s_get_instance().log_err(message);
	}
}

inline SDL_Renderer& Sdl_API::get_renderer() const {
	return *m_renderer;
}

inline SDL_Window& Sdl_API::get_window() const {
	return *m_window;
}

void Sdl_API::render()
{
	SDL_RenderClear(m_renderer);
	SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);

	SDL_RenderPresent(m_renderer);
}

void Sdl_API::terminate()
{
	m_events.quit_event();
	get_metadata().set_game_state(Game_State::TERMINATED);
}

void Sdl_API::update()
{
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

bool Sdl_API::check_integrity() const {
	return m_integrity;
}
