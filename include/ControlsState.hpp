/**
	* Filename: ControlsState.hpp
	*
	* This is the settings screen.
**/

#ifndef CONTROLSSTATE_HPP
#define CONTROLSSTATE_HPP


#include <iostream>
#include <SFML/Graphics.hpp>

#include "Global.hpp"
#include "GameApp.hpp"
#include "State.hpp"
#include "MenuState.hpp"

#define MAX_NUMBER_OF_ITEMS 3


class ControlsState : public State {

	public:
		ControlsState(GameDataRef data);
		void init();
		void handleEvents();
		void update(float dt);
		void draw(float dt);

    void moveUp();
	  void moveDown();
    int getPressedItem() { return selectedItem; }

	private:
		GameDataRef gameData;

		sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    int selectedItem;
	  sf::Font font;
	  sf::Text menu[MAX_NUMBER_OF_ITEMS];
	  sf::SoundBuffer controls_Theme;
	  sf::SoundBuffer select_Buffer;
	  sf::Sound controlsTheme;
	  sf::Sound select;

};


#endif
