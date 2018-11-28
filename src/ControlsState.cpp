//#include <sstream>
#include "MenuState.hpp"
#include "ControlsState.hpp"
#include "Global.hpp"
#include <iostream>

ControlsState::ControlsState(GameDataRef data) : gameData(data)
	{

	}

	void ControlsState::init()
	{
		this->gameData->resourceManager.loadFont("font", MAIN_FONT_FILEPATH);

    menu[0].setFont(this->gameData->resourceManager.getFont("font"));
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setCharacterSize(70);
    menu[0].setString("Menu");
    menu[0].setPosition(sf::Vector2f(WINDOW_WIDTH / 9.1,WINDOW_HEIGHT / (MAX_NUMBER_OF_ITEMS + 1) * 1));
    	//width/2.1
    menu[1].setFont(this->gameData->resourceManager.getFont("font"));
    menu[1].setFillColor(sf::Color::White);
    menu[1].setCharacterSize(70);
    menu[1].setString("    ");
    menu[1].setPosition(sf::Vector2f(WINDOW_WIDTH / 9.1,WINDOW_HEIGHT / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu[2].setFont(this->gameData->resourceManager.getFont("font"));
    menu[2].setFillColor(sf::Color::White);
    menu[2].setCharacterSize(70);
    menu[2].setString("   ");
    menu[2].setPosition(sf::Vector2f(WINDOW_WIDTH / 9.1, WINDOW_HEIGHT / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    selectedItem = 0;
	}

	void ControlsState::handleEvents()
	{
		sf::Event event;

		while (this->gameData->window.pollEvent(event))
		{

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
          break;

          case sf::Keyboard::Down:
          moveDown();
          break;

          case sf::Keyboard::Return:
          switch (getPressedItem() )
          {
            case 0:
            this->gameData->stateManager.pushState(StateRef(new MenuState(gameData)), true);
            break;
            case 1:
            //this->gameData->stateManager.pushState(StateRef(new GameState(gameData)), true);
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

	void ControlsState::update(float dt)
	{

	}

	void ControlsState::draw(float dt)
	{
		this->gameData->window.clear(sf::Color::Black);

		//this->gameData->window.draw(this->_background);

    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    	{
    		this->gameData->window.draw(menu[i]);
    	}

		this->gameData->window.display();
	}

  void ControlsState::moveUp()
  {
	   if (selectedItem - 1 >= 0)
	    {
        menu[selectedItem].setFillColor(sf::Color::White);
		    selectedItem--;
        menu[selectedItem].setFillColor(sf::Color::Red);
      }
    }

    void ControlsState::moveDown()
    {
      if (selectedItem + 1 < MAX_NUMBER_OF_ITEMS)
      {
        menu[selectedItem].setFillColor(sf::Color::White);
        selectedItem++;
        menu[selectedItem].setFillColor(sf::Color::Red);
      }
    }