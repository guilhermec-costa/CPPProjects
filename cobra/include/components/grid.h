#pragma once
#include <SDL2/SDL_render.h>
#include <SDL2/SDL.h>
#include "components/grid.h"
#include "components/collider2d.h"
#include <iostream>
#include <vector>

class Grid {
public:
	Grid(const unsigned int x, const unsigned int y,
		const unsigned int width, const unsigned int height,
		const unsigned int cell_width, const unsigned int cell_height
	);
	~Grid();
	void render(SDL_Renderer* renderer) const;
	void paint(SDL_Renderer* renderer, const SDL_Rect* rect, RGBA color) const;
	unsigned int m_width;
	unsigned int m_height;
	unsigned int m_x;
	unsigned int m_y;
	unsigned int m_cell_units;
	const SDL_Rect* get_rectangle(const unsigned int index) const;
private:
	std::vector<Collider2D*> m_colliders;
};

std::ostream& operator<<(std::ostream& stream, const Grid& grid);
