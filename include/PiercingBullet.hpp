#include <SFML/Graphics.hpp>
#pragma once

// This is the default bullet class

	class Bullet
	{
	public:
		Bullet(float StartX, float startY);
		sf::CircleShape getShape();
		sf::FloatCircle getPosition();
		void update();
		sf::Vector2f position;
	
	private:
		sf::CircleShape bullet;
	
	};