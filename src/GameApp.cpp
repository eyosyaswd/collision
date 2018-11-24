/**
  * Filename: GameApp.cpp
**/

#include "GameApp.hpp"
#include "Global.hpp"
#include "SplashState.hpp"
#include <iostream>


GameApp::GameApp() {
  gameData->window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BITS_PER_PIXEL), GAME_TITLE, sf::Style::Titlebar | sf::Style::Close);
  gameData->stateManager.pushState(StateRef(new SplashState(this->gameData)));
}


GameApp::~GameApp() {}


void GameApp::init() {

}


void GameApp::mainLoop() {
  float newTime, frameTime, interpolation;
  float currentTime = this->clock.getElapsedTime().asSeconds();
  float accumulator = 0.0f;

  while(this->gameData->window.isOpen()) {
    // this->gameData->stateManager.updateStates();
    //
    // newTime = this->clock.getElapsedTime().asSeconds();
    // frameTime = newTime - currentTime;
    //
    // if (frameTime > 0.25f) {
    //   frameTime = 0.25f;
    // }
    // currentTime = newTime;
    // accumulator += frameTime;
    //
    // while (accumulator >= dt) {
    //   this->gameData->stateManager.getActiveState()->handleEvents();
    //   this->gameData->stateManager.getActiveState()->update(dt);
    //
    //   accumulator -= dt;
    // }
    //
    // interpolation = accumulator / dt;
    // this->gameData->stateManager.getActiveState()->draw(interpolation);

    sf::Event event;

    while(this->gameData->window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        this->gameData->window.close();
    }

    this->gameData->window.clear(sf::Color::Blue);
    this->gameData->window.display();

  }

}
