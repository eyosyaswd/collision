/**
  * Filename: main.cpp
  *
  * This is the main file that starts the game and calls on the initialize
  *
**/

#include <SFML/Graphics.hpp>
#include "GameApp.hpp"
#include "MenuState.hpp"

int main(int argc, char** argv) {
  GameApp game;

  game.pushState(new MenuState(&game));

  game.gameLoop();

  return 0;
}
