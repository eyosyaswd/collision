#include <iostream>
#include <SFML/Graphics.hpp>
#include "Global.hpp"
#include "Player.hpp"

// creates the player class, a sprite with size, position and color
Player::Player(GameDataRef data) : gameData(data)
{
  boxSprite.left = 0;
  boxSprite.top = 200;
  boxSprite.width = 50;
  boxSprite.height = 50;
  this->gameData->resourceManager.loadTexture("ship", SPRITE_SHEET_FILEPATH);
  ship.setTexture(this->gameData->resourceManager.getTexture("ship"));


  ship.setTextureRect(boxSprite);

  position.x = ship.getPosition().x;
  position.y = ship.getPosition().y;

  ship.setPosition(position);

}

void Player::draw()
{
  gameData->window.draw(ship);
}

sf::FloatRect Player::getPosition()
{ return ship.getGlobalBounds(); }

//returns sprite
sf::Sprite Player::getShape()
{
  return ship;
}

//keyboard input up arrow to move spaceship
void Player::moveUp()
{
  position.y -= velocity;
  upDir = true;
  downDir = false;
  leftDir = false;
  rightDir = false;
  boxSprite.left = 0;
  boxSprite.top = 200;
  boxSprite.width = 50;
  boxSprite.height = 50;
  ship.setTextureRect(boxSprite);

}

//keyboard input down arrow to move spaceship
void Player::moveDown()
{
  position.y += velocity;
  downDir = true;
  upDir = false;
  leftDir = false;
  rightDir = false;
  boxSprite.left = 0;
  boxSprite.top = 250;
  boxSprite.width = 50;
  boxSprite.height = 50;
  ship.setTextureRect(boxSprite);
}

//moves spaceship Left
void Player::moveLeft()
{
  position.x -= velocity;
  leftDir = true;
  rightDir = false;
  downDir = false;
  upDir = false;
  boxSprite.left = 50;
  boxSprite.top = 250;
  boxSprite.width = 50;
  boxSprite.height = 50;
  ship.setTextureRect(boxSprite);
}

//moves spaceship Right
void Player::moveRight()
{
  position.x += velocity;
  rightDir = true;
  leftDir = false;
  downDir = false;
  upDir = false;
  boxSprite.left = 50;
  boxSprite.top = 200;
  boxSprite.width = 50;
  boxSprite.height = 50;
  ship.setTextureRect(boxSprite);
}

void Player::animate(float dt){
  if (clock.getElapsedTime().asSeconds() > 0.2f)
  {
    if (upDir == true and downDir == false)
    {
      if(boxSprite.left == 0 and boxSprite.top == 200)
      {
        boxSprite.left = 100;
        boxSprite.top == 200;
      }
      else
      {
        boxSprite.left = 0;
        boxSprite.top == 200;
      }
    //ship.setTextureRect(boxSprite);
  }
    if (upDir == false and downDir == true)
    {
      if(boxSprite.left == 0 and boxSprite.top == 250)
      {
        boxSprite.left = 100;
        boxSprite.top = 250;
      }
      else
      {
        boxSprite.left = 0;
        boxSprite.top = 250;
      }
      //ship.setTextureRect(boxSprite);
    }
    if (leftDir == true and rightDir == false)
    {
      if(boxSprite.left == 50 and boxSprite.top == 250)
      {
        boxSprite.left = 150;
        boxSprite.top == 250;
      }
      else
      {
        boxSprite.left = 50;
        boxSprite.top == 250;
      }
    //ship.setTextureRect(boxSprite);
  }
    if (leftDir == false and rightDir == true)
    {
      if(boxSprite.left == 50 and boxSprite.top == 200)
      {
        boxSprite.left = 150;
        boxSprite.top = 200;
      }
      else
      {
        boxSprite.left = 50;
        boxSprite.top = 200;
      }
      //ship.setTextureRect(boxSprite);
    }

    ship.setTextureRect(boxSprite);
    clock.restart();
  }
}

//Sets spaceship position
void Player::set()
{
  ship.setPosition(position);
}

void Player::hit()
{
  if (upDir == true and downDir == false)
  {
    ship.setTextureRect(sf::IntRect(200,200,50,50));
  }
  if (upDir == false and downDir == true)
  {

    ship.setTextureRect(sf::IntRect(200,250,50,50));
  }
  if (leftDir == true and rightDir == false)
  {
    ship.setTextureRect(sf::IntRect(250,250,50,50));
  }
  if (leftDir == false and rightDir == true)
  {
    ship.setTextureRect(sf::IntRect(250,200,50,50));
  }
  //ship.setTextureRect(sf::IntRect(0,0,0,0));
}

//redraws the paddle
void Player::update(float secs)
{
  //upDir = true;
  //downDir = false;
  //rightDir = false;
  //leftDir = false;

	ship.setPosition(position);
}
