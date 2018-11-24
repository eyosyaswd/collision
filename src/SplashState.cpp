/**
  * Filename: SplashState.cpp
**/

// #include <sstream>
#include <iostream>
#include "SplashState.hpp"
#include "Global.hpp"


SplashState::SplashState(GameDataRef gameDate) {
  this->gameData = gameData;
}


void SplashState::init() {
  this->gameData->resourceManager.loadTexture("SplashState Background", SPLASH_STATE_BACKGROUND_FILEPATH);
  backgroundSprite.setTexture(this->gameData->resourceManager.getTexture("SplashState Background"));
}


void SplashState::handleEvents() {
  sf::Event event;

  while(this->gameData->window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      this->gameData->window.close();
    }
  }
}


void SplashState::update(float dt) {
  if (clock.getElapsedTime().asSeconds() > SPLASH_STATE_TIME_LENGTH) {
    std::cout << "Go to Main Menu" << std::endl;
  }
}


void SplashState::draw(float dt) {
  gameData->window.clear();
  gameData->window.draw(backgroundSprite);
  gameData->window.display();
}
