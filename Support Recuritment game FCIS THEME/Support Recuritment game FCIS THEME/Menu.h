#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
class Menu
{
public:
	Menu(float width, float hieght);

	void draw(RenderWindow& window);
	void moveUp();
	void moveDown();


	int MenuPressed()
	{
		return selected;
	}

private:
	int selected;
	Font f;
	Text t[3];
};