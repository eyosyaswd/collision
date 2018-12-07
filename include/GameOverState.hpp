/**
	* Filename: GameOverState.hpp
	*
	* This is the screen that shows up when you lose the game.
**/

#ifndef LOSESTATE_HPP
#define LOSESTATE_HPP


#include <SFML/Graphics.hpp>

#include "GameApp.hpp"
#include "State.hpp"

#define MAX_NUMBER_OF_ITEMS 3


class GameOverState : public State {

	public:
		GameOverState(GameDataRef data);
		GameOverState(GameDataRef data, int score);
		void init();
		void handleEvents();
		void update(float dt);
		void draw(float dt);

		void moveUp();
		void moveDown();
		int getPressedItem() { return selectedItem; }

	private:
		GameDataRef gameData;
        std::string scorestring;
		int finalscoreint;
		sf::Text finalscore;
		sf::Text finaltext;


    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    int selectedItem;
	  sf::Font font;
	  sf::Text menu[MAX_NUMBER_OF_ITEMS];
	  sf::SoundBuffer defeat_Theme;
		sf::SoundBuffer switch_Buffer;
	  sf::SoundBuffer select_Buffer;
	  sf::Sound defeatTheme;
		sf::Sound select;
		sf::Sound menuSwitch;

};


#endif
