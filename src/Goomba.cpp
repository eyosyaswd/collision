/**
  * Filename: Goomba.hpp
**/

#include "Goomba.hpp"


Goomba::Goomba(GameDataRef data) : gameData(data) {
  goomba.setSize(sf::Vector2f(50.f, 50.f));

  position.x = rand() % int(gameData->window.getSize().x - goomba.getSize().x);
  position.y = 0.f; // TODO: Randomize the starting positions and movement
  goomba.setPosition(position);

  goomba.setFillColor(sf::Color::Blue);
}


Goomba::~Goomba() {}


void Goomba::draw() {
  gameData->window.draw(goomba);
}


void Goomba::animate(float secs) {}


sf::RectangleShape Goomba::getShape() {
  return goomba;
}


void Goomba::moveUp() {
  position.y -= velocity;
}


void Goomba::moveDown() {
  position.y += velocity;
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


sf::Vector2f Goomba::getSize() {
  return goomba.getSize();
}
