#include "SFML/Graphics.hpp"
#pragma once

#define MAX_NUMBER_OF_ITEMS 3


class Menu
{
public:
	Menu(float width, float height);

	void draw(sf::RenderWindow &window);
	void moveUp();
	void moveDown();
	int getPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};
