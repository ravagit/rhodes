#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "graphic.h"

SDL_Renderer* R;
TTF_Font* FONT;

typedef struct
{
	SDL_Rect geometry;
	bool state = false;
	SDL_Texture* text;
} Button;

Button do_stuff_button;

void button_create(Button* b, const char* text, int x, int y)
{
	SDL_Color color = {5, 5, 5, 0};
	SDL_Surface* surface = TTF_RenderText_Solid(FONT, text, color);
	b->text = SDL_CreateTextureFromSurface(R, surface);
    	b->geometry = {x,y,surface->w,surface->h};
	SDL_FreeSurface(surface);
}

void button_display(Button b)
{
	SDL_SetRenderDrawColor(R,0,0,0,0);
	SDL_Rect rect = {b.geometry.x, b.geometry.y, b.geometry.w+5, b.geometry.h+5};
	SDL_RenderFillRect(R,&rect);
	SDL_SetRenderDrawColor(R,255,255,255,0);
	SDL_RenderFillRect(R,&b.geometry);
	SDL_RenderCopy(R, b.text, NULL, &(b.geometry));
}

struct Animation 
{
	int n_frame = 0;
	SDL_Point position = {0,0};
	int tick_per_frame = 4;
	int tick = 0;
	int phase = 0;
	SDL_Texture** sprite;

};


typedef struct Animation Animation;

Animation anim;

void animation_display(Animation a)
{
	SDL_Rect rect;
	SDL_QueryTexture(a.sprite[a.phase],NULL,NULL, &(rect.w), &(rect.h));
	rect.x = a.position.x;
	rect.y = a.position.y;
	SDL_RenderCopy(R,a.sprite[a.phase],NULL,&rect);	
}

void animation_update(Animation* a)
{
	a->tick++;
	a->tick = a->tick % (a->tick_per_frame*a->n_frame); 
	a->phase = a->tick / a->tick_per_frame;
	//printf("tick : %f, phase : %f\n", (float) a->tick, (float) a->phase);
}

void animation_init(Animation* a, int num_sprites)
{
	a->n_frame = num_sprites;
	a->sprite = (SDL_Texture**) malloc(sizeof(SDL_Texture*)*num_sprites);
}

void animation_destroy(Animation* a)
{
	for(int i=0;i<a->n_frame;i++)
		SDL_DestroyTexture(a->sprite[i]);

}

void animation_add_sprite(Animation* a, const char* ref)
{

	SDL_Surface* tmp;
	tmp=IMG_Load(ref);
	if(!tmp)
		printf("Error while loading sprite: %s\n", IMG_GetError());
	
	a->sprite[a->n_frame] = SDL_CreateTextureFromSurface(R, tmp);
	a->n_frame++;
	SDL_FreeSurface(tmp);
		
}


void draw_square(int x, int y, int c)
{
	SDL_Rect rect = {x,y,c,c};
	SDL_SetRenderDrawColor(R,255,0,0,1);
	SDL_RenderDrawRect(R,&rect);
	
}

void draw_text(const char* text, int x, int y)
{
	SDL_Color color = {5, 5, 5, 0};
	SDL_Surface* surface = TTF_RenderText_Solid(FONT, text, color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(R, surface);
	if(texture==NULL || surface==NULL)
		printf("can't create text\n");

    	SDL_Rect geometry = {x,y,surface->w,surface->h};
	SDL_FreeSurface(surface);

	SDL_RenderCopy(R, texture, NULL, &geometry);
	SDL_DestroyTexture(texture);
}

void update_graphics(struct Application* app)
{
	
	SDL_SetRenderDrawColor(R,200,200,200,0);
	SDL_RenderClear(R);

	animation_display(anim);
	animation_update(&anim);
	button_display(do_stuff_button);
	//SDL_RenderSetScale(r,2.0,2.0);
	SDL_RenderPresent(R);

	
}

void init_graphics(SDL_Window* window)
{	
	//char* base_path = SDL_GetBasePath();
	//printf("base path is %s\n",base_path);
	
	R = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
	const char* font_path = "/Library/Fonts/Arial.ttf";
	const int MAX_SPRITES_PER_ANIMATION = 32;

	TTF_Init();
    	FONT = TTF_OpenFont(font_path, 12);
	if (FONT == NULL)
        	printf("error: font not found\n");
    	
	button_create(&do_stuff_button, "do it", 200, 30);
	//animation_init(&anim,11);
	anim.sprite = (SDL_Texture**) malloc(sizeof(SDL_Texture*)*MAX_SPRITES_PER_ANIMATION);
	animation_add_sprite(&anim,"SPRIT_run_1.png");
	animation_add_sprite(&anim,"SPRIT_run_2.png");
	animation_add_sprite(&anim,"SPRIT_run_3.png");
	animation_add_sprite(&anim,"SPRIT_run_4.png");
	animation_add_sprite(&anim,"SPRIT_run_5.png");
	animation_add_sprite(&anim,"SPRIT_run_6.png");
	animation_add_sprite(&anim,"SPRIT_run_7.png");
	animation_add_sprite(&anim,"SPRIT_run_8.png");
	animation_add_sprite(&anim,"SPRIT_run_9.png");
	animation_add_sprite(&anim,"SPRIT_run_10.png");
	animation_add_sprite(&anim,"SPRIT_run_11.png");


}

void close_graphics()
{
	animation_destroy(&anim);
	TTF_Quit();
	SDL_DestroyRenderer(R);
}



