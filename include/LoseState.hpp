#ifndef LOSESTATE_HPP
#define LOSESTATE_HPP


#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "GameApp.hpp"

#define MAX_NUMBER_OF_ITEMS 3


class LoseState : public State
	{
	public:
		LoseState(GameDataRef data);

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
	  sf::SoundBuffer defeat_Theme;
	  sf::Sound defeatTheme;

	};

#endif
