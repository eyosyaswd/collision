#include "Player.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

// creates the player class, a RectangleShape with size, position and color
//Player::Player(float startX, float startY)
//{
//	position.x = startX;
//	position.y = startY;

//	spaceship.setSize(sf::Vector2f(30,50));
//	spaceship.setPosition(position);
//	spaceship.setFillColor(sf::Color::Red);
//}

Player::Player(GameDataRef data) : gameData(data)
{
    position.x = spaceship.getPosition().x;
    position.y = spaceship.getPosition().y;
    
	spaceship.setSize(sf::Vector2f(30,50));
	spaceship.setPosition(position);
	spaceship.setFillColor(sf::Color::Red);
    
}

void Player::draw(){
        gameData->window.draw(spaceship);
}

void Player::animate(float secs){
    
}

// gets bounding box bounds
//sf::FloatRect Player::getPosition()
//{ return spaceship.getGlobalBounds(); }

//returns ranctablge shape
sf::RectangleShape Player::getShape()
{ return spaceship; }

//keyboard input up arrow to move paddle
void Player::moveUp()
{ 
    position.y -= velocity; 
    
}

//keyboard input down arrow to move paddle
void Player::moveDown()
{ 
    position.y += velocity;
    
}

void Player::moveLeft()
{ position.x -= velocity; }


void Player::moveRight()
{ position.x += velocity; }

void Player::set(){
    position.x = spaceship.getPosition().x;
	position.y = spaceship.getPosition().y;
    std::cout << "sapceship" << position.x;  
    spaceship.setPosition(position);
}

//redraws the paddle
void Player::update(float secs)
{
    
	spaceship.setPosition(position);
}
