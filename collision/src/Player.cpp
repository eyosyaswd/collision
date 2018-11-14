#include "Player.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

// creates the player class, a RectangleShape with size, position and color
Player::Player(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	spaceship.setSize(sf::Vector2f(30,50));
	spaceship.setPosition(position);
	spaceship.setFillColor(sf::Color::Red);
}

// gets bounding box bounds
sf::FloatRect Player::getPosition()
{ return spaceship.getGlobalBounds(); }

//returns ranctablge shape
sf::RectangleShape Player::getShape()
{ return spaceship; }

//keyboard input up arrow to move paddle
void Player::moveUp(float secs)
{ position.y -= velocity*secs; }

//keyboard input down arrow to move paddle
void Player::moveDown(float secs)
{ position.y += velocity*secs; }

void Player::moveLeft(float secs)
{ position.x -= velocity*secs; }


void Player::moveRight(float secs)
{ position.x += velocity*secs; }

//redraws the paddle
void Player::update()
{
	spaceship.setPosition(position);
}
