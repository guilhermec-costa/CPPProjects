#pragma once
#include "game_entity.h"
#include "texture_entity.h"
#include <deque>

enum Snake_Direction {
	UP = 'U',
	DOWN = 'D',
	LEFT = 'L',
	RIGHT = 'R'
};

typedef struct Bounds {
	int X_MIN;
	int X_MAX;
	int Y_MIN;
	int Y_MAX;
};

class Snake_Entity : public Game_Entity
{
public:
	Snake_Entity(SDL_Window* window, SDL_Renderer* renderer, Collider2D* head_rect, const unsigned length)
		: Game_Entity(window, renderer), m_length(length), m_direction(Snake_Direction::DOWN), head_rect(head_rect), m_apple(nullptr),
		m_is_game_over(false), m_bounds({}) {};
	~Snake_Entity();
	void render() const override;
	void update();
	bool check_food_collision(SDL_Rect* apple);
	bool collide_itself();
	inline void add_food(Texture_Entity* rect) {
		m_apple = rect;
	};
	void game_over();
	void set_length(const unsigned int length);
	void set_direction(const Snake_Direction direction);
	inline void set_bounds(const Bounds bounds) { m_bounds = bounds; };
	inline Snake_Direction get_direction() const
	{
		return m_direction;
	};
	inline int get_length() const
	{
		return m_length;
	}
private:
	bool m_is_game_over;
	unsigned int m_length;
	Snake_Direction m_direction;
	Bounds m_bounds;
	Collider2D* head_rect;
	Texture_Entity* m_apple;
	std::deque<SDL_Rect> _m_rq;
};
