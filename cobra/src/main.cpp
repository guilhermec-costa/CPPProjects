#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Logger.h"
#include "Sdl_API.h"
#include "cobra_events.h"
#include "game_entity.h"

int main(int argc, char* args[])
{
	std::unique_ptr<Sdl_API> game = std::make_unique<Sdl_API>();

	if (game->check_integrity())
	{
		game->setup_window("COBRA", NULL, NULL, 1360, 768);
		game->setup_renderer(SDL_RENDERER_ACCELERATED);

		Game_Entity* yellow_apple = new Game_Entity(game->get_renderer());
		yellow_apple->add_texture_component("C:\\Users\\guico\\source\\repos\\cpp-fundamentals\\cobra\\assets\\yellow_apple.png", { 0xFF, 0, 0xF4, 0xFF });
		yellow_apple->get_texture_component()->set_src_fraction_rect(NULL);
		yellow_apple->get_texture_component()->set_render_target_rect(new Cobra_Rect(100, 40, 289, 320));
		yellow_apple->add_collider2D(yellow_apple->get_texture_component()->get_render_target_rect());
		yellow_apple->get_collider(0)->place_outline({ 255, 255, 0, SDL_ALPHA_OPAQUE });
		yellow_apple->get_texture_component()->scale(-.5f);

		Game_Entity* red_apple = new Game_Entity(game->get_renderer());
		red_apple->add_texture_component("C:\\Users\\guico\\source\\repos\\cpp-fundamentals\\cobra\\assets\\red_apple.png", { 0xFF, 0, 0xF4, 0xFF });
		red_apple->get_texture_component()->set_src_fraction_rect(NULL);
		red_apple->get_texture_component()->set_render_target_rect(new Cobra_Rect(400, 100, 289, 320));
		red_apple->add_collider2D(red_apple->get_texture_component()->get_render_target_rect());
		red_apple->get_collider(0)->place_outline({ 255, 0 , 254, SDL_ALPHA_OPAQUE });
		red_apple->get_texture_component()->scale(-.5f);

		Game_Entity* green_apple = new Game_Entity(game->get_renderer());
		green_apple->add_texture_component("C:\\Users\\guico\\source\\repos\\cpp-fundamentals\\cobra\\assets\\green_apple.png", { 0xFF, 0, 0xF4, 0xFF });
		green_apple->get_texture_component()->set_src_fraction_rect(NULL);
		green_apple->get_texture_component()->set_render_target_rect(new Cobra_Rect(698, 160, 289, 320));
		green_apple->get_texture_component()->scale(-.5f);
		green_apple->add_collider2D(green_apple->get_texture_component()->get_render_target_rect());

		Cobra_Rect* green_apple_rect = green_apple->get_texture_component()->get_render_target_rect();
		int new_w = green_apple_rect->m_dimensions.w;
		int new_h = green_apple_rect->m_dimensions.h / 2;
		green_apple->add_collider2D(new Cobra_Rect(
			green_apple_rect->m_position.x, green_apple_rect->m_position.y,
			green_apple_rect->m_dimensions.w * 2, new_h
		));
		green_apple->get_collider(0)->place_outline({ 255, 255 , 255, SDL_ALPHA_OPAQUE });
		green_apple->get_collider(1)->place_outline({ 255, 7, 120, SDL_ALPHA_OPAQUE });

		const std::vector<const Game_Entity*> entities = { yellow_apple, green_apple, red_apple };
		game->add_entities(entities);

		while (game->get_metadata().get_game_state() == Game_State::RUNNING)
		{
			game->handle_events();
			game->update();
			game->render();
		}
	}
	return 0;
}