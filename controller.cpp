#include <SDL2/SDL.h>
#include "controller.h"

void update_controller(struct Controller* controller)
{
	SDL_Event e;
        if (SDL_PollEvent(&e)) 
	{
           	if (e.type == SDL_QUIT) 
			controller->quit_app = true;
		if(e.type == SDL_KEYDOWN)
		{
			switch(e.key.keysym.sym)
			{
				case SDLK_LEFT :
					controller->left = true;
					break;
				case SDLK_RIGHT :
					controller->right = true;
					break;

			}
		}
		if(e.type == SDL_KEYUP)
		{
			switch(e.key.keysym.sym)
			{
				case SDLK_LEFT :
					controller->left = false;
					break;
				case SDLK_RIGHT :
					controller->right = false;
					break;

			}

		}
		if(e.type == SDL_MOUSEBUTTONDOWN)
		{
			controller->mouse_position.x = e.button.x;
			controller->mouse_position.y = e.button.y;

			printf("Mouse : (%i,%i)\n",controller->mouse_position.x, controller->mouse_position.y);
		}


	}

}


