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
    void set();
    sf::Vector2f getPosition();


  private:
    sf::RectangleShape goomba;
    float velocity = 2.0;
    GameDataRef gameData;
    sf::Vector2f position;

    sf::Clock clock;

};


#endif //GOOMBA_HPP
