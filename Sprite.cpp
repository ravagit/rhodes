#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.h"


std::string Sprite::resource_folder;
SDL_Renderer* Sprite::renderer;


Sprite::Sprite(std::string name)
{
	std::string path = resource_folder+name;
	SDL_Surface* img = IMG_Load(path.c_str());
	if(!img)
		printf("Can't find sprite %s : %s\n",path.c_str() , IMG_GetError());
	
	texture = SDL_CreateTextureFromSurface(renderer, img);
	if(!texture)
		printf("CreateTextureFromSurface failed: %s\n", SDL_GetError());
	SDL_FreeSurface(img);

	SDL_QueryTexture(texture,NULL,NULL, &width, &height);
	
}

Sprite::~Sprite(void)
{
	SDL_DestroyTexture(texture);
}

void Sprite::draw(int x, int y)
{
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;
	SDL_RenderCopy(renderer,texture,NULL,&rect);	

}







