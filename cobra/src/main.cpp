#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Logger.h"
#include "Sdl_API.h"

int main(int argc, char* args[])
{
	std::unique_ptr<IGame> sdlAPI = std::make_unique<Sdl_API>();
	while (sdlAPI->get_metadata().get_game_state() == Game_State::RUNNING)
	{
		sdlAPI->handle_events();
	}
	sdlAPI->terminate();
	return 0;
}