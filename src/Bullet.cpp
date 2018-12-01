/**
  * Filename: Bullet.cpp
**/

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Bullet.hpp"
#include "Player.hpp"


// creates the player class, a RectangleShape with size, position and color
//Player::Player(float startX, float startY)
//{
//	position.x = startX;
//	position.y = startY;

//	spaceship.setSize(sf::Vector2f(30,50));
//	spaceship.setPosition(position);
//	spaceship.setFillColor(sf::Color::Red);
//}

Bullet::Bullet(GameDataRef data) : gameData(data)
{

    //spaceship = new Player(gameData);

    position.x = -500;
	position.y = -500;

	bullet.setRadius(7);
	bullet.setPosition(position);
	bullet.setFillColor(sf::Color::White);

}

void Bullet::draw(){

        gameData->window.draw(bullet);

}

void Bullet::move(float shot){
    //if(position.x < 0 || position.x > 1100 || position.y > 850 || position.y < 0){
    //bullet.move(cos(newshot) * 0.5f, 0);
    //bullet.setPosition(x,y);
    position.x = position.x + cos(shot) * 30.0;
    position.y = position.y;
    bullet.setPosition(position);
    //bullet.move(0, sin(newshot) * 0.5f);
    position.x = position.x;
    position.y = position.y + sin(shot) * 30.0;

    //position.x = position.x + 20;
    //position.y = position.y + 20;
    bullet.setPosition(position);

    //}

}

void Bullet::set(int x, int y){
    position.x = x;
	position.y = y;
    bullet.setPosition(position);
}

void Bullet::modify(std::string power){
        if(power == "big"){
                bullet.setFillColor(sf::Color::Yellow);
                bullet.setRadius(20);
        }
        if(power == "double"){
                bullet.setFillColor(sf::Color::Blue);
                bullet.setRadius(7);
        }
        if(power == "pierce"){
                bullet.setFillColor(sf::Color::Green);
                bullet.setRadius(7);
        }
}







//redraws the paddle
void Bullet::update(float secs)
{
	bullet.setPosition(position);
}
