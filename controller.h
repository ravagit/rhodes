#ifndef CONTROLLER_H
#define CONTROLLER_H

struct Controller {
	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;

	SDL_Point mouse_position = {0,0};

	bool quit_app = false;
};

void update_controller(struct Controller*);
void controller_modify(struct Controller*, bool );
void controller_get_input(struct Controller*);


#endif

