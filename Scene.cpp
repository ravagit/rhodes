#include "Scene.h"
#include "Sprite.h"

//-------------GameObject-------------//

GameObject::GameObject(int x, int y)
{

	geometry = {x,y,32,32};

}

GameObject::~GameObject(void)
{
	printf("Object is destroyed\n");
}

//-------------Scene-------------//

Scene::Scene() : o1(100,100), o2(50,50)
{
	o1.sprite = set_sprite("idle");
	o2.sprite = set_sprite("idle");

	
}
Scene::~Scene()
{
	
}

void Scene::draw(void)
{
	o1.sprite->draw(o1.geometry.x,o1.geometry.y);
	o2.sprite->draw(o2.geometry.x,o2.geometry.y);

}
