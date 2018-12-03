/**
  * Filename: Goomba.hpp
  *
  * This is the most basic enemy. Goombas will come in groups of rows. They will
  * start from one end of the screen and move across.
**/

#ifndef GOOMBA_HPP
#define GOOMBA_HPP


#include "GameApp.hpp"
#include "Entity.hpp"


class Goomba : public Entity{

  public:
    Goomba(GameDataRef data);
    ~Goomba();

    void draw();

    void animate(float secs);

    sf::RectangleShape getShape();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void update(float secs);
    void setPosition(sf::Vector2f);
    sf::Vector2f getPosition();
    sf::Vector2f getSize();

  private:
    sf::RectangleShape goomba;
    float velocity = 3.0;
    GameDataRef gameData;
    sf::Vector2f position;

    sf::Clock clock;

};


#endif //GOOMBA_HPP
