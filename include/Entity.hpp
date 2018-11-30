#ifndef ENTITY_HPP
#define ENTITY_HPP


#include <SFML/Graphics.hpp>

class Entity
{
public:
    virtual void draw() = 0;

    virtual void animate(float secs) = 0;

    //Player(float startX, float startY);
    //sf::FloatRect getPosition();
    virtual sf::RectangleShape getShape() = 0;
    virtual void moveUp() = 0;
    virtual void moveDown() = 0;
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
    virtual void update(float secs) = 0;
    virtual void set() = 0;
    virtual sf::Vector2f getPosition() = 0;

};

#endif //ENTITY_HPP
