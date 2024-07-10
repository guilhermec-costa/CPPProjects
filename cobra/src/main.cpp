#include <iostream>
#include <SDL2/SDL.h>
#include "Logger.h"

#define COBRA_SUBSYSTEMS SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER

int main(int argc, char* args[])
{
	Logger logger;
	if (SDL_Init(COBRA_SUBSYSTEMS) == 0)
	{
		logger.log_err("Failed to initialize SDL Video Subsystems");
	}
	return 0;
}