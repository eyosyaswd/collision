#include <sstream>
#include "GameState.hpp"
#include "MenuState.hpp"
#include "Global.hpp"
#include "PauseState.hpp"
#include "WinState.hpp"
#include "LoseState.hpp"
#include "Player.hpp"
#include <iostream>
#include "Bullet.hpp"

float newshot = 0.0f;


    
   



GameState::GameState(GameDataRef data) : gameData(data)
	{

	}

	void GameState::init()
	{
    this->gameData->resourceManager.loadTexture("GameState Background", GAME_STATE_BACKGROUND_FILEPATH);
    backgroundSprite.setTexture(this->gameData->resourceManager.getTexture("GameState Background"));
    
    spaceship = new Player(gameData);
    bullet = new Bullet(gameData);
    
    //sets up weapon toggle
    std::string weapontoggle = "selectsecondary";
    defaultWeapon.setRadius(25);
    defaultWeapon.setPosition(50, 750);
    secondaryWeapon.setRadius(15);
    secondaryWeapon.setPosition(100, 750);


    


    




    
	}

	void GameState::handleEvents()
	{
		sf::Event event;

        
        
        
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

				this->gameData->stateManager.pushState(StateRef(new PauseState(gameData)), false);
        }
        
        

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        { this->gameData->window.close();}
	     }
	     
	    
         //different weapon toggle system, switches between bullets, active bullet displays larger, need to calibrate sizes still
         if(event.type == sf::Event::MouseWheelMoved){
                if(weapontoggle == "selectsecondary"){
                    defaultWeapon.setRadius(15);
                    secondaryWeapon.setRadius(25);
                    weapontoggle = "selectprimary";
                }
                else{
                    defaultWeapon.setRadius(25);
                    secondaryWeapon.setRadius(15);
                    weapontoggle = "selectsecondary";
                }
                
         }

        
     }
     
     
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        { spaceship->moveDown();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)|| sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        { spaceship->moveUp();}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        { spaceship->moveLeft();}
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        { spaceship->moveRight();}
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            bullet->set();
            
            //sf::Vector2f mousePosition = this->gameData->window.mapPixelToCoords(sf::Mouse::getPosition(this->gameData->window));
            
            //float cleanshot = atan2(sf::Mouse::getPosition(this->gameData->window).y - 500,
              //                   sf::Mouse::getPosition(this->gameData->window).x - 500);
            //newshot = cleanshot;
            
            //bullet->move(newshot);
        }
             
             
        //testing cycling through the various kind of bullets - will depend on colliding with power-ups later, but for now just toggle through them with keys as a test     
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) || sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        { bullet->modify("big");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) || sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        { bullet->modify("pierce");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::O) || sf::Keyboard::isKeyPressed(sf::Keyboard::O))
        { bullet->modify("double");
        }
        


     
   }

	void GameState::update(float dt)
	{
        spaceship->update(dt);
        bullet->update(dt);
	}

	void GameState::draw(float dt)
	{
		this->gameData->window.clear(sf::Color::Red);

    this->gameData->window.draw(backgroundSprite);
    spaceship->draw();
    bullet->draw();
    this->gameData->window.draw(defaultWeapon);
    this ->gameData ->window.draw(secondaryWeapon);

		this->gameData->window.display();
	}
