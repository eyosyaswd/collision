
//#include <sstream>


#include "MenuState.hpp"
#include "Global.hpp"
#include <iostream>

MenuState::MenuState(GameDataRef data) : gameData(data)
	{

	}

	void MenuState::init()
	{
		//this->gameData->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);

		//this->_background.setTexture(this->gameData->assets.GetTexture("Background"));

    if (!font.loadFromFile("../res/fonts/Ailerons.ttf"))
  	{
  		// handle error
  	}

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setCharacterSize(70);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(WINDOW_WIDTH / 9.1,WINDOW_HEIGHT / (MAX_NUMBER_OF_ITEMS + 1) * 1));
    	//width/2.1
    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setCharacterSize(70);
    menu[1].setString("Options");
    menu[1].setPosition(sf::Vector2f(WINDOW_WIDTH / 9.1,WINDOW_HEIGHT / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setCharacterSize(70);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(WINDOW_WIDTH / 9.1, WINDOW_HEIGHT / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    selectedItemIndex = 0;
	}

	void MenuState::handleEvents()
	{
		sf::Event event;

		while (this->gameData->window.pollEvent(event))
		{
      switch (event.type)
      {
        case sf::Event::KeyReleased:
        switch (event.key.code)
        {
          case sf::Keyboard::Up:
          MoveUp();
          break;

          case sf::Keyboard::Down:
          MoveDown();
          break;

          case sf::Keyboard::Return:
          switch (GetPressedItem() )
          {
            case 0:
            //loadgame();
            break;
            case 1:
            std::cout << "Option button has been pressed" << std::endl;
            break;
            case 2:
            this->gameData->window.close();
            break;
          }

          break;
      }
      break;
      case sf::Event::Closed:
      this->gameData->window.close();
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

		//this->gameData->window.draw(this->_background);

    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    	{
    		this->gameData->window.draw(menu[i]);
    	}

		this->gameData->window.display();
	}

  void MenuState::MoveUp()
  {
	   if (selectedItemIndex - 1 >= 0)
	    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
		    selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
      }
    }

    void MenuState::MoveDown()
    {
      if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
      {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
      }
    }
