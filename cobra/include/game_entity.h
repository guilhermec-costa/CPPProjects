#pragma once
#include "components/texture_component.h"
#include <SDL2/SDL_render.h>

class Game_Entity {

public:
	Game_Entity(SDL_Renderer*);
	~Game_Entity();
	void add_texture_component(const char*, RGBA);
	Texture_Component* get_texture_component() const;
private:
	Texture_Component* m_texture_component;
	SDL_Renderer* m_renderer;
};
