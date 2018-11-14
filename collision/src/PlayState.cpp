#include "PlayState.hpp"
#include "MenuState.hpp"
#include <iostream>

#include <SFML/Graphics.hpp>

#include "gameState.hpp"


void PlayState::draw(const float dt)
{



}

void PlayState::update(const float dt)
{




}

void PlayState::handleInput()
{
    sf::Event event;

    while (this->game->window.pollEvent(event))
    {
        switch (event.type)
        {
            // Close the window
        case sf::Event::Closed:
            this->game->window.close();
            break;

            //pause game
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
                PauseGame();
            break;

        }
    }


}

PlayState::PlayState(GameApp* game)
{

}

void PlayState::PauseGame()
{


}
