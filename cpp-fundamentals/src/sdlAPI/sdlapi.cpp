#include "Game.hpp"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include "sdlapi.h"

namespace sdlAPI {

	void run() {
		Game game;
		game.set_max_framerate(60);
		game.start();
		while (game.get_state()) {
			game.treat_events();
			game.update();
			game.render();
		}

		game.finish();

	}
} // namespace sdlgame
