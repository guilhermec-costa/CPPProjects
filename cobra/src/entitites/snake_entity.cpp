#include "snake_entity.h"

void Snake_Entity::render() const
{
	Texture_Component* texture_component = get_texture_component();
	if (texture_component != nullptr) {
		get_texture_component()->render();
	}

	for (const Collider2D* collider : m_colliders)
	{
		if (collider != nullptr)
		{
			collider->render(m_renderer);
		}
	}

	for (const Grid* grid : m_grids)
	{
		if (grid != nullptr)
		{
			grid->render(m_renderer);
		}
	}
	if (m_grids.size() > 0) {
		m_grids[0]->paint(m_renderer, m_grids[0]->get_rectangle(4), { 255, 255, 0, 255 });
	}
}