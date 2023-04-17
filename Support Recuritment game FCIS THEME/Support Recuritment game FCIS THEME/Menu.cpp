#include "Menu.h"
using namespace sf;
Menu::Menu(float width, float hieght)
{
	if (!f.loadFromFile("OpenSans-Bold.ttf")) {}

	for (int i = 0; i < 3; i++)
	{
		t[i].setFont(f);
		t[i].setCharacterSize(50);
		if (i == 0)
		{
			t[i].setFillColor(Color::Magenta);
			t[i].setString("PLAY");
			t[i].setPosition(width / 2 - 150, hieght / 4 - 100);

		}
		if (i == 1)
		{
			t[i].setFillColor(Color::Black);
			t[i].setString("INSTRUCTIONS");
			t[i].setPosition(width / 2 - 150, ((hieght / 4) * 2) - 100);

		}
		if (i == 2)
		{
			t[i].setFillColor(Color::Black);
			t[i].setString("EXIT");
			t[i].setPosition(width / 2 - 150, ((hieght / 4) * 3) - 100);

		}

	}
	selected = 0;

}


void Menu::draw(RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(t[i]);
	}

}

void Menu::moveDown()
{
	if (selected + 1 <= 3)
	{
		t[selected].setFillColor(Color::Black);
		selected++;
		if (selected == 3)
			selected = 0;
		t[selected].setFillColor(Color::Magenta);
	}
}


void Menu::moveUp()
{
	if (selected - 1 >= -1)
	{
		t[selected].setFillColor(Color::Black);
		selected--;
		if (selected == -1)
			selected = 2;
		t[selected].setFillColor(Color::Magenta);
	}
}
