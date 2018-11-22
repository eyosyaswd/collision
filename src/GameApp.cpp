/**
  * Filename: GameApp.cpp
  *
  * Game Application class.
  * This class initiallizes the game and starts the main loop.
**/

#include "GameApp.hpp"
#include "Global.hpp"

// Constructor
GameApp::GameApp() {
  window = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BITS_PER_PIXEL), GAME_TITLE/*, Style::Titlebar | Style::Close*/);
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
    Event event;

    while(window->pollEvent(event)) {
      if (event.type == Event::Closed)
        window->close();
    }

    // no drawing should happen here but it's okay for now
    window->clear(sf::Color::Blue);
    window->display();

  }

}
