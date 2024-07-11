#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Logger.h"
#include "Sdl_API.h"

int main(int argc, char* args[])
{
	IGame* sdlAPI = new Sdl_API();
	while (sdlAPI->get_metadata().get_game_state() == Game_State::RUNNING)
	{
		std::cout << "Hello game" << std::endl;
	}
	sdlAPI->terminate();
	return 0;
}