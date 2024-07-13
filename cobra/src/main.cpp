#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Logger.h"
#include "Sdl_API.h"
#include "cobra_events.h"
#include "game_entity.h"

int main(int argc, char* args[])
{
	std::unique_ptr<Sdl_API> sdlAPI = std::make_unique<Sdl_API>();

	if (sdlAPI->check_integrity())
	{
		sdlAPI->setup_window("COBRA", NULL, NULL, 1360, 768);
		sdlAPI->setup_renderer(SDL_RENDERER_ACCELERATED);

		Game_Entity* yellow_apple = new Game_Entity(sdlAPI->get_renderer());
		yellow_apple->add_texture_component(
			"C:\\Users\\guico\\source\\repos\\cpp-fundamentals\\cobra\\assets\\foods.png",
			{ 0xFF, 0, 0xF4, 0xFF }
		);
		yellow_apple->get_texture_component()->set_src_fraction_rect(new Cobra_Rect(0, 0, 266, 300));
		yellow_apple->get_texture_component()->set_render_target_rect(new Cobra_Rect(10, 10, 266, 300));
		sdlAPI->add_entity(yellow_apple);

		while (sdlAPI->get_metadata().get_game_state() == Game_State::RUNNING)
		{
			sdlAPI->handle_events();
			sdlAPI->update();
			sdlAPI->render();
		}
	}
	return 0;
}