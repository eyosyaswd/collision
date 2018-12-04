/**
  * Filename: Koopa.hpp
**/

#include "Koopa.hpp"
#include "Global.hpp"


Koopa::Koopa(GameDataRef data) : gameData(data) {

    //TODO: Change filepath to Koopa spaceship color
    this->gameData->resourceManager.loadTexture("koopa", SPRITE_SHEET_FILEPATH);
    koopa.setTexture(this->gameData->resourceManager.getTexture("koopa"));

    boxSprite.left = 350;
    boxSprite.top = 0;
    boxSprite.width = 50;
    boxSprite.height = 50;
    koopa.setTextureRect(boxSprite);

    position.x = rand() % int(gameData->window.getSize().x - 50);
    position.y = 0.f; // TODO: Randomize the starting positions and movement

    koopa.setPosition(position);
}

Koopa::Koopa(GameDataRef data, std::string direction) : gameData(data) {

    this->direction = direction;

    this->gameData->resourceManager.loadTexture("koopa", SPRITE_SHEET_FILEPATH);
    koopa.setTexture(this->gameData->resourceManager.getTexture("koopa"));

    // TODO: Might have to tweak spawn locations
    if(direction == "down") { ;
        position.x = rand() % int(gameData->window.getSize().x - 50);
        position.y = 0.f;
    }

    if(direction == "up") {
        position.x = rand() % int(gameData->window.getSize().x - 50);
        position.y = int(gameData->window.getSize().y - 100);
    }

    if(direction == "right") {
        koopa.setTextureRect(sf::IntRect(350,50,50,50));
        position.x = 0.f;
        position.y = rand() % int(gameData->window.getSize().y - 50); // TODO: Randomize the starting positions and movement
    }

    if(direction == "left") {
      koopa.setTextureRect(sf::IntRect(350,0,50,50));

        position.x = int(gameData->window.getSize().x - 100);
        position.y = rand() % int(gameData->window.getSize().y - 50); // TODO: Randomize the starting positions and movement
    }

    koopa.setPosition(position);
}


Koopa::~Koopa() {}


void Koopa::draw() {
    gameData->window.draw(koopa);
}


void Koopa::animate(float secs) {
  if (clock.getElapsedTime().asSeconds() > 0.5f)
  {
    if (leftDir == true)
    {
      if(boxSprite.left == 350 and boxSprite.top == 0)
      {
        boxSprite.left = 350;
        boxSprite.top == 100;
      }
      else
      {
        boxSprite.left = 350;
        boxSprite.top == 0;
      }
    //ship.setTextureRect(boxSprite);
  }
    if (rightDir == true)
    {
      if(boxSprite.left == 350 and boxSprite.top == 50)
      {
        boxSprite.left = 350;
        boxSprite.top = 150;
      }
      else
      {
        boxSprite.left = 350;
        boxSprite.top = 50;
      }
      //ship.setTextureRect(boxSprite);
    }
    koopa.setTextureRect(boxSprite);
    clock.restart();
  }
}

void Koopa::hit(){
  if(rightDir == true){
    koopa.setTextureRect(sf::IntRect(350,200,50,50));
  }
  if(leftDir == true){
    koopa.setTextureRect(sf::IntRect(350,250,50,50));
  }
}



sf::Sprite Koopa::getShape() {
    return koopa;
}


void Koopa::moveUp() {
    position.y -= velocity;
}


void Koopa::moveDown() {
    position.y += velocity;
}


void Koopa::moveLeft() {
    position.x -= velocity;
    leftDir = true;
    rightDir = false;
    boxSprite.left = 350;
    boxSprite.top = 50;
    boxSprite.width = 50;
    boxSprite.height = 50;
    koopa.setTextureRect(boxSprite);
}


void Koopa::moveRight() {
    position.x += velocity;
    leftDir = false;
    rightDir = true;
    boxSprite.left = 350;
    boxSprite.top = 0;
    boxSprite.width = 50;
    boxSprite.height = 50;
    koopa.setTextureRect(boxSprite);
}


void Koopa::setPosition(sf::Vector2f) {
    koopa.setPosition(position);
}


void Koopa::update(float secs) {
    koopa.setPosition(position);
}


sf::Vector2f Koopa::getPosition() {
    return position;
}

std::string Koopa::getDirection() {
  return direction;
}
