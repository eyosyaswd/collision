/**
	* Filename: Bullet.BULLET_HPP
	*
	* Represents a bullet.
**/

#ifndef BULLET_HPP
#define BULLET_HPP


#include <math.h>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "GameApp.hpp"
#include "Player.hpp"


class Bullet {
	public:
    Bullet(GameDataRef data);
    ~Bullet();

    void draw();
		sf::CircleShape getShape();
		void move(float shot);
    sf::Vector2f position;
    void set(int x, int y);
    void update(float secs);
    void modify(std::string power);
    std::string getType();
    void backmove(float shot);

	private:
		sf::CircleShape bullet;
    GameDataRef gameData;
    sf::Clock clock;
		Player *spaceship;


};

#endif
