#include "components/grid.h"
#include "iostream"

Grid::Grid(const unsigned int x, const unsigned int y,
	const unsigned int width, const unsigned int height,
	const unsigned int cell_width, const unsigned int cell_height
) : m_x(x), m_y(x), m_width(width), m_height(height), m_cell_width(cell_width), m_cell_height(cell_height)
{
	int m_grid_area = width * height;
	int cell_area = cell_width * cell_height;
	m_cell_units = m_grid_area / cell_area;

	int x_counter = 0, y_counter = 0;
	for (int i = 0; i <= m_grid_area / sizeof(int); i++, x_counter += cell_width)
	{
		if (x_counter >= width) {
			x_counter = 0;
			y_counter += cell_height;
		}
		Collider2D* test_collider = new Collider2D(new Cobra_Rect(x_counter, y_counter, cell_width, cell_height));
		test_collider->place_outline({ 0x1a, 0x1a, 0x1a, 0xff });
		m_colliders.push_back(test_collider);
	}
};

Grid::~Grid()
{
	for (const Collider2D* collider : m_colliders)
		delete collider;
}

std::ostream& operator<<(std::ostream& stream, const Grid& grid)
{
	stream << grid.m_cell_units;
	return stream;
}

void Grid::render(SDL_Renderer* renderer) const
{
	for (const Collider2D* collider : m_colliders)
		collider->render(renderer);
}

void Grid::paint(SDL_Renderer* renderer, const SDL_Rect* rect, RGBA color) const
{
	SDL_SetRenderDrawColor(renderer, color.R, color.G, color.B, color.A);
	SDL_RenderFillRect(renderer, rect);
}

SDL_Rect* Grid::get_rectangle(const unsigned int index) const { return m_colliders[index]->get_dst_rect()->get_generated_SDL_rect(); }
