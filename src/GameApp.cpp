/**
  * Filename: GameApp.cpp
**/

#include <iostream>

#include "Global.hpp"
#include "GameApp.hpp"
#include "SplashState.hpp"
#include "GameState.hpp"


GameApp::GameApp() {}


GameApp::~GameApp() {}


void GameApp::init() {
  this->gameData->window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BITS_PER_PIXEL), GAME_TITLE, sf::Style::Titlebar | sf::Style::Close);
  this->gameData->window.setMouseCursorVisible(false);

  this->gameData->stateManager.pushState(StateRef(new SplashState(this->gameData)));
}


void GameApp::mainLoop() {
  float newTime, frameTime, interpolation;
  float currentTime = this->clock.getElapsedTime().asSeconds();
  float accumulator = 0.0f;

  while(this->gameData->window.isOpen()) {  // TODO: Needs to be simplified
    this->gameData->stateManager.updateStates();

    newTime = this->clock.getElapsedTime().asSeconds();
    frameTime = newTime - currentTime;

    if (frameTime > 0.25f) {
      frameTime = 0.25f;
    }
    currentTime = newTime;
    accumulator += frameTime;

    while (accumulator >= dt) {
      if (this->gameData->window.hasFocus()) {
        this->gameData->stateManager.getActiveState()->handleEvents();
      }
      this->gameData->stateManager.getActiveState()->update(dt);

      accumulator -= dt;
    }

    interpolation = accumulator / dt;
    this->gameData->stateManager.getActiveState()->draw(interpolation);
  }
}
