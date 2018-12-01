/**
	* Filename: Enemy.cpp
**/

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Enemy.hpp"

// creates the player class, a RectangleShape with size, position and color
Enemy::Enemy(float startX, float startY)
{
	position.x = startX;
	position.y = startY;
  direction.x = 1.0;
  direction.y = 1.0;

	spaceship.setSize(sf::Vector2f(30,30));
	spaceship.setPosition(position);
	spaceship.setFillColor(sf::Color::White);
}

// gets bounding box bounds
sf::FloatRect Enemy::getPosition()
{ return spaceship.getGlobalBounds(); }

//returns ranctablge shape
sf::RectangleShape Enemy::getShape()
{ return spaceship; }

//keyboard input up arrow to move paddle
void Enemy::move(float secs) {
  // std::cout<<"Hello";
  //position.x += velocity*secs;
  //position.
  spaceship.move(direction.x * secs * velocity, direction.y * secs * velocity);
}

//redraws the paddle
void Enemy::update()
{
	spaceship.setPosition(position);
}
