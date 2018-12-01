/**
	* Filename: WinState.hpp
	*
	* This is the screen that will be displayed when the player wins the game.
**/

#ifndef WINSTATE_HPP
#define WINSTATE_HPP


#include <SFML/Graphics.hpp>

#include "GameApp.hpp"
#include "State.hpp"

#define MAX_NUMBER_OF_ITEMS 3


class WinState : public State {

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

		sf::Texture backgroundTexture;
		sf::Sprite backgroundSprite;

	  sf::Font font;
	  sf::Text menu[MAX_NUMBER_OF_ITEMS];
<<<<<<< HEAD
	  sf::SoundBuffer victory_Theme;
	  sf::Sound victoryTheme;
	};
=======

};

>>>>>>> b632f3edbba2380383382c6b35e4ddbc7ea40726

#endif
