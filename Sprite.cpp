#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>

#include "Sprite.h"

std::map<std::string, Sprite*> mapOfSprites;

std::string Sprite::resource_folder = "./Assets/";
SDL_Renderer* Sprite::renderer;

void load_all_sprites()
{
	mapOfSprites["idle"] = new Sprite("idle.png");
}

Sprite* set_sprite(std::string key)
{
	return mapOfSprites[key];
}

void unload_all_sprites()
{
	std::map<std::string, Sprite*>::iterator it = mapOfSprites.begin();
	while(it != mapOfSprites.end())
	{
		printf("Free sprite : %s\n",it->first.c_str());
		delete it->second;
		it++;
	}
}

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
	printf("Created sprite : %s\n", name.c_str());

	
}

Sprite::~Sprite(void)
{
	printf("Sprite is destroyed\n");
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







