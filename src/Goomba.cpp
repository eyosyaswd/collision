/**
  * Filename: Goomba.hpp
**/

#include "Goomba.hpp"


Goomba::Goomba(GameDataRef data) : gameData(data) {
  position.x = goomba.getPosition().x;
  position.y = goomba.getPosition().y;

  goomba.setSize(sf::Vector2f(20,20));
  goomba.setPosition(position);
  goomba.setFillColor(sf::Color::Blue);
}


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


void Goomba::set() {
  goomba.setPosition(position);
}


void Goomba::update(float secs) {
  goomba.setPosition(position);
}

sf::Vector2f Goomba::getPosition() {
  return position;
}
