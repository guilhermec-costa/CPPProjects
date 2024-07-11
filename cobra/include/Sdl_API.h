#pragma once
#include "IGame.h"
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_events.h>

#define COBRA_SUBSYSTEMS (SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)

class Sdl_API: public IGame {
public:
	Sdl_API();
	void play() override;
	void render() override;
	void update() override;
	void terminate() override;
	void handle_events() override;
private:
	void setup_window(const char* title, int w, int h);
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Event* m_event_src;
};
