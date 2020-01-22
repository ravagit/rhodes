#include <SDL2/SDL.h>
#include <stdio.h>
#include "controller.h"
#include "Sprite.h"

class Application 
{
	public:
		bool is_running = true;
		const char* name = "Graffiti";
		SDL_Window* window;
		SDL_Renderer* renderer;
		int width = 600;
		int height = 400;
		struct Controller control;
	
		Application(void);
		~Application(void);

};

Application::Application()
{
	SDL_Init( SDL_INIT_VIDEO);
	window = SDL_CreateWindow( name, 
					SDL_WINDOWPOS_UNDEFINED, 
					SDL_WINDOWPOS_UNDEFINED, 
					width, 
					height, 
					SDL_WINDOW_SHOWN 
					);

	renderer =  SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);		
}

Application::~Application()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}



unsigned int t = 0;
unsigned int prev_t = 0;
float framerate = 20;
float period = 1/framerate*1000;


void run(Application* app,  Sprite* spr)
{
	prev_t = SDL_GetTicks();
	update_controller(&(app->control));

	t = SDL_GetTicks();
	unsigned int dt = t-prev_t;

	SDL_SetRenderDrawColor(app->renderer,200,200,200,0);
	SDL_RenderClear(app->renderer);


	spr->draw(100,100);
	SDL_RenderPresent(app->renderer);

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
	Application app;
	Sprite::resource_folder = "./Assets/";
	Sprite::renderer = app.renderer;
	

	
	Sprite sprite1("idle.png");
	while (!app.control.quit_app) 
		run(&app, &sprite1);
	
	return 0;
}
