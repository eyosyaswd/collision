#include <iostream>

#include "Global.hpp"
#include "MenuState.hpp"
#include "GameState.hpp"
#include "StoryState.hpp"
#include "ControlsState.hpp"



MenuState::MenuState(GameDataRef data) : gameData(data)
	{

	}

	void MenuState::init()
	{
		this->gameData->resourceManager.loadTexture("MenuState Background", MENU_STATE_BACKGROUND_FILEPATH);
    backgroundSprite.setTexture(this->gameData->resourceManager.getTexture("MenuState Background"));

		this->gameData->resourceManager.loadFont("font", MAIN_FONT_FILEPATH);

        if (!menu_Theme.loadFromFile("../res/sounds/collisionTheme.wav"))
            std::cout << "Error occured while loading music " << std::endl;
        else {
            menuTheme.setBuffer(menu_Theme);
            menuTheme.setLoop(true);
            menuTheme.play();
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


    menu[0].setFont(this->gameData->resourceManager.getFont("font"));
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setCharacterSize(70);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f((WINDOW_WIDTH / 2),WINDOW_HEIGHT / (MAX_NUMBER_OF_ITEMS + 1) * 1.2));
    	//width/2.1
    menu[1].setFont(this->gameData->resourceManager.getFont("font"));
    menu[1].setFillColor(sf::Color::White);
    menu[1].setCharacterSize(70);
    menu[1].setString("Controls");
    menu[1].setPosition(sf::Vector2f((WINDOW_WIDTH / 2),WINDOW_HEIGHT / (MAX_NUMBER_OF_ITEMS + 1) * 1.2 * 1.5));

    menu[2].setFont(this->gameData->resourceManager.getFont("font"));
    menu[2].setFillColor(sf::Color::White);
    menu[2].setCharacterSize(70);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f((WINDOW_WIDTH / 2), WINDOW_HEIGHT / (MAX_NUMBER_OF_ITEMS + 1) * 1.2 * 2));

    selectedItem = 0;
	}

	void MenuState::handleEvents()
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
          menuSwitch.play();
          break;

          case sf::Keyboard::Down:
          moveDown();
          menuSwitch.play();
          break;

          case sf::Keyboard::Return:
          switch (getPressedItem() )
          {
            case 0: {
                select.play();
                this->gameData->stateManager.pushState(StateRef(new StoryState(gameData)), true);
                menuTheme.stop();
            }
            break;
            case 1:
                select.play();
                this->gameData->stateManager.pushState(StateRef(new ControlsState(gameData)), true);
                menuTheme.stop();
            break;
            case 2: {
                select.play();
                this->gameData->window.close();
                menuTheme.stop();
            }
            break;
          }

          break;
      	}
      	break;
			}
		}
	}

	void MenuState::update(float dt)
	{

	}

	void MenuState::draw(float dt)
	{
		this->gameData->window.clear(sf::Color::Black);

		this->gameData->window.draw(backgroundSprite);

		//this->gameData->window.draw(this->_background);

    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    	{
    		this->gameData->window.draw(menu[i]);
    	}

		this->gameData->window.display();
	}

  void MenuState::moveUp()
  {
	   if (selectedItem - 1 >= 0)
	    {
        menu[selectedItem].setFillColor(sf::Color::White);
		    selectedItem--;
        menu[selectedItem].setFillColor(sf::Color::Red);
      }
    }

    void MenuState::moveDown()
    {
      if (selectedItem + 1 < MAX_NUMBER_OF_ITEMS)
      {
        menu[selectedItem].setFillColor(sf::Color::White);
        selectedItem++;
        menu[selectedItem].setFillColor(sf::Color::Red);
      }
    }
