/**
	* Filename: GameState2.cpp
**/

#include "GameState2.hpp"


GameState2::GameState2(GameDataRef data) : gameData(data) {}


void GameState2::init() {
	// load background
  this->gameData->resourceManager.loadTexture("GameState2 Background", GAME_STATE2_BACKGROUND_FILEPATH);
  backgroundSprite.setTexture(this->gameData->resourceManager.getTexture("GameState2 Background"));

	// initialize player, bullet, and enemies
  spaceship = new Player(gameData);
	bullet = new Bullet(gameData);
  goombaSpawnTimer = 0;

    //TODO: uncomment music later, only turned it off for testing

    //Initializes sounds for the game
     if (!play_Theme.loadFromFile("../res/sounds/wave2.wav"))
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
      }
      else{
	      defaultWeapon.setRadius(24);
	      secondaryWeapon.setRadius(12);
	      secondaryWeapon.setPosition(100, 750);
	      weapontoggle = "selectsecondary";
      }
		}

	}

  /* proccess key inputs */
	// "Space" key pressed (pauses game)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
	    playTheme.stop();
		this->gameData->stateManager.pushState(StateRef(new PauseState(gameData)), false);
	}

	// "Esc" key pressed (closes game)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		this->gameData->window.close();
	}

	// "Up" and "Down" keys pressed (moves player up and down)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		spaceship->moveDown();
  }
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)|| sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    spaceship->moveUp();

	}

	// "Left" and "Right" keys pressed (moves player left and right)
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		spaceship->moveLeft();
	}
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
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


void GameState2::update(float dt) {
  bullet->move(newshot);
  spaceship->update(dt);
  bullet->update(dt);

  elapsedpowertime += powerclock.getElapsedTime();
  powertime = powerclock.getElapsedTime();
  powerclock.restart();

  if (elapsedpowertime.asSeconds() > 5) {
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
      }
      if(powercolor == 5){
            secondaryWeapon.setFillColor(sf::Color::Yellow);
            bullet->modify("big");
      }
      if(powercolor == 4){
            secondaryWeapon.setFillColor(sf::Color::Green);
            bullet->modify("pierce");
      }
  }
  

  // determine how fast goombas can spawn
  if (goombaSpawnTimer < 50) {  // TODO: can also use asSeconds() instead
     goombaSpawnTimer++;
  }

  // spawn goombas that move down
  if (goombaSpawnTimer >= 50) {
    goombas.push_back(Goomba(this->gameData, "down"));
    goombaSpawnTimer = 0;
  }

  // move goombas down
  for (size_t i = 0; i < goombas.size(); i++) {
    goombas[i].moveDown();
    goombas[i].update(dt);

    // delete goombas if they go off the screen
    if (goombas[i].getPosition().y > this->gameData->window.getSize().y - 100) { // TODO: get rid of the '-100', only there for testing
      goombas.erase(goombas.begin() + i);
    }
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
        // TODO: erase bullet
        goombas.erase(goombas.begin() + i);
        bullet->set(-10000000,-100000000);
        break;
      }
    }
  }
  
  
  //playercollision
    if (!goombas.empty()) {
    for (size_t i = 0; i < goombas.size(); i++) {
      if (spaceship->getPosition().intersects(goombas[i].getShape().getGlobalBounds())) {
        // TODO: erase bullet
        goombas.erase(goombas.begin() + i);
        break;
      }
    }
  }

}


void GameState2::draw(float dt) {
	this->gameData->window.clear(sf::Color::White);
  this->gameData->window.draw(backgroundSprite);

  spaceship->draw();
  bullet->draw();

  for (size_t i = 0; i < goombas.size(); i++) {
    goombas[i].draw();
  }


  this->gameData->window.draw(defaultWeapon);
  this->gameData->window.draw(secondaryWeapon);
  this->gameData->window.draw(heart1);
  this->gameData->window.draw(heart2);
  this->gameData->window.draw(heart3);
  this->gameData->window.draw(powerup);
  this->gameData->window.draw(powerup);

	this->gameData->window.display();
}
