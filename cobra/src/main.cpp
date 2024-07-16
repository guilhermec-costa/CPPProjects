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
		Grid* grid = new Grid(0, 0, game->get_win_dimensions().x, game->get_win_dimensions().y, 40, 40);

		Game_Entity* snake_entity = new Game_Entity(game->get_window(), game->get_renderer());
		Vector2 window_dimension = game->get_win_dimensions();
		snake_entity ->add_grid(grid);

		Game_Entity* yellow_apple = new Game_Entity(game->get_window(), game->get_renderer());
		yellow_apple->add_texture_component("C:\\Users\\guico\\source\\repos\\cpp-fundamentals\\cobra\\assets\\yellow_apple.png", { 0xFF, 0, 0xF4, 0xFF });
		yellow_apple->get_texture_component()->set_src_fraction_rect(NULL);
		yellow_apple->get_texture_component()->set_render_target_rect(new Cobra_Rect(100, 40, 64, 64));
		yellow_apple->add_collider2D(yellow_apple->get_texture_component()->get_render_target_rect());

		Game_Entity* red_apple = new Game_Entity(game->get_window(), game->get_renderer());
		red_apple->add_texture_component("C:\\Users\\guico\\source\\repos\\cpp-fundamentals\\cobra\\assets\\red_apple.png", { 0xFF, 0, 0xF4, 0xFF });
		red_apple->get_texture_component()->set_src_fraction_rect(NULL);
		red_apple->get_texture_component()->set_render_target_rect(new Cobra_Rect(400, 100, 64, 64));
		red_apple->add_collider2D(red_apple->get_texture_component()->get_render_target_rect());
		//red_apple->get_collider(0)->place_outline({ 255, 255 , 255, SDL_ALPHA_OPAQUE });
		//red_apple->get_texture_component()->scale(-.5f);

		Game_Entity* green_apple = new Game_Entity(game->get_window(), game->get_renderer());
		green_apple->add_texture_component("C:\\Users\\guico\\source\\repos\\cpp-fundamentals\\cobra\\assets\\green_apple.png", { 0xFF, 0, 0xF4, 0xFF });
		green_apple->get_texture_component()->set_src_fraction_rect(NULL);
		green_apple->get_texture_component()->set_render_target_rect(new Cobra_Rect(698, 160, 64, 64));
		//green_apple->get_texture_component()->scale(-.5f);
		green_apple->add_collider2D(green_apple->get_texture_component()->get_render_target_rect());
		//green_apple->get_collider(0)->place_outline({ 255, 255 , 255, SDL_ALPHA_OPAQUE });

		const std::vector<const Game_Entity*> entities = { yellow_apple, green_apple, red_apple, snake_entity};
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