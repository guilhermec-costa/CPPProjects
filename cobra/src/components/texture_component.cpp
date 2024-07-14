#include "components/texture_component.h"
#include "asset_manager.h"
#include <SDL2/SDL_pixels.h>
#include "iostream"

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

Cobra_Rect::Cobra_Rect(
	int x = 0, int y = 0,
	int w = 32, int h = 32
)
{
	this->m_position.set(x, y);
	this->m_dimensions.set(w, h);
	this->generate_SDL_rect();
}

void Cobra_Rect::Dimensions::set(int w, int h)
{
	this->w = w;
	this->h = h;
}

void Cobra_Rect::Position::set(int xpos, int ypos)
{
	x = xpos;
	y = ypos;
}

void Cobra_Rect::generate_SDL_rect()
{
	m_SDL_rect = new SDL_Rect{
		this->m_position.x,
		this->m_position.y,
		this->m_dimensions.w,
		this->m_dimensions.h
	};
}

inline SDL_Rect* Cobra_Rect::get_generated_SDL_rect() const
{
	return m_SDL_rect;
}

Texture_Component::Texture_Component(SDL_Renderer* renderer, const char* path, RGBA mask)
	: bg_mask(mask), m_src_fraction_rect(new Cobra_Rect()), m_render_target_rect(new Cobra_Rect()), m_renderer(renderer)
{
	SDL_Surface* surface_path = Asset_Manager::get_instance().get_asset(path);
	SDL_SetColorKey(surface_path, SDL_TRUE, SDL_MapRGBA(surface_path->format, mask.R, mask.G, mask.B, mask.A));
	m_texture = SDL_CreateTextureFromSurface(get_renderer(), surface_path);
}

void Texture_Component::render()
{
	SDL_RenderCopy(m_renderer, m_texture, m_src_fraction_rect->get_generated_SDL_rect(), m_render_target_rect->get_generated_SDL_rect());
}


Cobra_Rect* Texture_Component::get_src_fraction_rect() const
{
	return m_src_fraction_rect;
}
Cobra_Rect* Texture_Component::get_render_target_rect() const
{
	return m_render_target_rect;
}

void Texture_Component::set_src_fraction_rect(Cobra_Rect* const src_rect)
{
	*m_src_fraction_rect = *src_rect;
	delete src_rect;
};

void Texture_Component::set_render_target_rect(Cobra_Rect* const dst_rect)
{
	*m_render_target_rect = *dst_rect;
	delete dst_rect;
}

inline SDL_Renderer* Texture_Component::get_renderer() const
{
	return m_renderer;
}

inline SDL_Texture* Texture_Component::get_texture() const {
	return m_texture;
}
