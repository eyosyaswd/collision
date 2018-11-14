
#include "SFML/Graphics.hpp"

#include <iostream>

#include "MenuState.hpp"
#include "PlayState.hpp"
#include "gameState.hpp"


MenuState::MenuState(GameApp* game)
{
    this->game = game;

    if (!font.loadFromFile("../res/fonts/Ailerons.ttf"))
  	{
  		// handle error
  	}

  	menu[0].setFont(font);
  	menu[0].setColor(sf::Color::Red);
  	menu[0].setString("Play");
  	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

  	menu[1].setFont(font);
  	menu[1].setColor(sf::Color::White);
  	menu[1].setString("Options");
  	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

  	menu[2].setFont(font);
  	menu[2].setColor(sf::Color::White);
  	menu[2].setString("Exit");
  	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

  	selectedItemIndex = 0;

}
void MenuState::handleInput()
{
    sf::Event event;

    while (game->window.pollEvent(event))
    {
      switch (event.type)
    {
    case sf::Event::KeyReleased:
      switch (event.key.code)
      {
      case sf::Keyboard::Up:
        moveUp();
        break;

      case sf::Keyboard::Down:
        moveDown();
        break;

      case sf::Keyboard::Return:
        switch (getPressedItem())
        {
        case 0:
          loadgame();
          break;
        case 1:
          std::cout << "Option button has been pressed" << std::endl;
          break;
        case 2:
          this->game->window.close();
          break;
        }

        break;
      }
      break;
    case sf::Event::Closed:
      this->game->window.close();
      break;


        }
    }

}

void MenuState::update(const float dt)
{

}

void MenuState::draw(const float dt)
{
  for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		this->game->window.draw(menu[i]);
	}
}

void MenuState::loadgame()
{
  game->pushState(new PlayState(game));
}

void MenuState::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void MenuState::moveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}
