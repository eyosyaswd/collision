#include <iostream>

#include "Global.hpp"
#include "LoseState.hpp"
#include "MenuState.hpp"
#include "GameState2.hpp"


LoseState::LoseState(GameDataRef data) : gameData(data)
	{

	}

LoseState::LoseState(GameDataRef data, int score) : gameData(data)
{
        this->finalscoreint = score;

}

	void LoseState::init()
	{
		this->gameData->resourceManager.loadTexture("LoseState Background", LOSE_STATE_BACKGROUND_FILEPATH);
    backgroundSprite.setTexture(this->gameData->resourceManager.getTexture("LoseState Background"));

        finaltext.setFont(this->gameData->resourceManager.getFont("font"));
        finaltext.setFillColor(sf::Color::Red);
        finaltext.setCharacterSize(70);
        finaltext.setString("Game Over! Final Score:");
        finaltext.setPosition((WINDOW_WIDTH / 8) - 40, 65);

        finalscore.setFont(this->gameData->resourceManager.getFont("font"));
        finalscore.setFillColor(sf::Color::Red);
        finalscore.setCharacterSize(70);
        scorestring = std::to_string(finalscoreint);
        finalscore.setString(scorestring);
        finalscore.setPosition(WINDOW_WIDTH / 2, 150);


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

		this->gameData->resourceManager.loadFont("font", MAIN_FONT_FILEPATH);
        if (!defeat_Theme.loadFromFile("../res/sounds/defeatTheme.wav"))
            std::cout << "Error occured while loading music " << std::endl;
        else {
            defeatTheme.setBuffer(defeat_Theme);
            defeatTheme.play();
        }
    menu[0].setFont(this->gameData->resourceManager.getFont("font"));
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setCharacterSize(70);
    menu[0].setString("Try Again");
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
    menu[2].setPosition(sf::Vector2f(WINDOW_WIDTH / 3, WINDOW_HEIGHT / (MAX_NUMBER_OF_ITEMS + 1) + 220));

    selectedItem = 0;
	}

	void LoseState::handleEvents()
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
            case 0:
						select.play();
						defeatTheme.stop();
            this->gameData->stateManager.pushState(StateRef(new GameState2(gameData)), true);
            break;
            case 1:
						select.play();
						defeatTheme.stop();
            this -> gameData->stateManager.pushState(StateRef(new MenuState(gameData)), true);
            break;
            case 2:
						select.play();
            this->gameData->window.close();
            break;
          }

          break;
      	}
      	break;
			}
		}
	}

	void LoseState::update(float dt)
	{

	}

	void LoseState::draw(float dt)
	{
		this->gameData->window.clear(sf::Color::Black);

		this->gameData->window.draw(backgroundSprite);
        this->gameData->window.draw(finalscore);

    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    	{
    		this->gameData->window.draw(menu[i]);
    	}

        this->gameData->window.draw(finaltext);
        this->gameData->window.draw(finalscore);

		this->gameData->window.display();
	}

  void LoseState::moveUp()
  {
	   if (selectedItem - 1 >= 0)
	    {
        menu[selectedItem].setFillColor(sf::Color::White);
		    selectedItem--;
        menu[selectedItem].setFillColor(sf::Color::Red);
      }
    }

    void LoseState::moveDown()
    {
      if (selectedItem + 1 < MAX_NUMBER_OF_ITEMS)
      {
        menu[selectedItem].setFillColor(sf::Color::White);
        selectedItem++;
        menu[selectedItem].setFillColor(sf::Color::Red);
      }
    }
