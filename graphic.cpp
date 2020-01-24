#include <SDL2/SDL.h>
#include "Graphic.h"

#include "Sprite.h"
#include "Scene.h"


struct Graphics
{
	SDL_Window* window;	
	SDL_Renderer* renderer;
	SDL_Color clear_color = {200,200,200,0};
	const int framerate = 30;
} g;


void graphics_initialize()
{
	const char* name = "Window";
	const int width = 600;
	const int height = 400;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow(name,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer =  SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
	
	g.window = window;
	g.renderer =renderer;

	//init other subsytems (e.g. Sprites.cpp...)
	Sprite::renderer = renderer;
	load_all_sprites();
	
}


void graphics_close()
{
	unload_all_sprites();	
	SDL_DestroyRenderer(g.renderer);
	SDL_DestroyWindow(g.window);
	SDL_Quit();
}


const float graphics_update(Scene* s)
{
	const int t0 = SDL_GetTicks();
	SDL_SetRenderDrawColor(g.renderer,g.clear_color.r,g.clear_color.g,g.clear_color.b,g.clear_color.a);
	SDL_RenderClear(g.renderer);
	
	s->draw();

	SDL_RenderPresent(g.renderer);
	const float time_left_in_frame = (1/g.framerate*1000 - (SDL_GetTicks()-t0));

	return time_left_in_frame;

}




