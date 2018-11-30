#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP


#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "GameApp.hpp"
#include "Player.hpp"
#include "Bullet.hpp"


class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void init();

		void handleEvents();
		void update(float dt);
		void draw(float dt);
        


	private:
    GameDataRef gameData;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::CircleShape defaultWeapon;
    sf::CircleShape secondaryWeapon;
    std::string weapontoggle;
    sf::CircleShape powerup;
    
    sf::Sprite heart1;
    sf::Sprite heart2;
    sf::Sprite heart3;
    
    sf::Time powertime;
    sf::Time  elapsedpowertime;
    sf::Clock powerclock;
    
    Player *spaceship;
    Bullet *bullet;
    
    float newshot;
    float cleanshot;
    int bulletstart_x;
    int bulletstart_y;

	};

#endif
