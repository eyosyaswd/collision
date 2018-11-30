#include "Bullet.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
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

    spaceship = new Player(gameData);
    
    position.x = -100;
	position.y = -100;

	bullet.setRadius(7);
	bullet.setPosition(position);
	bullet.setFillColor(sf::Color::White);
    
}

void Bullet::draw(){
    
        gameData->window.draw(bullet);
        
}

void Bullet::move(float shot){
    bullet.move(cos(shot) * 0.5f, 0);
    bullet.move(0, sin(shot) * 0.5f);
}

void Bullet::set(){
    position.x = spaceship->position.x+500;
	position.y = spaceship->position.y+500;
    std::cout << "bullet" <<position.x;  
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


