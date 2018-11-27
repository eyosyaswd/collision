/**
  * Filename: main.cpp
  *
  * This is the main file that starts the game and calls on the initialize
  *
**/

#include "GameApp.hpp"


int main(int argc, char** argv) {
  GameApp game;
  game.init();
  game.mainLoop();

  return EXIT_SUCCESS;
}
