#pragma once
#include "components/texture_component.h"
#include "components/collider2d.h"
#include <SDL2/SDL_render.h>

typedef enum Visibility {
	NOT_VISIBLE,
	VISIBLE,
};

class Game_Entity {

public:
	Game_Entity(SDL_Renderer*);
	~Game_Entity();
	void add_texture_component(const char*, RGBA);
	void add_collider2D(Cobra_Rect*);
	void render() const;
	void set_visibility(Visibility visibility);
	Visibility is_visible() const;
	Texture_Component* get_texture_component() const;
	Collider2D* get_collider_component() const;
public:
	Visibility m_visibility;
private:
	Texture_Component* m_texture_component;
	Collider2D* m_collider_component;
	SDL_Renderer* m_renderer;
};
