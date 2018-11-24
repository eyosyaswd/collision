/**
  * Filename: GameApp.hpp
  *
  * Game Application.
  * This class initiallizes the game and starts the main loop.
**/
//#pragma once

#ifndef GAMEAPP_HPP
#define GAMEAPP_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include "StateManager.hpp"
#include "ResourceManager.hpp"
//#include "GameLogic.hpp"


/**
  * Game Data struct that will contain the main data to be shared throughout all classes.
**/
struct GameData {
  sf::RenderWindow window;
  StateManager stateManager;
  ResourceManager resourceManager;
  // GameLogic gameLogic;
};

typedef std::shared_ptr<GameData> GameDataRef; // used to access contents of GameData


class GameApp {

  public:
    /**
      * Constructor and Destructor
    **/
    GameApp();
    ~GameApp();

    /**
      * Initiallizes the different managers, game logic, states, etc.
      * Better to have an init() instead of initiallizing in the Constructor
      *   because the Constructor cannot fail!
    **/
    void init();

    /**
      * Contains the main while loop of the game.
    **/
    void mainLoop();

  private:
    const float dt = 1.0f / 60.0f;
    sf::Clock clock;

    GameDataRef gameData = std::make_shared<GameData>();

};


#endif
