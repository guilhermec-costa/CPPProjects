#include "snake_entity.h"
#include <algorithm>
#include <iterator>

void Snake_Entity::render() const
{
	if (_m_rq.size() > 0) {

		int width = _m_rq[0].w, height = _m_rq[0].h;
		Uint32* buffer = new Uint32[width * height];
		for (auto it = _m_rq.begin(); it != _m_rq.end(); ++it)
		{
			for (int i = 0; i < width * height; i++) {
				if(it == _m_rq.begin()) buffer[i] = 0xFF0000FF;
				else buffer[i] = 0x00FF00FF;
			}
			SDL_Texture* texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, width, height);
			SDL_UpdateTexture(texture, NULL, buffer, sizeof(Uint32) * width);
			SDL_RenderCopy(m_renderer, texture, NULL, &(*it));
			SDL_DestroyTexture(texture);
		}

		delete[] buffer;
	}
}

void Snake_Entity::check_food_collision(SDL_Rect* food)
{
	if (head_rect->is_colliding(food)) {
		belly_effect();
		apples_eaten++;
		m_length += 2.5;
		SDL_Rect* apple_rect = m_apple->get_collider(0)->get_dst_rect()->get_generated_SDL_rect();
		apple_rect->x = (rand() % (int)(800 - apple_rect->w * 1.5)) + 1;
		apple_rect->y = (rand() % (int)(600 - apple_rect->y * 1.5)) + 1;
	}
}

void Snake_Entity::update()
{
	adjust_snake();
	check_food_collision(m_apple->get_texture_component()->get_render_target_rect()->get_generated_SDL_rect());
	collide_itself();
	if (is_expanding) {
		int body_counter = 0;
		const int max_animation_frames = 15;
		const float expansion_amount = 1;
		const float max_expansion = 3.0;
		float expansion_step = (animation_progress < max_animation_frames / 2.5) ? expansion_amount : -expansion_amount;
		if (animation_progress < max_animation_frames) {
			for (auto& segment : _m_rq) {
				if (m_direction == Snake_Direction::RIGHT || m_direction == Snake_Direction::LEFT) {
					segment.y += (expansion_step / max_animation_frames) * max_expansion;
				}
				else if (m_direction == Snake_Direction::UP || m_direction == Snake_Direction::DOWN) {
					segment.x += (expansion_step / max_animation_frames) * max_expansion;
				}
			}
			animation_progress++;
		}
		else {
			is_expanding = false;
			animation_progress = 0;  // Reset the progress for the next expansion
		}
	}
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
		is_expanding = true;
		animation_progress = 0;
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
