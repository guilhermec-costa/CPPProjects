#pragma once
#include "game_entity.h"

enum Snake_Direction {
	UP = 'U',
	DOWN = 'D',
	LEFT = 'L',
	RIGHT = 'R'
};

class Snake_Entity : public Game_Entity
{
public:
	Snake_Entity(SDL_Window* window, SDL_Renderer* renderer, const unsigned length)
		: Game_Entity(window, renderer), m_length(length), m_direction(Snake_Direction::DOWN) {};
	void render() const override;
	void update();
	void add_grid(Grid* grid);
	Grid* get_grid(const unsigned int index) const;
	void set_length(const unsigned int length);
	void set_direction(const Snake_Direction direction);
	inline Snake_Direction get_direction() const
	{
		return m_direction;
	};
private:
	std::vector<Grid*> m_grids;
	unsigned int m_length;
	Snake_Direction m_direction;
};
