/**
  * Filename: GameApp.hpp
  *
  * Game Application header file.
**/

#ifndef GAMEAPP_HPP
#define GAMEAPP_HPP

#include <SFML/Graphics.hpp>

using namespace sf;


class GameApp {

  public:
    GameApp();
    virtual ~GameApp();

    void init();
    void mainLoop();

  private:
    RenderWindow window;

};


#endif
