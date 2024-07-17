#include "snake_entity.h"

void Snake_Entity::render() const
{
	Texture_Component* texture_component = get_texture_component();
	if (texture_component != nullptr) {
		get_texture_component()->render();
	}

	for (auto& collider: m_colliders)
	{
		if (collider != nullptr)
		{
			collider->render(m_renderer);
		}
	}


	if (!m_grids.empty()) {
		Grid* main_grid = m_grids[0];
		for (unsigned i = 0; i < m_length; ++i) {
			SDL_Rect* rect = get_grid(0)->get_rectangle(i);
			if (i == 0) {
				main_grid->paint(m_renderer, rect, { 255, 0, 0, 255 });
			}
			else {
				main_grid->paint(m_renderer, rect, { 0, 255, 0, 255 });
			}
		}
	}

	for (auto& grid: m_grids)
	{
		if (grid != nullptr)
		{
			grid->render(m_renderer);
		}
	}
}

void Snake_Entity::add_grid(Grid* grid)
{
	m_grids.push_back(grid);
}

Grid* Snake_Entity::get_grid(const unsigned int index) const
{
	return m_grids[index];
}

void Snake_Entity::set_length(const unsigned int length)
{
	m_length = length;
}

void Snake_Entity::set_direction(const Snake_Direction direction)
{
	m_direction = direction;
}

void Snake_Entity::update()
{
	if (m_grids.empty()) return;
	Grid* main_grid = get_grid(0);
	int cell_width = main_grid->m_cell_width;
	int cell_height = main_grid->m_cell_height;

	// move each snake rect to the previous snake rect
	for (int i = m_length; i > 0; --i)
	{
		const SDL_Rect* prev_rect = main_grid->get_rectangle(i - 1);
		SDL_Rect* current_rect = main_grid->get_rectangle(i);
		current_rect->x = prev_rect->x;
		current_rect->y = prev_rect->y;
	}

	// Update the head based on the current direction
	SDL_Rect* snake_head_rect = main_grid->get_rectangle(0);
	switch (m_direction)
	{
	case UP:
		snake_head_rect->y -= cell_height;
		break;
	case DOWN:
		snake_head_rect->y += cell_height;
		break;
	case LEFT:
		snake_head_rect->x -= cell_width;
		break;
	case RIGHT:
		snake_head_rect->x += cell_width;
		break;
	}
	if (snake_head_rect->x < 0) snake_head_rect->x = 200;
	if (snake_head_rect->y < 0) snake_head_rect->y = 0;
	if (snake_head_rect->x >= main_grid->m_width) snake_head_rect->x = main_grid->m_width - cell_width;
	if (snake_head_rect->y >= main_grid->m_height) snake_head_rect->y = main_grid->m_height - cell_height;
}

Snake_Entity::~Snake_Entity()
{
	for (auto& grid : m_grids)
	{
		delete grid;
	}
}