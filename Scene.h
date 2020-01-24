#ifndef SCENE_H
#define SCENE_H

#include <SDL2/SDL.h>
#include "Sprite.h"


class GameObject
{
	public:
		SDL_Rect geometry;
		Sprite* sprite;

		GameObject(int x, int y);
		~GameObject(void);
};


class Scene
{
	private:
		GameObject o1,o2;
		
	public:
		Scene();
		~Scene();
		void draw(void);
};



#endif
