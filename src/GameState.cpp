#include <sstream>
#include "GameState.hpp"
#include "MenuState.hpp"
#include "Global.hpp"
#include "PauseState.hpp"
#include "WinState.hpp"
#include "LoseState.hpp"

#include <iostream>



GameState::GameState(GameDataRef data) : gameData(data)
	{

	}

	void GameState::init()
	{
    this->gameData->resourceManager.loadTexture("GameState Background", GAME_STATE_BACKGROUND_FILEPATH);
    backgroundSprite.setTexture(this->gameData->resourceManager.getTexture("GameState Background"));
	}

	void GameState::handleEvents()
	{
		sf::Event event;

		while (this->gameData->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->gameData->window.close();
			}

      if (event.type == sf::Event::KeyPressed)
      {
        if (event.key.code == sf::Keyboard::Space)
        {

				this->gameData->stateManager.pushState(StateRef(new PauseState(gameData)), false);
        }
	     }
     }
   }

	void GameState::update(float dt)
	{

	}

	void GameState::draw(float dt)
	{
		this->gameData->window.clear(sf::Color::Red);


    this->gameData->window.draw(backgroundSprite);

		this->gameData->window.display();
	}
