#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP


#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "GameApp.hpp"


class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void init();

		void handleEvents();
		void update(float dt);
		void draw(float dt);


	private:
    GameDataRef gameData;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

	};

#endif
