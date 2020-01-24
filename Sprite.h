#ifndef SPRITE_H
#define SPRITE_H
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Sprite 
{
	private :
	
		SDL_Rect rect;
		SDL_Texture* texture;
		static std::string resource_folder;
		
		
		
	public :
		static SDL_Renderer* renderer;

		int width;
		int height;

		Sprite(std::string);
		~Sprite(void);
		void draw(int ,int );
};


void load_all_sprites();
void unload_all_sprites();

Sprite* set_sprite(std::string);


#endif
