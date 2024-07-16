#include "components/grid.h"
#include "iostream"

Grid::Grid(SDL_Renderer* renderer, const unsigned int x, const unsigned int y,
	const unsigned int width, const unsigned int height,
	const unsigned int cell_width, const unsigned int cell_height
) : m_x(x), m_y(x), m_width(width), m_height(height)
{
	int m_grid_area = width * height;
	int cell_area = cell_width * cell_height;
	m_cell_units = m_grid_area / cell_area;

	int x_counter = 0, y_counter = 0;
	for (int i = 0; i <= m_grid_area / sizeof(int); i++, x_counter += 32)
	{
		if (x_counter >= 1360) {
			x_counter = 0;
			y_counter += 32;
		}
		Collider2D* test_collider = new Collider2D(new Cobra_Rect(x_counter, y_counter, 32, 32));
		test_collider->place_outline({ 0xA6, 0xA6, 0xA6, SDL_ALPHA_OPAQUE });
		m_colliders.push_back(test_collider);
	}
};

Grid::~Grid()
{
	for (const Collider2D* collider : m_colliders)
	{
		delete collider;
	}
}

std::ostream& operator<<(std::ostream& stream, const Grid& grid)
{
	stream << grid.m_cell_units;
	return stream;
}

void Grid::render(SDL_Renderer* renderer) const
{
	for (const Collider2D* collider : m_colliders)
	{
		collider->render(renderer);
	}
}

