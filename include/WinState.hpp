#ifndef WINSTATE_HPP
#define WINSTATE_HPP


#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "GameApp.hpp"

#define MAX_NUMBER_OF_ITEMS 3


class WinState : public State
	{
	public:
		WinState(GameDataRef data);

		void init();

		void handleEvents();
		void update(float dt);
		void draw(float dt);
    void moveUp();
	  void moveDown();
    int getPressedItem() { return selectedItem; }

	private:
		GameDataRef gameData;

    int selectedItem;
	  sf::Font font;
	  sf::Text menu[MAX_NUMBER_OF_ITEMS];
	  sf::SoundBuffer victory_Theme;
	  sf::Sound victoryTheme;
	};

#endif
