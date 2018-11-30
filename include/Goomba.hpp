#ifndef GOOMBA_HPP
#define GOOMBA_HPP


#include "Entity.hpp"
#include "GameApp.hpp"

class Goomba : public Entity{
public:
    Goomba(GameDataRef data);
    ~Goomba();

    void draw();

    void animate(float secs);

    //Player(float startX, float startY);
    //sf::FloatRect getPosition();
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
