#include <iostream>
#include <SFML/Graphics.hpp>
#include "Global.hpp"
#include "Player.hpp"

// creates the player class, a sprite with size, position and color
Player::Player(GameDataRef data) : gameData(data)
{

  this->gameData->resourceManager.loadTexture("ship", SPRITE_SHEET_FILEPATH);
  ship.setTexture(this->gameData->resourceManager.getTexture("ship"));
  //sf::IntRect box(0,200,50,50);
  boxSprite.left = 0;
  boxSprite.top = 200;
  boxSprite.width = 50;
  boxSprite.height = 50;
  ship.setTextureRect(boxSprite);

  position.x = ship.getPosition().x;
  position.y = ship.getPosition().y;

  ship.setPosition(position);

}

void Player::draw()
{
  gameData->window.draw(ship);
}


// gets bounding box bounds
//sf::FloatRect Player::getPosition()
//{ return spaceship.getGlobalBounds(); }

//returns sprite
sf::Sprite Player::getShape()
{
  return ship;
}

//keyboard input up arrow to move spaceship
void Player::moveUp()
{
  position.y -= velocity;
  ship.setTextureRect(sf::IntRect(0,200,50,50));

}

//keyboard input down arrow to move spaceship
void Player::moveDown()
{
  position.y += velocity;
  ship.setTextureRect(sf::IntRect(0,250,50,50));
}

//moves spaceship Left
void Player::moveLeft()
{
  position.x -= velocity;
  ship.setTextureRect(sf::IntRect(50,250,50,50));
}

//moves spaceship Right
void Player::moveRight()
{
  position.x += velocity;
  ship.setTextureRect(sf::IntRect(50,200,50,50));
}

//Sets spaceship position
void Player::set()
{
  ship.setPosition(position);
}

void Player::hit()
{
  ship.setTextureRect(sf::IntRect(0,0,0,0));
}

//redraws the paddle
void Player::update(float secs)
{
	ship.setPosition(position);
}
