#ifndef GRAPHIC_H
#define GRAPHIC_H


class Scene
{
	private:
		
	public:
		Scene(){};
		~Scene(){};
		void draw(void)
		{
		};
};



void graphics_initialize();
void graphics_close();
const float graphics_update(Scene*);





#endif
