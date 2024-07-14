#include "components/collider2d.h"

Collider2D::Collider2D(SDL_Renderer* renderer, Cobra_Rect* rect)
	: m_dst_rect(rect), m_renderer(renderer)
{}

Collider2D::~Collider2D()
{
	delete m_dst_rect;
}

bool Collider2D::is_colliding(const SDL_Rect* other) const
{
	return SDL_HasIntersection(m_dst_rect->get_generated_SDL_rect(), other);
}

void Collider2D::render() const
{
	SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawRect(m_renderer, m_dst_rect->get_generated_SDL_rect());
}