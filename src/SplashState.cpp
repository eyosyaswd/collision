/**
  * Filename: SplashState.cpp
**/

#include <iostream>

#include "Global.hpp"
#include "SplashState.hpp"
#include "MenuState.hpp"
#include "WinState.hpp"
#include "LoseState.hpp"
#include "StoryState.hpp"

SplashState::SplashState(GameDataRef data): gameData(data) {}


void SplashState::init() {
  this->gameData->resourceManager.loadTexture("SplashState Background", SPLASH_STATE_BACKGROUND_FILEPATH);
  backgroundSprite.setTexture(this->gameData->resourceManager.getTexture("SplashState Background"));

    if (!splash_Theme.loadFromFile("../res/sounds/splash.wav"))
        std::cout << "Error occured while loading music " << std::endl;
    else {
        splash.setBuffer(splash_Theme);
        splash.play();
    }
}


void SplashState::handleEvents() {
  sf::Event event;

  while(this->gameData->window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      this->gameData->window.close();
    }
  }
}


void SplashState::update(float dt)
{
  if (this->clock.getElapsedTime().asSeconds() > SPLASH_STATE_TIME_LENGTH)
  {
    // goes to main menu after some seconds
    this -> gameData->stateManager.pushState(StateRef(new MenuState(gameData)), true);
  }
}


void SplashState::draw(float dt) {
  gameData->window.clear();
  gameData->window.draw(backgroundSprite);
  gameData->window.display();
}
