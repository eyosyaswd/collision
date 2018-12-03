#include <iostream>

#include "Global.hpp"
#include "PauseState.hpp"
#include "GameState.hpp"
#include "MenuState.hpp"


PauseState::PauseState(GameDataRef data) : gameData(data)
	{

	}

	void PauseState::init()
	{

        if (!pause_Theme.loadFromFile("../res/sounds/controlsTheme.wav"))
            std::cout << "Error occured while loading music " << std::endl;
        else {
            pauseTheme.setBuffer(pause_Theme);
            pauseTheme.setLoop(true);
            pauseTheme.play();
        }

        if (!switch_Buffer.loadFromFile("../res/sounds/switch.wav"))
            std::cout << "Error occured while loading music " << std::endl;
        else {
            menuSwitch.setBuffer(switch_Buffer);
        }

        if (!select_Buffer.loadFromFile("../res/sounds/select.wav"))
            std::cout << "Error occured while loading music " << std::endl;
        else {
            select.setBuffer(select_Buffer);
        }

        if (!play_Theme.loadFromFile("../res/sounds/wave1.wav"))
            std::cout << "Error occured while loading music " << std::endl;
        else {
            playTheme.setBuffer(play_Theme);
            playTheme.setLoop(true);
        }



		this->gameData->resourceManager.loadTexture("GameState Background", GAME_STATE1_BACKGROUND_FILEPATH);
    backgroundSprite.setTexture(this->gameData->resourceManager.getTexture("GameState Background"));

		this->gameData->resourceManager.loadTexture("PauseState Background", PAUSE_STATE_BACKGROUND_FILEPATH);
    backgroundSprite.setTexture(this->gameData->resourceManager.getTexture("PauseState Background"));

		this->gameData->resourceManager.loadFont("font", MAIN_FONT_FILEPATH);

    menu[0].setFont(this->gameData->resourceManager.getFont("font"));
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setCharacterSize(70);
    menu[0].setString("Resume");
    menu[0].setPosition(sf::Vector2f(WINDOW_WIDTH / 3,WINDOW_HEIGHT / (MAX_NUMBER_OF_ITEMS + 1) + 60));
    	//width/2.1
    menu[1].setFont(this->gameData->resourceManager.getFont("font"));
    menu[1].setFillColor(sf::Color::White);
    menu[1].setCharacterSize(70);
    menu[1].setString("Main Menu");
    menu[1].setPosition(sf::Vector2f(WINDOW_WIDTH / 3,WINDOW_HEIGHT / (MAX_NUMBER_OF_ITEMS + 1) + 140));

    menu[2].setFont(this->gameData->resourceManager.getFont("font"));
    menu[2].setFillColor(sf::Color::White);
    menu[2].setCharacterSize(70);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(WINDOW_WIDTH / 3, WINDOW_HEIGHT / (MAX_NUMBER_OF_ITEMS + 1) +220));

    selectedItem = 0;
	}

	void PauseState::handleEvents()
	{
		sf::Event event;
    
		while (this->gameData->window.pollEvent(event))
		{
            playTheme.pause();
			if (sf::Event::Closed == event.type)
			{
				this->gameData->window.close();
			}
			if(event.type == sf::Event::KeyReleased)
			{
        switch (event.key.code)
        {
          case sf::Keyboard::Up:
          moveUp();
          menuSwitch.play();
          break;

          case sf::Keyboard::Down:
          moveDown();
          menuSwitch.play();
          break;

          case sf::Keyboard::Return:
          switch (getPressedItem() )
          {
            case 0:
            this->gameData->stateManager.popState();
            select.play();
            pauseTheme.stop();
            playTheme.play();
            break;
            case 1:
            this->gameData->stateManager.popState();
            this->gameData->stateManager.pushState(StateRef(new MenuState(gameData)),true);
            select.play();
            pauseTheme.stop();
            break;
            case 2:
            this->gameData->window.close();
            break;
          }

          break;
      	}
      	break;
			}
		}
	}

	void PauseState::update(float dt)
	{

	}

	void PauseState::draw(float dt)
	{
		this->gameData->window.clear(sf::Color::Black);

		this->gameData->window.draw(backgroundSprite);

    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    	{
    		this->gameData->window.draw(menu[i]);
    	}

		this->gameData->window.display();
	}

  void PauseState::moveUp()
  {
	   if (selectedItem - 1 >= 0)
	    {
        menu[selectedItem].setFillColor(sf::Color::White);
		    selectedItem--;
        menu[selectedItem].setFillColor(sf::Color::Red);
      }
    }

    void PauseState::moveDown()
    {
      if (selectedItem + 1 < MAX_NUMBER_OF_ITEMS)
      {
        menu[selectedItem].setFillColor(sf::Color::White);
        selectedItem++;
        menu[selectedItem].setFillColor(sf::Color::Red);
      }
    }
