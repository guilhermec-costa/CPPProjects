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
		yellow_apple->add_texture_component("C:\\Users\\guico\\source\\repos\\cpp-fundamentals\\cobra\\assets\\foods.png",{ 0xFF, 0, 0xF4, 0xFF });
		yellow_apple->get_texture_component()->set_src_fraction_rect(new Cobra_Rect(0, 0, 241, 320));
		yellow_apple->get_texture_component()->set_render_target_rect(new Cobra_Rect(100, 40, 241, 300));
		yellow_apple->add_collider2D(yellow_apple->get_texture_component()->get_render_target_rect());
		yellow_apple->get_collider_component()->place_outline({ 255, 255, 0, SDL_ALPHA_OPAQUE });

		Game_Entity* red_apple = new Game_Entity(sdlAPI->get_renderer());
		red_apple->add_texture_component("C:\\Users\\guico\\source\\repos\\cpp-fundamentals\\cobra\\assets\\foods.png", { 0xFF, 0, 0xF4, 0xFF });
		red_apple->get_texture_component()->set_src_fraction_rect(new Cobra_Rect(242, 0, 241, 320));
		red_apple->get_texture_component()->set_render_target_rect(new Cobra_Rect(350, 40, 241, 300));
		red_apple->add_collider2D(red_apple->get_texture_component()->get_render_target_rect());
		red_apple->get_collider_component()->place_outline({ 255, 0 , 0, SDL_ALPHA_OPAQUE });

		Game_Entity* green_apple = new Game_Entity(sdlAPI->get_renderer());
		green_apple->add_texture_component("C:\\Users\\guico\\source\\repos\\cpp-fundamentals\\cobra\\assets\\foods.png",{ 0xFF, 0, 0xF4, 0xFF });
		green_apple->get_texture_component()->set_src_fraction_rect(new Cobra_Rect(484, 0, 241, 320));
		green_apple->get_texture_component()->set_render_target_rect(new Cobra_Rect(592, 100, 120, 150));
		green_apple->add_collider2D(green_apple->get_texture_component()->get_render_target_rect());
		green_apple->get_collider_component()->place_outline({ 0, 255 , 0, SDL_ALPHA_OPAQUE });

		const std::vector<const Game_Entity*> entities = { yellow_apple, green_apple, red_apple };
		sdlAPI->add_entities(entities);

		while (sdlAPI->get_metadata().get_game_state() == Game_State::RUNNING)
		{
			sdlAPI->update();
			sdlAPI->render();
			sdlAPI->handle_events();
		}
	}
	return 0;
}