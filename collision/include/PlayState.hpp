#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include <SFML/Graphics.hpp>

#include "gameState.hpp"


class PlayState : public GameState
{
public:

    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

    PlayState(GameApp* game);



private:
    void PauseGame();
    sf::View gameView;
    float width = 800.f;
    float height = 600.f;


};

#endif /* PLAYSTATE_HPP */
