#pragma once
#include "components/texture_component.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

class Collider2D {
public:
	Collider2D(SDL_Renderer*, Cobra_Rect*);
	~Collider2D();
	bool is_colliding(const SDL_Rect*) const;
	void render() const;
public:
	Cobra_Rect* m_dst_rect;
	SDL_Renderer* m_renderer;
};