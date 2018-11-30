#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>
#include "GameApp.hpp"
#include "Player.hpp"
#include <iostream>
#pragma once


// This is the player class, it creates the paddle ojects that
// the player can control with the keyboard.


	class Bullet
	{
	public:
        Bullet(GameDataRef data);
        ~Bullet();
        
        void draw();
        
        
        
		
		sf::CircleShape getShape();
		void move(float shot);
        sf::Vector2f position;
        void set();
        void update(float secs);
        void modify(std::string power);

	private:
		sf::CircleShape bullet;
        GameDataRef gameData;
        
        sf::Clock clock;
		Player *spaceship;

	};

#endif
