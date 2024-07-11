#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Logger.h"
#include "Sdl_API.h"

int main(int argc, char* args[])
{
	IGame* sdlAPI = new Sdl_API();
	SDL_Delay(7000);
	return 0;
}