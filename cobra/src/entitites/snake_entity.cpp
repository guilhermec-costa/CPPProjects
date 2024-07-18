#include "snake_entity.h"
#include <algorithm>
#include <iterator>

void Snake_Entity::render() const
{
	for (auto it = _m_rq.begin(); it != _m_rq.end(); ++it)
	{
		if(it == _m_rq.begin())
			SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
		else {
			SDL_SetRenderDrawColor(m_renderer, 0, 255, 0, 255);
		}
		SDL_RenderFillRect(m_renderer, &(*it));
	}
}

void Snake_Entity::check_food_collision(SDL_Rect* food)
{
	if (head_rect->is_colliding(food)) {
		apples_eaten++;
		m_length += 1.5;
		SDL_Rect* apple_rect = m_apple->get_collider(0)->get_dst_rect()->get_generated_SDL_rect();
		apple_rect->x = (rand() % (int)(800 - apple_rect->w * 1.5)) + 1;
		apple_rect->y = (rand() % (int)(600 - apple_rect->y * 1.5)) + 1;
		belly_effect();
	}
}

void Snake_Entity::update()
{
	adjust_snake();
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

void Snake_Entity::collide_itself()
{
	if (_m_rq.size() > 0)
	{
		SDL_Rect* _head_rect = head_rect->get_dst_rect()->get_generated_SDL_rect();
		for (auto it = std::next(_m_rq.begin()); it != _m_rq.end(); ++it) {
			if (_head_rect->x == it->x &&
				_head_rect->y == it->y) {
				game_over();
			}
		}
	}
}

void Snake_Entity::adjust_snake()
{
	SDL_Rect* _head_rect = head_rect->get_dst_rect()->get_generated_SDL_rect();
	if (_head_rect->x <= m_bounds.X_MIN) {
		_head_rect->x = m_bounds.X_MAX + 1;
		return;
	}
	if (_head_rect->x >= m_bounds.X_MAX) {
		_head_rect->x = m_bounds.X_MIN + 1;
		return;
	}
	if (_head_rect->y <= m_bounds.Y_MIN) {
		_head_rect->y = m_bounds.Y_MAX + 1;
		return;
	}
	if (_head_rect->y >= m_bounds.Y_MAX) {
		_head_rect->y = m_bounds.X_MIN + 1;
	}
}

void Snake_Entity::belly_effect()
{
	if (_m_rq.size() > 0)
	{
		for (size_t i = 0; i < _m_rq.size(); ++i)
		{
			_m_rq[i].h += 30;
		}
	}
}

void Snake_Entity::game_over()
{
	std::cout << "game over" << std::endl;
	m_is_game_over = true;
}

Snake_Entity::~Snake_Entity()
{
	delete head_rect;
}

void Snake_Entity::set_length(const unsigned int length) { m_length = length; }
void Snake_Entity::set_direction(const Snake_Direction direction) { m_direction = direction; }
