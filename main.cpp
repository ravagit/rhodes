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
	init_graphics(application.window);
	
}

void close()
{
	close_graphics();
	SDL_DestroyWindow(application.window);
	SDL_Quit();
}


unsigned int t = 0;
unsigned int prev_t = 0;
float framerate = 20;
float period = 1/framerate*1000;

void run()
{
	prev_t = SDL_GetTicks();
	update_controller(&controller);
	update_graphics();

	t = SDL_GetTicks();
	unsigned int dt = t-prev_t;

	if(dt<period)
	{	
		//printf("process time :%d\n",dt);

		SDL_Delay(period-dt);
	}
	else
	{
		printf("Framerate limit\n");
		printf("--process time :%d\n",dt);

	}

	t = SDL_GetTicks();
	dt = t-prev_t;
	//printf("total loop time :%d\n",dt);
	
}	

int main( int argc, char* args[] )
{
	initialize();
	while (!controller.quit_app) 
		run();
	close();	
	return 0;
}
