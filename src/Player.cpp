#include "Player.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Global.hpp"

// creates the player class, a RectangleShape with size, position and color
//Player::Player(float startX, float startY)
//{
//	position.x = startX;
//	position.y = startY;

//	spaceship.setSize(sf::Vector2f(30,50));
//	spaceship.setPosition(position);
//	spaceship.setFillColor(sf::Color::Red);
//}

Player::Player(GameDataRef data) : gameData(data)
{
  //position.x = spaceship.getPosition().x;
  //position.y = spaceship.getPosition().y;

	//spaceship.setSize(sf::Vector2f(30,50));
	//spaceship.setPosition(position);
	//spaceship.setFillColor(sf::Color::Red);

  this->gameData->resourceManager.loadTexture("ship", SPRITE_SHEET_FILEPATH);
  ship.setTexture(this->gameData->resourceManager.getTexture("ship"));
  ship.setTextureRect(sf::IntRect(0,200,50,50));

  position.x = ship.getPosition().x;
  position.y = ship.getPosition().y;

  ship.setPosition(position);

}

void Player::draw(){
        gameData->window.draw(spaceship);
        gameData->window.draw(ship);
}

void Player::animate(float secs){

}

// gets bounding box bounds
//sf::FloatRect Player::getPosition()
//{ return spaceship.getGlobalBounds(); }

//returns ranctablge shape
//sf::RectangleShape Player::getShape()
//{ return ship; }

sf::Sprite Player::getShape()
{ return ship; }

//keyboard input up arrow to move paddle
void Player::moveUp()
{
    position.y -= velocity;
    ship.setTextureRect(sf::IntRect(0,200,50,50));

}

//keyboard input down arrow to move paddle
void Player::moveDown()
{
    position.y += velocity;
    ship.setTextureRect(sf::IntRect(0,250,50,50));

}

void Player::moveLeft()
{ position.x -= velocity;
  ship.setTextureRect(sf::IntRect(50,250,50,50));
}


void Player::moveRight()
{ position.x += velocity;
  ship.setTextureRect(sf::IntRect(50,200,50,50));
}

void Player::set(){
    //position.x = spaceship.getPosition().x;
	//position.y = spaceship.getPosition().y;
    //std::cout << "sapceship" << position.x;
    ship.setPosition(position);
}

//redraws the paddle
void Player::update(float secs)
{

	ship.setPosition(position);
}
