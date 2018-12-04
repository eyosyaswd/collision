/**
  * Filename: Goomba.hpp
**/

#include "Goomba.hpp"
#include "Global.hpp"


Goomba::Goomba(GameDataRef data) : gameData(data) {

  this->gameData->resourceManager.loadTexture("goomba", PINK_SHEET_FILEPATH);
  goomba.setTexture(this->gameData->resourceManager.getTexture("goomba"));

  boxSprite.left = 100;
  boxSprite.top = 0;
  boxSprite.width = 50;
  boxSprite.height = 50;
  goomba.setTextureRect(boxSprite);

  position.x = rand() % int(gameData->window.getSize().x - 50);
  position.y = 0.f; // TODO: Randomize the starting positions and movement

  goomba.setPosition(position);
}

Goomba::Goomba(GameDataRef data, std::string direction) : gameData(data) {

  this->gameData->resourceManager.loadTexture("goomba", PINK_SHEET_FILEPATH);
  goomba.setTexture(this->gameData->resourceManager.getTexture("goomba"));

  // TODO: Might have to tweak spawn locations
  if(direction == "down") {

    goomba.setTextureRect(boxSprite);
    position.x = rand() % int(gameData->window.getSize().x - 50);
    position.y = 0.f;
  }

  if(direction == "up") {
    goomba.setTextureRect(sf::IntRect(100,50,50,50));
    position.x = rand() % int(gameData->window.getSize().x - 50);
    position.y = int(gameData->window.getSize().y - 100); //TODO: Spawn at edge of screen
  }

  if(direction == "right") {
    position.x = 0.f;
    position.y = rand() % int(gameData->window.getSize().y - 50); // TODO: Randomize the starting positions and movement
  }

  if(direction == "left") {
    position.x = int(gameData->window.getSize().x - 100);
    position.y = rand() % int(gameData->window.getSize().y - 50); // TODO: Randomize the starting positions and movement
  }

  goomba.setPosition(position);
}

Goomba::~Goomba() {}


void Goomba::draw() {
  gameData->window.draw(goomba);
}

sf::Sprite Goomba::getShape() {
  return goomba;
}

void Goomba::moveUp() {
  position.y -= velocity;
  upDir = true;
  downDir = false;
  boxSprite.left = 100;
  boxSprite.top = 0;
  boxSprite.width = 50;
  boxSprite.height = 50;
  goomba.setTextureRect(boxSprite);
  //goomba.setTextureRect(sf::IntRect(100,0,50,50));
}

void Goomba::moveDown() {
  position.y += velocity;
  upDir = false;
  downDir = true;
  boxSprite.left = 100;
  boxSprite.top = 50;
  boxSprite.width = 50;
  boxSprite.height = 50;
  goomba.setTextureRect(boxSprite);
  //goomba.setTextureRect(sf::IntRect(100,50,50,50));
}

void Goomba::moveLeft() {
  position.x -= velocity;
}

void Goomba::moveRight() {
  position.x += velocity;
}

void Goomba::hit(){
  if(downDir == true){
  goomba.setTextureRect(sf::IntRect(0,50,50,50));
  }
  if(upDir == true){
  goomba.setTextureRect(sf::IntRect(0,0,50,50));
  }
}

void Goomba::setPosition(sf::Vector2f) {
  goomba.setPosition(position);
}


void Goomba::update(float secs) {
  goomba.setPosition(position);
}

void Goomba::animate(float secs) {
  if (clock.getElapsedTime().asSeconds() > 0.5f)
  {
    if (upDir == true)
    {
      if(boxSprite.left == 100 and boxSprite.top == 0)
      {
        boxSprite.left = 50;
        boxSprite.top == 0;
      }
      else
      {
        boxSprite.left = 100;
        boxSprite.top == 0;
      }
    //ship.setTextureRect(boxSprite);
  }
    if (downDir == true)
    {
      if(boxSprite.left == 100 and boxSprite.top == 50)
      {
        boxSprite.left = 50;
        boxSprite.top = 50;
      }
      else
      {
        boxSprite.left = 100;
        boxSprite.top = 50;
      }
      //ship.setTextureRect(boxSprite);
    }
    goomba.setTextureRect(boxSprite);
    clock.restart();
  }
}

sf::Vector2f Goomba::getPosition() {
  return position;
}
