#include "GameApp.hpp"
#include "SFML/Graphics.hpp"
#include "gameState.hpp"


// Constructor
GameApp::GameApp() {
  window.create(sf::VideoMode(windowWidth, windowHeight, 32), "COLLISION", sf::Style::Titlebar | sf::Style::Close);
}


// Destructor
GameApp::~GameApp() {
  while (!states.empty()){
    popState();
  }
}

GameState* GameApp::CurrentState()
{
  if(states.empty())
  {
    return nullptr;
  }
  else
  {
    return states.back();
  }
}
// Initiallizing function:

void GameApp::pushState(GameState* state) {
  states.push_back(state);
}

void GameApp::popState()
{
  states.back();
  delete states.back();
  states.pop_back();
}


void GameApp::gameLoop() {
  sf::Clock clock;

  while(window.isOpen()) {
    sf::Time elapsed = clock.restart();
    float dt = elapsed.asSeconds();

    if(CurrentState() == nullptr){
      continue;
    }

    CurrentState()->handleInput();

    CurrentState()->update(dt);


    window.clear();
    CurrentState()->draw(dt);
    window.display();

  }

}
