/**
	* Filename: StoryState.hpp
	*
	* This is the sequence of screens that show the story before the GameState.
**/

#ifndef STORY_STATE_HPP
#define STORY_STATE_HPP


#include <SFML/Graphics.hpp>

#include "GameApp.hpp"
#include "State.hpp"

#define MAX_NUMBER_OF_ITEMS 3


class StoryState : public State {

	public:
		StoryState(GameDataRef data);
		void init();
		void handleEvents();
		void update(float dt);
		void draw(float dt);

	private:
		GameDataRef gameData;
    int count;


		sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Sprite backgroundSprite2;
    sf::Sprite backgroundSprite3;
		sf::Sprite backgroundSprite4;


	  sf::Font font;

    sf::SoundBuffer play_Theme;
    sf::Sound playTheme;


};


#endif
