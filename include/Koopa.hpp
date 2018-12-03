/**
  * Filename: Koopa.hpp
  *
  * This is the second level of enemies. Koopas will come in from the sides of the screen.
  * They will start from one end of the screen and bounce from border to border.
**/

#ifndef KOOPA_HPP
#define KOOPA_HPP


#include "GameApp.hpp"
#include "Entity.hpp"


class Koopa : public Entity{

public:
    Koopa(GameDataRef data);

    Koopa(GameDataRef data, std::string direction);
    ~Koopa();

    void draw();

    void animate(float secs);

    sf::Sprite getShape();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void update(float secs);
    void setPosition(sf::Vector2f);
    sf::Vector2f getPosition();
    sf::Vector2f getSize();

private:
    sf::Sprite koopa;
    sf::Texture texture;
    float velocity = 6;
    GameDataRef gameData;
    sf::Vector2f position;

    sf::Clock clock;

};


#endif //KOOPA_HPP
