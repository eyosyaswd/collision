/**
  * Filename: Bullet.cpp
**/


#include "Bullet.hpp"


Bullet::Bullet(GameDataRef data) : gameData(data) {
  position.x = -500;
	position.y = -500;

	bullet.setRadius(7);
	bullet.setPosition(position);
	bullet.setFillColor(sf::Color::White);
}


void Bullet::draw() {
  gameData->window.draw(bullet);
}


void Bullet::move(float shot) {
  position.x = position.x + cos(shot) * 30.0;
  position.y = position.y;
  bullet.setPosition(position);

  position.x = position.x;
  position.y = position.y + sin(shot) * 30.0;

  bullet.setPosition(position);
}


void Bullet::backmove(float shot) {
  position.x = position.x - cos(shot) * 30.0;
  position.y = position.y;
  bullet.setPosition(position);

  position.x = position.x;
  position.y = position.y - sin(shot) * 30.0;

  bullet.setPosition(position);
}


void Bullet::set(int x, int y) {
  position.x = x;
  position.y = y;
  bullet.setPosition(position);
}

void Bullet::modify(std::string power) {
  if(power == "big") {
    bullet.setFillColor(sf::Color::Yellow);
    bullet.setRadius(20);
  }
  if(power == "double") {
    bullet.setFillColor(sf::Color::Blue);
    bullet.setRadius(7);
  }
  if(power == "pierce") {
    bullet.setFillColor(sf::Color::Green);
    bullet.setRadius(7);
  }
  if(power == "default") {
    bullet.setFillColor(sf::Color::White);
    bullet.setRadius(7);
  }
}


void Bullet::setFillColor() {
  bullet.setFillColor(sf::Color::Blue);
}


void Bullet::update(float secs) {
	bullet.setPosition(position);
}


sf::CircleShape Bullet::getShape() {
  return bullet;
}

std::string Bullet::getType() {
  return power;
}
