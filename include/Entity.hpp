/**
  * Filename: Entity.hpp
  *
  * This is the base entity class that other entities will inherit from.
**/

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>


class Entity {

  public:
    virtual void draw() = 0;

    virtual void moveUp() = 0;
    virtual void moveDown() = 0;
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;

};


#endif //ENTITY_HPP
