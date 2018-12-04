/**
	* Filename: GameState2.cpp
**/

#include "GameState2.hpp"



GameState2::GameState2(GameDataRef data) : gameData(data) {}


void GameState2::init() {
  currGameTime = 0.0f;

	// load background
  this->gameData->resourceManager.loadTexture("GameState1 Background", GAME_STATE1_BACKGROUND_FILEPATH);
  this->gameData->resourceManager.loadTexture("GameState2 Background", GAME_STATE2_BACKGROUND_FILEPATH);
  this->gameData->resourceManager.loadTexture("GameState3 Background", GAME_STATE3_BACKGROUND_FILEPATH);
  backgroundSprite.setTexture(this->gameData->resourceManager.getTexture("GameState1 Background"));


  //draws shot count in bottom left
  shotcountstring = "";
  shotcount.setFont(this->gameData->resourceManager.getFont("font"));
  shotcount.setFillColor(sf::Color::White);
  shotcount.setCharacterSize(70);
  shotcount.setString(shotcountstring);
  shotcount.setPosition(150, WINDOW_HEIGHT-100);

    shield.setRadius(50);
    shield.setPosition(-400,-400);
    shieldfollow = false;
    backbool = false;
    bigbool = false;

    enemytext.setFont(this->gameData->resourceManager.getFont("font"));
    enemytext.setFillColor(sf::Color::Red);
    enemytext.setCharacterSize(70);
    enemytext.setString("Enemies Destroyed: ");
    enemytext.setPosition(WINDOW_WIDTH - 300, WINDOW_HEIGHT - 100);

    killcountstring = "0";
    killcount.setFont(this->gameData->resourceManager.getFont("font"));
    killcount.setFillColor(sf::Color::Red);
    killcount.setCharacterSize(70);
    killcount.setString(killcountstring);
    killcount.setPosition(WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100);


	// initialize player, bullet, and enemies
  spaceship = new Player(gameData);
	bullet = new Bullet(gameData);
  backbullet = new Bullet(gameData);
  backbullet->setFillColor();
  goombaSpawnTimer = 0;
  goombaSpawnSpeed = 60;

  //Initializes sounds for the game
  if (!play_Theme.loadFromFile("../res/sounds/wave1.wav"))
     std::cout << "Error occured while loading music " << std::endl;
  else {
     playTheme.setBuffer(play_Theme);
     playTheme.setLoop(true);
     playTheme.play();
  }

  if (!laser_Buffer.loadFromFile("../res/sounds/laser.wav"))
      std::cout << "Error occured while loading music " << std::endl;
  else
  {
      laser.setBuffer(laser_Buffer);
  }

  // sets up weapon toggle
  std::string weapontoggle = "selectsecondary";
  defaultWeapon.setRadius(24);
  defaultWeapon.setPosition(50, 750);
  secondaryWeapon.setRadius(12);
  secondaryWeapon.setPosition(100, 750);

	// loads lives
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

  // loads powerups
  powerup.setRadius(30);
  powerup.setOutlineThickness(10);
  powerup.setOutlineColor(sf::Color::White);
  powerup.setPosition(1500,1500);
  piercing = false;
}


void GameState2::handleEvents() {
	sf::Event event;

	/* process events */
	while (this->gameData->window.pollEvent(event)) {

		// close event
		if (sf::Event::Closed == event.type) {
			this->gameData->window.close();
		}

		//different weapon toggle system, switches between bullets, active bullet displays larger, need to calibrate sizes still
		if(event.type == sf::Event::MouseWheelMoved){
    	if(weapontoggle == "selectsecondary"){
	      defaultWeapon.setRadius(12);
	      secondaryWeapon.setRadius(24);
	      secondaryWeapon.setPosition(80,750);
	      weapontoggle = "selectprimary";

          if (piercing == true){
            bullet->modify("pierce");
          }
          if (backbool == true){
            bullet->modify("double");
          }
          if(bigbool == true){
                bullet->modify("big");
          }
      }
      else{
	      defaultWeapon.setRadius(24);
	      secondaryWeapon.setRadius(12);
	      secondaryWeapon.setPosition(100, 750);
	      weapontoggle = "selectsecondary";
        bullet->modify("default");
      }
		}

	}

  /* proccess key inputs */
	// "Space" key pressed (pauses game)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
	    //Fix music on pause screen
	    playTheme.stop();
		this->gameData->stateManager.pushState(StateRef(new PauseState(gameData)), false);
	}

	// "Esc" key pressed (closes game)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		this->gameData->window.close();
	}

	// "Up" and "Down" keys pressed (moves player up and down)

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
  {
		spaceship->moveDown();
  }
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)|| sf::Keyboard::isKeyPressed(sf::Keyboard::W))
  {
    spaceship->moveUp();

	}

	// "Left" and "Right" keys pressed (moves player left and right)
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
  {
		spaceship->moveLeft();
	}
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
  {
		spaceship->moveRight();
	}


	// "Mouse Left-Click" pressed (player shoots bullets)
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
    if(bullet->position.y > 850 || bullet->position.y < 0 || bullet->position.x > 1100 || bullet->position.x < 0) {
    	bullet->set(spaceship->position.x,spaceship->position.y);
	    sf::Vector2f mousePosition = this->gameData->window.mapPixelToCoords(sf::Mouse::getPosition(this->gameData->window));

	    laser.play();

	    float cleanshot = atan2(sf::Mouse::getPosition(this->gameData->window).y - bullet->position.y, sf::Mouse::getPosition(this->gameData->window).x - bullet->position.x);
	    newshot = cleanshot;

        if(backbool == true and weapontoggle == "selectprimary"){
          backbullet->set(spaceship->position.x,spaceship->position.y);
        }

        if(weapontoggle == "selectprimary" && shotcountstring != ""){

            int shotint = std::stoi(shotcountstring);
            shotint = shotint - 1;
            shotcountstring = std::to_string(shotint);
            shotcount.setString(shotcountstring);
            if(shotint == 0){
                shotcountstring = "";
                shotcount.setString(shotcountstring);
                secondaryWeapon.setFillColor(sf::Color::White);
                bullet->modify("default");
                piercing = false;
                backbool = false;
                bigbool = false;
            }
        }

    }
  }







}


void GameState2::update(float dt) {
  spaceship->animate(dt);

  bullet->move(newshot);




  spaceship->update(dt);
  bullet->update(dt);

  if(backbool == true) {
    backbullet->backmove(newshot);
    backbullet->update(dt);
  }


  elapsedpowertime += powerclock.getElapsedTime();
  powertime = powerclock.getElapsedTime();
  powerclock.restart();
  gameTime = gameClock.getElapsedTime();
  currGameTime = gameTime.asSeconds();
  std::cout << currGameTime << std::endl;

  if (elapsedpowertime.asSeconds() > 17) {
    powercolor = rand() % 5 + 1;
    int powerx = rand() % 800 + 100;
    int powery = rand() % 700 + 100;
    if(powercolor == 1) {
      powerup.setFillColor(sf::Color::Red);
    }
    else if(powercolor == 2) {
      powerup.setFillColor(sf::Color::Magenta);
    }
    else if(powercolor == 3) {
      powerup.setFillColor(sf::Color::Blue);
    }
    else if(powercolor == 4) {
      powerup.setFillColor(sf::Color::Green);
    }
    else if(powercolor == 5) {
      powerup.setFillColor(sf::Color::Yellow);
    }
    powerup.setPosition(powerx,powery);

    elapsedpowertime = sf::milliseconds(0);
  }



  //power-up collision
  if(spaceship->getPosition().intersects(powerup.getGlobalBounds())){
      powerup.setPosition(-1000,-1000);
      if(powercolor == 3){
            secondaryWeapon.setFillColor(sf::Color::Blue);
            bullet->modify("double");
            shotcountstring = "20";
            shotcount.setString(shotcountstring);
            piercing = false;
            backbool = true;
            bigbool = false;
      }
      if(powercolor == 5){
            secondaryWeapon.setFillColor(sf::Color::Yellow);
            bullet->modify("big");
            shotcountstring = "20";
            shotcount.setString(shotcountstring);
            piercing = false;
            backbool = false;
            bigbool = true;
      }
      if(powercolor == 4){
            secondaryWeapon.setFillColor(sf::Color::Green);
            bullet->modify("pierce");
            shotcountstring = "20";
            shotcount.setString(shotcountstring);
            piercing = true;
            backbool = false;
            bigbool = false;
      }
      if(powercolor==2){
            shieldfollow = true;
            shield.setFillColor(sf::Color(255,255,255,128));
      }
      if(powercolor ==1){
            if(heart2.getPosition().x > 0 and heart1.getPosition().x > 0){
                    heart3.setPosition(120,50);
            }
            else
            {
                    heart2.setPosition(70,50);
            }


      }

          defaultWeapon.setRadius(12);
	      secondaryWeapon.setRadius(24);
	      secondaryWeapon.setPosition(80,750);
	      weapontoggle = "selectprimary";
  }

  if(shieldfollow == true){
        shield.setPosition(spaceship->position.x - 25,spaceship->position.y - 20);
  }


  // determine how fast goombas can spawn
  if (goombaSpawnTimer < goombaSpawnSpeed) {
    goombaSpawnTimer++;
 }

 // spawn goombas that move up
 if ((currGameTime > 70.0 && currGameTime < 120.0) || (currGameTime > 185.0)) {
   if (goombaSpawnTimer >= goombaSpawnSpeed) {
     goombas.push_back(Goomba(this->gameData, "up"));
   }
 }

 // spawn goombas that move down
 if ((currGameTime > 5.0 && currGameTime < 60.0) ||
     (currGameTime > 70.0 && currGameTime < 120.0) ||
     (currGameTime > 185.0)) {
    if (goombaSpawnTimer >= goombaSpawnSpeed) {
      goombas.push_back(Goomba(this->gameData, "down"));
      goombaSpawnTimer = 0;
    }
  }

  // move goombas down

  // move goombas
  for (size_t i = 0; i < goombas.size(); i++) {
    if (goombas[i].getDirection() == "down") {
      goombas[i].moveDown();
      // delete goombas if they go below the screen
      if (goombas[i].getPosition().y > this->gameData->window.getSize().y) {
        goombas.erase(goombas.begin() + i);
      }
    }
    else if (goombas[i].getDirection() == "up") {
      goombas[i].moveUp();
      // delete goombas if they go above the screen
      if (goombas[i].getPosition().y < 0) {
        goombas.erase(goombas.begin() + i);
      }
    }
    // TODO: animate goombas
    goombas[i].update(dt);

  }

  //Testing for Koopas
/*
    // spawn koopas that move down
    if (goombaSpawnTimer >= 50) {
        koopas.push_back(Koopa(this->gameData, "right"));
        goombaSpawnTimer = 0;
    }

    // move koopas down
    for (size_t i = 0; i < koopas.size(); i++) {
        koopas[i].moveDown();
        koopas[i].update(dt);

        // delete koopas if they go off the screen
        if (koopas[i].getPosition().x > this->gameData->window.getSize().x - 100) { // TODO: get rid of the '-100', only there for testing
            koopas.erase(koopas.begin() + i);
        }
    }
    */

  // collision of bullets and goombas
  if (!goombas.empty()) {
    for (size_t i = 0; i < goombas.size(); i++) {
      if (bullet->getShape().getGlobalBounds().intersects(goombas[i].getShape().getGlobalBounds())) {
        goombas[i].hit();

        int killint = std::stoi(killcountstring);
        killint++;
        killcountstring = std::to_string(killint);
        killcount.setString(killcountstring);

        // TODO: erase bullet
        goombas.erase(goombas.begin() + i);
        if(piercing == true and weapontoggle == "selectprimary"){
        /////
        }
        else{
          bullet->set(-10000000,-100000000);
        }
        break;
      }
    }
  }


  //playercollision
  if (!goombas.empty()) {
    for (size_t i = 0; i < goombas.size(); i++) {
      if (spaceship->getPosition().intersects(goombas[i].getShape().getGlobalBounds())) {
        // TODO: erase bullet
        spaceship->hit();
        goombas[i].hit();
        goombas.erase(goombas.begin() + i);
        if(shieldfollow == true){
            spaceship->hit();
            shield.setPosition(-1000,-1000);
            shieldfollow = false;
        }
        else{
        if(heart3.getPosition().x >= 0){
            spaceship->hit();
            heart3.setPosition(-100,0);
        }
        else if(heart2.getPosition().x > 0){
          spaceship->hit();
            heart2.setPosition(-100,0);
        }
        else{
            playTheme.stop();
            this->gameData->stateManager.pushState(StateRef(new LoseState(this->gameData)), true);
        }
        }

        break;
      }
    }
  }

  // change enemy spawn speeds based on time
  if (currGameTime > 10.0 && currGameTime < 20.0) {
    goombaSpawnSpeed = 40;
  }
  else if(currGameTime > 20.0 && currGameTime < 30.0) {
    goombaSpawnSpeed = 30;
  }
  else if(currGameTime > 30.0 && currGameTime < 45.0) {
    goombaSpawnSpeed = 20;
  }
  else if(currGameTime > 45.0 && currGameTime < 60.0) {
    goombaSpawnSpeed = 10;
  }
  else if(currGameTime > 60.0 && currGameTime < 70.0) {
    goombaSpawnSpeed = 50;
  }

}


void GameState2::draw(float dt) {
	this->gameData->window.clear(sf::Color::White);
  this->gameData->window.draw(backgroundSprite);

  this->gameData->window.draw(defaultWeapon);
  this->gameData->window.draw(secondaryWeapon);
  this->gameData->window.draw(heart1);
  this->gameData->window.draw(heart2);
  this->gameData->window.draw(heart3);
  this->gameData->window.draw(powerup);
  this->gameData->window.draw(powerup);
  this->gameData->window.draw(shotcount);
  this->gameData->window.draw(killcount);
  this->gameData->window.draw(enemytext);
  this->gameData->window.draw(shield);

  if(backbool == true){
    backbullet->draw();
  }

  spaceship->draw();
  bullet->draw();

  for (size_t i = 0; i < goombas.size(); i++) {
    goombas[i].draw();
  }

  this->gameData->window.display();
}
