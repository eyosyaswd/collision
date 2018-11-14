#ifndef GAMEAPP_HPP
#define GAMEAPP_HPP

#include <vector>
#include <SFML/Graphics.hpp>

class GameState;

class GameApp
{
  public:
    GameApp();
    ~GameApp();

    void pushState(GameState* state);
    void popState();

    GameState* CurrentState();

    void gameLoop();

    sf::RenderWindow window;

  private:
    float windowWidth = 800.f;
    float windowHeight = 600.f;

    std::vector<GameState*> states;

};
#endif /* GAMEAPP_HPP*/
