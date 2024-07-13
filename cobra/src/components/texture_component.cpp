#include "components/texture_component.h"
#include "asset_manager.h"
#include <SDL2/SDL_pixels.h>

Uint32 RGBA::format() const
{
	Uint32 color = this->R;
	color <<= 8;
	color += this->G;
	color <<= 8;
	color += this->B;
	color <<= 8;
	color += this->A;

	return color;
}

Texture_Component::Texture_Component(SDL_Renderer* renderer, const char* path, RGBA mask)
	: bg_mask(mask), m_dimensions({ 32, 32 }), m_position({ 0, 0 }),
	m_src_fraction_rect(NULL), m_render_target_rect(NULL), m_renderer(renderer)
{
	SDL_Surface* surface_path = Asset_Manager::get_instance().get_asset(path);
	SDL_SetColorKey(surface_path, SDL_TRUE, SDL_MapRGBA(surface_path->format, mask.R, mask.G, mask.B, mask.A));
	m_texture = SDL_CreateTextureFromSurface(get_renderer(), surface_path);
}

void Texture_Component::render() {
	SDL_RenderCopy(m_renderer, m_texture, m_src_fraction_rect, m_render_target_rect);
}

SDL_Renderer* Texture_Component::get_renderer() const {
	return m_renderer;
}
