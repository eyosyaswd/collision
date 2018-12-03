/**
  * Filename: Goomba.hpp
**/

#include "Goomba.hpp"
#include "Global.hpp"


Goomba::Goomba(GameDataRef data) : gameData(data) {

  this->gameData->resourceManager.loadTexture("goomba", PINK_SHEET_FILEPATH);
  goomba.setTexture(this->gameData->resourceManager.getTexture("goomba"));
  goomba.setTextureRect(sf::IntRect(100,0,50,50));

  position.x = rand() % int(gameData->window.getSize().x - 50);
  position.y = 0.f; // TODO: Randomize the starting positions and movement

  goomba.setPosition(position);
}


Goomba::~Goomba() {}


void Goomba::draw() {
  gameData->window.draw(goomba);
}


void Goomba::animate(float secs) {}


sf::Sprite Goomba::getShape() {
  return goomba;
}


void Goomba::moveUp() {
  position.y -= velocity;
  goomba.setTextureRect(sf::IntRect(100,0,50,50));
}


void Goomba::moveDown() {
  position.y += velocity;
  goomba.setTextureRect(sf::IntRect(100,50,50,50));
}


void Goomba::moveLeft() {
  position.x -= velocity;
}


void Goomba::moveRight() {
  position.x += velocity;
}


void Goomba::setPosition(sf::Vector2f) {
  goomba.setPosition(position);
}


void Goomba::update(float secs) {
  goomba.setPosition(position);
}


sf::Vector2f Goomba::getPosition() {
  return position;
}
