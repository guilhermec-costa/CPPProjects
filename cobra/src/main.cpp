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
	srand(time(NULL));

	if (game->check_integrity())
	{
		game->setup_window("COBRA", NULL, NULL, 800, 600);
		game->setup_renderer(SDL_RENDERER_ACCELERATED);
		game->set_max_framerate(60);

		Snake_Entity* snake_entity = new Snake_Entity(game->get_window(), game->get_renderer(), new Collider2D(new Cobra_Rect{100, 100, 28, 28}), 5);
		snake_entity->set_bounds({ 0, game->get_win_dimensions().x, 0, game->get_win_dimensions().y });
		game->set_active_snake(snake_entity);

		Texture_Entity* red_apple = new Texture_Entity(game->get_window(), game->get_renderer());
		red_apple->add_texture_component("C:\\Users\\guico\\source\\repos\\cpp-fundamentals\\cobra\\assets\\red_apple.png", { 0xFF, 0, 0xF4, 0xFF });
		red_apple->get_texture_component()->set_src_fraction_rect(NULL);
		red_apple->get_texture_component()->set_render_target_rect(new Cobra_Rect(400, 100, 44, 44));
		red_apple->add_collider2D(red_apple->get_texture_component()->get_render_target_rect());
		snake_entity->add_food(red_apple);

		const std::vector<const Game_Entity*> entities = { red_apple, snake_entity };
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