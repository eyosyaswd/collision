#include "Bullet.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

Bullet:Bullet(float startX, float startY)
{
		position.x = startX;
		position.y = startY;
		
		bullet.setRadius(7);
		bullet.setPosition(position);
		bullet.setFillColor(sf::Color::White);
}


sf::FloatCircle Bullet::getPosition()
{ return bullet.getGlobalBounds(); }

sf::CircleShape Bullet::getShape()
{ return bullet; }

void Bullet::update()
{
		bullet.setPosition(position);
}
	
	

