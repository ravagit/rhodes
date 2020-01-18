#include <SDL2/SDL.h>
#include "graphic.h"


struct Sprite 
{
	SDL_Renderer* renderer;
	SDL_Rect geometry;
	SDL_Texture* img;

};

void sprite_draw(Sprite s)
{
	SDL_RenderCopy(s.renderer,s.img,NULL,&s.geometry);	
}

struct Create_Sprite
{
	Create_Sprite(SDL_Renderer* ren){
		r=ren;
	};
	void operator()(struct Sprite* s, const char* ref) const
	{
		s->renderer = r;
		s->geometry = {0,0,20,20};
	}

	private:
	SDL_Renderer* r;
};


void draw_square(SDL_Renderer* r, int x, int y, int c)
{
	SDL_Rect rect = {x,y,c,c};
	SDL_SetRenderDrawColor(r,255,0,0,1);
	SDL_RenderDrawRect(r,&rect);
	
}

void update_renderer(SDL_Renderer* r, struct Controller c)
{
	
	SDL_SetRenderDrawColor(r,0,0,0,1);
	SDL_RenderClear(r);
	draw_square(r, c.mouse_position.x, c.mouse_position.y, 20);
	//SDL_RenderSetScale(r,2.0,2.0);
	SDL_RenderPresent(r);

	
}










