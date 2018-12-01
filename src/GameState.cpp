#include <sstream>
#include <iostream>

#include "Global.hpp"
#include "GameState.hpp"
#include "GameState2.hpp"
#include "MenuState.hpp"
#include "PauseState.hpp"
#include "WinState.hpp"
#include "LoseState.hpp"
#include "Player.hpp"
#include "Bullet.hpp"
#include <SFML/Audio.hpp>










GameState::GameState(GameDataRef data) : gameData(data)
	{
        bullet = new Bullet(gameData);

	}

	void GameState::init()
	{
    this->gameData->resourceManager.loadTexture("GameState1 Background", GAME_STATE1_BACKGROUND_FILEPATH);
    backgroundSprite.setTexture(this->gameData->resourceManager.getTexture("GameState1 Background"));

    if (!play_Theme.loadFromFile("../res/sounds/confrontation.wav"))
        std::cout << "Error occured while loading music " << std::endl;
    else {
        playTheme.setBuffer(play_Theme);
        playTheme.setLoop(true);
        playTheme.play();
        }

    spaceship = new Player(gameData);
    goomba = new Goomba(gameData);

    //sets up weapon toggle
    std::string weapontoggle = "selectsecondary";
    defaultWeapon.setRadius(24);
    defaultWeapon.setPosition(50, 750);
    secondaryWeapon.setRadius(12);
    secondaryWeapon.setPosition(100, 750);



    this->gameData->resourceManager.loadTexture("heart", "../res/images/heart.png"); //having trouble getting it to recognize HEART_PATH in global, help would be great
    heart1.setTexture(this->gameData->resourceManager.getTexture("heart"));
    heart1.setPosition(20,50);
    heart1.setScale(sf::Vector2f(0.1f, 0.1f));
    heart2.setTexture(this->gameData->resourceManager.getTexture("heart"));
    heart2.setPosition(70,50);
    heart2.setScale(sf::Vector2f(0.1f, 0.1f));
    heart3.setTexture(this->gameData->resourceManager.getTexture("heart"));
    heart3.setPosition(120,50);
    heart3.setScale(sf::Vector2f(0.1f, 0.1f));

    powerup.setRadius(30);
    powerup.setOutlineThickness(10);
    powerup.setOutlineColor(sf::Color::White);
    powerup.setPosition(1500,1500);

    sf::Time powertime;
    sf::Time  elapsedpowertime;
    sf::Clock powerclock;
















	}

	void GameState::handleEvents() {
        sf::Event event;


<<<<<<< HEAD
		while (this->gameData->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->gameData->window.close();
			}



      if (event.type == sf::Event::KeyPressed)
      {
        if (event.key.code == sf::Keyboard::Space)
        {

				this->gameData->stateManager.pushState(StateRef(new PauseState(this->gameData)), false);
        }
=======
        while (this->gameData->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                this->gameData->window.close();
            }
>>>>>>> 47721da557e5c2ae34938d0a82bd8b56a8107e22


            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {

                    this->gameData->stateManager.pushState(StateRef(new PauseState(gameData)), false);
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { this->gameData->window.close(); }
            }

			 // switch to GameState2
			 if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
				 this->gameData->stateManager.pushState(StateRef(new GameState2(this->gameData)), true);
			 }

            //different weapon toggle system, switches between bullets, active bullet displays larger, need to calibrate sizes still
            if (event.type == sf::Event::MouseWheelMoved) {


                if (weapontoggle == "selectsecondary") {
                    defaultWeapon.setRadius(12);
                    secondaryWeapon.setRadius(24);
                    secondaryWeapon.setPosition(80, 750);
                    weapontoggle = "selectprimary";
                } else {
                    defaultWeapon.setRadius(24);
                    secondaryWeapon.setRadius(12);
                    secondaryWeapon.setPosition(100, 750);
                    weapontoggle = "selectsecondary";
                }

            }


        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            spaceship->moveDown();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
                   sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { spaceship->moveUp(); }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { spaceship->moveLeft(); }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
                 sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { spaceship->moveRight(); }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {


            if (bullet->position.y > 850 || bullet->position.y < 0 || bullet->position.x > 1100 ||
                bullet->position.x < 0) {

                bullet->set(spaceship->position.x, spaceship->position.y);
                sf::Vector2f mousePosition = this->gameData->window.mapPixelToCoords(
                        sf::Mouse::getPosition(this->gameData->window));
                std::cout << mousePosition.x;
                std::cout << mousePosition.y;
                float cleanshot = atan2(sf::Mouse::getPosition(this->gameData->window).y - bullet->position.y,
                                        sf::Mouse::getPosition(this->gameData->window).x - bullet->position.x);
                newshot = cleanshot;

                if (bullet->position.y > 850 || bullet->position.y < 0 || bullet->position.x > 1100 ||
                    bullet->position.x < 0) {
                    bullet->set(spaceship->position.x, spaceship->position.y);

                    sf::Vector2f mousePosition = this->gameData->window.mapPixelToCoords(
                            sf::Mouse::getPosition(this->gameData->window));
                    std::cout << mousePosition.x;
                    std::cout << mousePosition.y;
                    float cleanshot = atan2(sf::Mouse::getPosition(this->gameData->window).y - bullet->position.y,
                                            sf::Mouse::getPosition(this->gameData->window).x - bullet->position.x);
                    newshot = cleanshot;
                }

            }


            //testing cycling through the various kind of bullets - will depend on colliding with power-ups later, but for now just toggle through them with keys as a test
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) || sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
                bullet->modify("big");

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) || sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
                bullet->modify("pierce");
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::O) || sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
                bullet->modify("double");
            }


        }
    }

        void GameState::update(float dt) {
            bullet->move(newshot);
            spaceship->update(dt);
            bullet->update(dt);
            goomba->update(dt);


            elapsedpowertime += powerclock.getElapsedTime();
            powertime = powerclock.getElapsedTime();
            powerclock.restart();

            if (elapsedpowertime.asSeconds() > 5) {
                int powercolor = rand() % 5 + 1;
                int powerx = rand() % 800 + 100;
                int powery = rand() % 700 + 100;
                if (powercolor == 1) {
                    powerup.setFillColor(sf::Color::Red);
                } else if (powercolor == 2) {
                    powerup.setFillColor(sf::Color::Magenta);
                } else if (powercolor == 3) {
                    powerup.setFillColor(sf::Color::Blue);
                } else if (powercolor == 4) {
                    powerup.setFillColor(sf::Color::Green);
                } else if (powercolor == 5) {
                    powerup.setFillColor(sf::Color::Yellow);
                }
                powerup.setPosition(powerx, powery);

                elapsedpowertime = sf::milliseconds(0);
            }


        }

        void GameState::draw(float dt) {
            this->gameData->window.clear(sf::Color::White);

            this->gameData->window.draw(backgroundSprite);
            spaceship->draw();
            goomba->draw();
            bullet->draw();
            this->gameData->window.draw(defaultWeapon);
            this->gameData->window.draw(secondaryWeapon);
            this->gameData->window.draw(heart1);
            this->gameData->window.draw(heart2);
            this->gameData->window.draw(heart3);
            this->gameData->window.draw(powerup);
            this->gameData->window.draw(powerup);


            this->gameData->window.display();
        }
