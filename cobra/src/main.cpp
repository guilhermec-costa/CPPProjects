#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "entitites/texture_entity.h"
#include "entitites/snake_entity.h"
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
		game->set_max_framerate(60);

		Snake_Entity* snake_entity = new Snake_Entity(game->get_window(), game->get_renderer(), 5);
		Grid* snake_grid = new Grid(0, 0, game->get_win_dimensions().x, game->get_win_dimensions().y, 32, 32);
		snake_entity->add_grid(snake_grid);
		game->set_active_snake(snake_entity);

		Texture_Entity* yellow_apple = new Texture_Entity(game->get_window(), game->get_renderer());
		yellow_apple->add_texture_component("C:\\Users\\guico\\source\\repos\\cpp-fundamentals\\cobra\\assets\\yellow_apple.png", { 0xFF, 0, 0xF4, 0xFF });
		yellow_apple->get_texture_component()->set_src_fraction_rect(NULL);
		yellow_apple->get_texture_component()->set_render_target_rect(new Cobra_Rect(100, 40, 64, 64));
		yellow_apple->add_collider2D(yellow_apple->get_texture_component()->get_render_target_rect());

		Texture_Entity* red_apple = new Texture_Entity(game->get_window(), game->get_renderer());
		red_apple->add_texture_component("C:\\Users\\guico\\source\\repos\\cpp-fundamentals\\cobra\\assets\\red_apple.png", { 0xFF, 0, 0xF4, 0xFF });
		red_apple->get_texture_component()->set_src_fraction_rect(NULL);
		red_apple->get_texture_component()->set_render_target_rect(new Cobra_Rect(400, 100, 64, 64));
		red_apple->add_collider2D(red_apple->get_texture_component()->get_render_target_rect());

		Game_Entity* green_apple = new Texture_Entity(game->get_window(), game->get_renderer());
		green_apple->add_texture_component("C:\\Users\\guico\\source\\repos\\cpp-fundamentals\\cobra\\assets\\green_apple.png", { 0xFF, 0, 0xF4, 0xFF });
		green_apple->get_texture_component()->set_src_fraction_rect(NULL);
		green_apple->get_texture_component()->set_render_target_rect(new Cobra_Rect(698, 160, 64, 64));
		green_apple->add_collider2D(green_apple->get_texture_component()->get_render_target_rect());

		const std::vector<const Game_Entity*> entities = { yellow_apple, green_apple, red_apple, snake_entity };
		game->add_entities(entities);

		while (game->get_metadata()->get_game_state() == Game_State::RUNNING ||
			game->get_metadata()->get_game_state() == Game_State::PAUSED)
		{
			game->handle_events();
			game->update();
			game->render();
		}
	}
	return 0;
}