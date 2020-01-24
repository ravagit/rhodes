#include <SDL2/SDL.h>
#include <stdio.h>

#include "Controller.h"
#include "Sprite.h"
#include "Graphic.h"



int main( int argc, char* args[] )
{
	graphics_initialize();

	struct Controller controller;
	Scene main_scene;
	
	while (!controller.quit_app) 
	{
		update_controller(&controller);
		const float time_left = graphics_update(&main_scene);
	       	if(time_left > 0)
			SDL_Delay(time_left);
		else
			printf("Framerate overflow by :%f milliseconds\n",time_left);

				
	}
	graphics_close();	
	
	return 0;
}
