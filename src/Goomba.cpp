#include "Goomba.hpp"

Goomba::Goomba(GameDataRef data) : gameData(data)
{
    position.x = goomba.getPosition().x;
    position.y = goomba.getPosition().y;

    goomba.setSize(sf::Vector2f(20,20));
    goomba.setPosition(position);
    goomba.setFillColor(sf::Color::Blue);

}

void Goomba::draw(){
    gameData->window.draw(goomba);
}

void Goomba::animate(float secs){

}

// gets bounding box bounds
//sf::FloatRect Goomba::getPosition()
//{ return goomba.getGlobalBounds(); }

//returns ranctablge shape
sf::RectangleShape Goomba::getShape()
{ return goomba; }

//keyboard input up arrow to move paddle
void Goomba::moveUp()
{
    position.y -= velocity;

}

//keyboard input down arrow to move paddle
void Goomba::moveDown()
{
    position.y += velocity;

}

void Goomba::moveLeft()
{ position.x -= velocity; }


void Goomba::moveRight()
{ position.x += velocity; }

void Goomba::set(){
    //position.x = goomba.getPosition().x;
    //position.y = goomba.getPosition().y;
    //std::cout << "sapceship" << position.x;  
    goomba.setPosition(position);
}

//redraws the paddle
void Goomba::update(float secs)
{

    goomba.setPosition(position);
}

sf::Vector2f Goomba::getPosition()
{
    return position;
    }