#include <iostream>

#include "Global.hpp"
#include "StoryState.hpp"
#include "MenuState.hpp"
#include "GameState2.hpp"


StoryState::StoryState(GameDataRef data) : gameData(data)
	{

	}

	void StoryState::init()
	{
    count = 0;
		this->gameData->resourceManager.loadTexture("StoryState1 Background", STORY_STATE_BACKGROUND_FILEPATH1);
    backgroundSprite.setTexture(this->gameData->resourceManager.getTexture("StoryState1 Background"));

    this->gameData->resourceManager.loadTexture("StoryState2 Background", STORY_STATE_BACKGROUND_FILEPATH2);


    this->gameData->resourceManager.loadTexture("StoryState3 Background", STORY_STATE_BACKGROUND_FILEPATH3);




    if (!play_Theme.loadFromFile("../res/sounds/wave1.wav"))
        std::cout << "Error occured while loading music " << std::endl;
    else {
        playTheme.setBuffer(play_Theme);
        playTheme.play();
    }

	}

	void StoryState::handleEvents()
	{

		sf::Event event;

    while (this->gameData->window.pollEvent(event))
		{

			if (sf::Event::Closed == event.type)
			{
				this->gameData->window.close();
			}

      if (event.type == sf::Event::KeyPressed) {
          if (event.key.code == sf::Keyboard::Return) {
            count = count + 1;
            if(count > 2){
              this -> gameData->stateManager.pushState(StateRef(new GameState2(gameData)), true);
            }
            if (count == 1){
              backgroundSprite.setTexture(this->gameData->resourceManager.getTexture("StoryState2 Background"));

            }
            if (count == 2){
              backgroundSprite.setTexture(this->gameData->resourceManager.getTexture("StoryState3 Background"));
            }
            if (count == 3){
                playTheme.stop();
            }
          }
        }
		}
	}


	void StoryState::update(float dt)
	{

	}

	void StoryState::draw(float dt)
	{
		this->gameData->window.clear(sf::Color::Black);

		this->gameData->window.draw(backgroundSprite);

        gameData->window.display();
	}
