/**
  * Filename: SplashState.hpp
  *
  * This is the splash screen that will be displayed for 3 seconds when the
  * game is initially launched.
**/

#ifndef SPLASHSTATE_HPP
#define SPLASHSTATE_HPP


#include <SFML/Graphics.hpp>

#include "GameApp.hpp"
#include "State.hpp"


class SplashState : public State {

  public:
    SplashState(GameDataRef data);
    void init();
    void handleEvents();
    void update(float dt);
    void draw(float dt);

  private:
    GameDataRef gameData;

    sf::Clock clock;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    sf::SoundBuffer splash_Theme;
    sf::Sound splash;

};


#endif
