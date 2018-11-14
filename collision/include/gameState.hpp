#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "GameApp.hpp"

class GameState
{
  public:
    GameApp* game;

    virtual void draw(const float dt) = 0;
    virtual void update(const float dt) = 0;
    virtual void handleInput() = 0;
};
#endif /* GAME_STATE_HPP */
