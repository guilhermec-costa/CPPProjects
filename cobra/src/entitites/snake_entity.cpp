#include "snake_entity.h"
#include <algorithm>

void Snake_Entity::render() const
{
	SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
	std::for_each(_m_rq.begin(), _m_rq.end(), [&](auto& segment)
		{
			SDL_RenderFillRect(m_renderer, &segment);
		});
}

bool Snake_Entity::check_food_collision(SDL_Rect* food)
{
	//if (head_rect->get_dst_rect()->get_generated_SDL_rect()->x == food->x && head_rect->get_dst_rect()->get_generated_SDL_rect()->y == food->y) {
	if(head_rect->is_colliding(food)) {
		m_length++;
		std::cout << rand() << std::endl;
		m_apple->get_collider(0)->get_dst_rect()->get_generated_SDL_rect()->x = (rand() % 1330) + 1;
		m_apple->get_collider(0)->get_dst_rect()->get_generated_SDL_rect()->y = (rand() % 730) + 1;
		return true;
	}
	return false;
}

void Snake_Entity::update()
{
	check_food_collision(m_apple->get_texture_component()->get_render_target_rect()->get_generated_SDL_rect());
	collide_itself();
	switch (m_direction)
	{
	case UP:
		head_rect->get_dst_rect()->get_generated_SDL_rect()->y -= 10;
		break;
	case DOWN:
		head_rect->get_dst_rect()->get_generated_SDL_rect()->y += 10;
		break;
	case LEFT:
		head_rect->get_dst_rect()->get_generated_SDL_rect()->x -= 10;
		break;
	case RIGHT:
		head_rect->get_dst_rect()->get_generated_SDL_rect()->x += 10;
		break;
	}
	_m_rq.push_front(*head_rect->get_dst_rect()->get_generated_SDL_rect());
	while (_m_rq.size() > m_length)
	{
		_m_rq.pop_back();
	}
}

bool Snake_Entity::collide_itself()
{
	std::for_each(_m_rq.begin(), _m_rq.end(), [&](auto& segment) {
		if (head_rect->get_dst_rect()->get_generated_SDL_rect()->x == segment.x && head_rect->get_dst_rect()->get_generated_SDL_rect()->y == segment.y)
		{
			//m_length = 1;
		}
		});
	return false;
}

void Snake_Entity::game_over()
{
	std::cout << "game over" << std::endl;
	m_is_game_over = false;
}

Snake_Entity::~Snake_Entity()
{
	delete head_rect;
}

void Snake_Entity::set_length(const unsigned int length) { m_length = length; }
void Snake_Entity::set_direction(const Snake_Direction direction) { m_direction = direction; }
