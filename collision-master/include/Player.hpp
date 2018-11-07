#include <SFML/Graphics.hpp>
#pragma once

// This is the player class, it creates the paddle ojects that
// the player can control with the keyboard.


	class Player
	{
	public:
		Player(float startX, float startY);
		sf::FloatRect getPosition();
		sf::RectangleShape getShape();
		void moveUp(float secs);
		void moveDown(float secs);
		void moveLeft(float secs);
		void moveRight(float secs);
		void update();
        sf::Vector2f position;

	private:
		sf::RectangleShape spaceship;
		float velocity = 300.f;
		

	};
