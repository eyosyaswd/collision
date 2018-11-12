/**
  * Filename: GameApp.hpp
  *
  * Game Application header file.
**/

#ifndef GAMEAPP_HPP
#define GAMEAPP_HPP

#include <SFML/Graphics.hpp>


class GameApp {

  public:
    GameApp();
    ~GameApp();

    void init();
    void mainLoop();

  private:
    float windowWidth = 800.f;
    float windowHeight = 600.f;
    sf::RenderWindow *window;

};


#endif
