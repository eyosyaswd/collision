/**
	* Filename: PauseState.hpp
	*
	* This is the screen that shows up when you pause the game.
**/

#ifndef PAUSESTATE_HPP
#define PAUSESTATE_HPP


#include <SFML/Graphics.hpp>

#include "GameApp.hpp"
#include "State.hpp"

#define MAX_NUMBER_OF_ITEMS 3


class PauseState : public State {

	public:
		PauseState(GameDataRef data);
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

	sf::SoundBuffer pause_Theme;
	sf::SoundBuffer play_Theme;
    sf::SoundBuffer switch_Buffer;
    sf::SoundBuffer select_Buffer;
    sf::Sound menuSwitch;
    sf::Sound select;
    sf::Sound pauseTheme;
	sf::Sound playTheme;

};


#endif
