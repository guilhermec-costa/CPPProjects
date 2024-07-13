#pragma once
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

#define DEFAULT_TEXTURE_DIMENSIONS { 32, 32 }
#define DEFAULT_TEXTURE_POSITIONS { 32, 32 }

typedef struct RGBA {
	Uint8 R;
	Uint8 G;
	Uint8 B;
	Uint8 A;
	Uint32 format() const;
} RGBA;

struct Dimensions {
	unsigned int w;
	unsigned int h;
};

struct Position {
	unsigned int x;
	unsigned int y;
};

class Texture_Component {
public:
	Texture_Component(SDL_Renderer*, const char*, RGBA);
	void render();
	SDL_Renderer* get_renderer() const;
	//SDL_Texture* get_texture() const;
	//Uint32 get_width() const;
	//Uint32 get_height() const;
	//void set_width();
	//void set_height();
private:
	SDL_Rect* m_src_fraction_rect;
	SDL_Rect* m_render_target_rect;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	RGBA bg_mask;
	Dimensions m_dimensions;
	Position m_position;
};

