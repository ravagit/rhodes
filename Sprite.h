#ifndef SPRITE_H
#define SPRITE_H
#include <string>

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

#endif
