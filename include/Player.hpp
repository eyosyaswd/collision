#include <SFML/Graphics.hpp>
#include "GameApp.hpp"
#pragma once

// This is the player class, it creates the paddle ojects that
// the player can control with the keyboard.


	class Player
	{
	public:
        Player(GameDataRef data);
        ~Player();
        
        void draw();
        
        void animate(float secs);
        
		//Player(float startX, float startY);
		//sf::FloatRect getPosition();
		sf::RectangleShape getShape();
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
		void update(float secs);
        void set();
        sf::Vector2f position;

	private:
		sf::RectangleShape spaceship;
		float velocity = 5.f;
        GameDataRef gameData;
        
        sf::Clock clock;
		

	};
