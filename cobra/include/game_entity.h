#pragma once
#include "components/texture_component.h"
#include "components/collider2d.h"
#include <SDL2/SDL_render.h>
#include "vector"

typedef enum Visibility 
{
	NOT_VISIBLE,
	VISIBLE,
};

typedef enum Status
{
	NOT_ACTIVE,
	ACTIVE,
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
	Collider2D* get_collider(const unsigned int index) const;
public:
	Visibility m_visibility;
	Status get_status() const;
private:
	Texture_Component* m_texture_component;
	std::vector<Collider2D*> m_colliders;
	SDL_Renderer* m_renderer;
	Status m_status;
};
