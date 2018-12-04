/**
	* Filename: Player.hpp
	*
	* This will represent the spaceship controlled by the player.
**/

#include <SFML/Graphics.hpp>
#include "GameApp.hpp"
#pragma once


class Player {

	public:
		Player(GameDataRef data);
		~Player();

		void draw();
		sf::Sprite getShape();
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
		void set();
		void animate(float secs);
		void update(float secs);
		void hit();
        sf::FloatRect getPosition();
		sf::Vector2f position;

	private:
		bool upDir;
		bool downDir;
		bool rightDir;
		bool leftDir;
		float velocity = 5.f;
		GameDataRef gameData;
		sf::Texture texture;
		sf::Clock clock;
		sf::Clock move;
		sf::Sprite ship;
		sf::IntRect boxSprite;
		std::vector<sf::Texture> frames;
		int shipState;

};
