/**
  * Filename: SplashState.hpp
  *
  * Splash screen that will be displayed for 3 seconds when the game is
  * initially launched.
**/

#ifndef SPLASHSTATE_HPP
#define SPLASHSTATE_HPP

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "GameApp.hpp"

class SplashState : public State {

  public:
    /**
      * Constructor
    **/
    SplashState(GameDataRef data);

    /**
      * Initiallizes the state.
    **/
    void init();

    /**
      * Handles inputs (events).
    **/
    void handleEvents();

    /**
      * Updates the game.
    **/
    void update(float dt);

    /**
      * Draws the game onto the screen.
    **/
    void draw(float dt);

  private:
    GameDataRef gameData;
    sf::Clock clock;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

};


#endif
