/**
	* Filename: GameState.hpp
	*
	* This is the second wave of the game.
**/

#ifndef GAMESTATE2_HPP
#define GAMESTATE2_HPP


#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <vector>


#include "Global.hpp"
#include "State.hpp"
#include "GameApp.hpp"

#include "MenuState.hpp"
#include "PauseState.hpp"
#include "GameOverState.hpp"

#include "Player.hpp"
#include "Bullet.hpp"
#include "Goomba.hpp"

#include "GameOverState.hpp"
#include "Koopa.hpp"



class GameState : public State {

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
    sf::CircleShape shield;
    std::string weapontoggle;
    sf::CircleShape powerup;

    sf::Sprite heart1;
    sf::Sprite heart2;
    sf::Sprite heart3;

    sf::Time powertime;
    sf::Time  elapsedpowertime;
    sf::Clock powerclock;
		sf::Clock gameClock;
		sf::Time gameTime;
		float currGameTime;

    int powercolor;

    Player *spaceship;
    Bullet *bullet;
    Bullet *backbullet;
		std::vector<Goomba> goombas;
		int goombaSpawnTimer;
		int goombaSpawnSpeed;

		std::vector<Koopa> koopas;
		int koopaSpawnTimer;
		int koopaSpawnSpeed;

    float newshot;
    float cleanshot;
    int bulletstart_x;
    int bulletstart_y;

		sf::SoundBuffer play_Theme;
		sf::SoundBuffer laser_Buffer;
		sf::Sound playTheme;
		sf::Sound laser;

		sf::Font font;
		sf::Text shotcount;
		std::string shotcountstring;

    bool piercing;
    bool backbool;
    bool shieldfollow;
    bool bigbool;

    sf::Text enemytext;
    std::string killcountstring;
    sf::Text killcount;
    int killint;

		//mouse cursor
		sf::Sprite mouseSprite;

};


#endif
