/**
	* Filename: MenuState.hpp
	*
	* This is the main menu screen that you see after the splash screen.
**/

#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "GameApp.hpp"
#include "State.hpp"

#define MAX_NUMBER_OF_ITEMS 3


class MenuState : public State {

	public:
		MenuState(GameDataRef data);
		void init();
		void handleEvents();
		void update(float dt);
		void draw(float dt);

    void moveUp();
	  void moveDown();
    int getPressedItem() { return selectedItem; }

	private:
		GameDataRef gameData;

<<<<<<< HEAD
      int selectedItem;
=======
    int selectedItem;

		sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
>>>>>>> b632f3edbba2380383382c6b35e4ddbc7ea40726
	  sf::Font font;
	  sf::Text menu[MAX_NUMBER_OF_ITEMS];
	  sf::SoundBuffer menu_Theme;
	  sf::Sound menuTheme;

};


#endif
