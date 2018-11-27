#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP


#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "GameApp.hpp"

#define MAX_NUMBER_OF_ITEMS 3


class MenuState : public State
	{
	public:
		MenuState(GameDataRef data);

		void init();

		void handleEvents();
		void update(float dt);
		void draw(float dt);
    void MoveUp();
	  void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }

	private:
		GameDataRef gameData;

    int selectedItemIndex;
	  sf::Font font;
	  sf::Text menu[MAX_NUMBER_OF_ITEMS];

	};

#endif
