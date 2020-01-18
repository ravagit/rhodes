#include <SDL2/SDL.h>
#include <stdio.h>
#include "controller.h"
#include "graphic.h"

struct Application {
	bool is_running = true;
	const char* name = "Graffiti";
	SDL_Window* window;
	SDL_Renderer* renderer;
	int width = 600;
	int height = 400;

};
struct Application application;
struct Controller controller;


void initialize()
{
	SDL_Init( SDL_INIT_VIDEO);
	application.window = SDL_CreateWindow(application.name, 
					SDL_WINDOWPOS_UNDEFINED, 
					SDL_WINDOWPOS_UNDEFINED, 
					application.width, 
					application.height, 
					SDL_WINDOW_SHOWN 
					);
	application.renderer = SDL_CreateRenderer(application.window,-1,SDL_RENDERER_ACCELERATED);
	
}

void close()
{
	SDL_DestroyRenderer(application.renderer);
	SDL_DestroyWindow(application.window);
	SDL_Quit();
}



void run()
{
	//controller_get_input();
	update_controller(&controller);
	update_renderer(application.renderer, controller);
}
	
	

int main( int argc, char* args[] )
{
	initialize();
	while (!controller.quit_app) 
		run();
	close();	
	return 0;
}
