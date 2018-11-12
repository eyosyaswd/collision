/**
  * Filename: GameApp.cpp
  *
  * Game Application class.
**/

#include "GameApp.hpp"


// Constructor
GameApp::GameApp() {
  window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight, 32), "COLLISION", sf::Style::Titlebar | sf::Style::Close);
}


// Destructor
GameApp::~GameApp() {}


// Initiallizing function:
// This is where we want to initiallize deltaTime,
void GameApp::init() {

}


void GameApp::mainLoop() {
  // sf::Clock clock;

  while(window->isOpen()) {
    sf::Event event;

    while(window->pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window->close();
    }

    // no drawing should happen here but it's okay for now
    window->clear(sf::Color::Blue);
    window->display();

  }

}
