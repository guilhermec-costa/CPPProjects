#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Logger.h"
#include "Sdl_API.h"
#include "cobra_events.h"

int main(int argc, char* args[])
{
	std::unique_ptr<Sdl_API> sdlAPI = std::make_unique<Sdl_API>();
	if (sdlAPI->check_integrity())
	{
		sdlAPI->setup_window("COBRA", NULL, NULL, 1360, 768);
		sdlAPI->setup_renderer(SDL_RENDERER_ACCELERATED);
		while (sdlAPI->get_metadata().get_game_state() == Game_State::RUNNING)
		{
			sdlAPI->handle_events();
			sdlAPI->update();
			sdlAPI->render();
		}
	}
	sdlAPI->terminate();
	return 0;
}