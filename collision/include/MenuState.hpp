#ifndef GAME_STATE_START_HPP
#define GAME_STATE_START_HPP
#include <SFML/Graphics.hpp>
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3

#include "gameState.hpp"
#include "PlayState.hpp"

class MenuState : public GameState
{
public:

    MenuState(GameApp* game);


    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

    void moveUp();
  	void moveDown();
  	int getPressedItem() { return selectedItemIndex; }

private:

    sf::View view;

    
    void loadgame();
    int selectedItemIndex;
  	sf::Font font;
  	sf::Text menu[MAX_NUMBER_OF_ITEMS];
    float width = 800.f;
    float height = 600.f;
};
#endif /* GAME_STATE_START_HPP*/
