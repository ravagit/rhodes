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
	struct Controller control;

};
struct Application app;


void initialize()
{
	SDL_Init( SDL_INIT_VIDEO);
	app.window = SDL_CreateWindow(app.name, 
					SDL_WINDOWPOS_UNDEFINED, 
					SDL_WINDOWPOS_UNDEFINED, 
					app.width, 
					app.height, 
					SDL_WINDOW_SHOWN 
					);
	init_graphics(app.window);
	
}

void close()
{
	close_graphics();
	SDL_DestroyWindow(app.window);
	SDL_Quit();
}


void update_application()
{
	if(app.control.quit_app)
		app.is_running = false;
}


unsigned int t = 0;
unsigned int prev_t = 0;
float framerate = 20;
float period = 1/framerate*1000;

void run()
{
	prev_t = SDL_GetTicks();
	update_application();
	update_controller(&(app.control));
	update_graphics(&app);

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
	while (app.is_running) 
		run();
	close();	
	return 0;
}
