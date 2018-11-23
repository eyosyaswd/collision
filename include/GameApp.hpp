/**
  * Filename: GameApp.hpp
  *
  * Game Application header file.
**/
//#pragma once

#ifndef GAMEAPP_HPP
#define GAMEAPP_HPP

#include <SFML/Graphics.hpp>

using namespace sf;


class GameApp {

  public:
    GameApp();
    ~GameApp();

    void init();
    void mainLoop();

  private:
    RenderWindow window;

};


#endif
