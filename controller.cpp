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

void controller_modify(struct Controller* c, bool b)
{
}


void controller_get_input(struct Controller* controller)
{
	SDL_PumpEvents();

	const Uint8* key_state = SDL_GetKeyboardState(NULL);
	const Uint32 mouse_state = SDL_GetMouseState(&(controller->mouse_position.x), &(controller->mouse_position.y));

	if (key_state[SDL_SCANCODE_LEFT])
   		printf("Left Pressed.\n");
	if (key_state[SDL_SCANCODE_RIGHT])
    		printf("Right Pressed.\n");
	if (key_state[SDL_SCANCODE_UP])
   		printf("Up Pressed.\n");
	if (key_state[SDL_SCANCODE_DOWN])
    		printf("Down Pressed.\n");
	if (mouse_state & SDL_BUTTON(SDL_BUTTON_LEFT))
		printf("Mouse pressed");


}


