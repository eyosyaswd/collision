/**
  * Filename: Koopa.hpp
**/

#include "Koopa.hpp"
#include "Global.hpp"


Koopa::Koopa(GameDataRef data) : gameData(data) {

    //TODO: Change filepath to Koopa spaceship color
    this->gameData->resourceManager.loadTexture("koopa", PINK_SHEET_FILEPATH);
    koopa.setTexture(this->gameData->resourceManager.getTexture("koopa"));
    koopa.setTextureRect(sf::IntRect(100,0,50,50));

    position.x = rand() % int(gameData->window.getSize().x - 50);
    position.y = 0.f; // TODO: Randomize the starting positions and movement

    koopa.setPosition(position);
}

Koopa::Koopa(GameDataRef data, std::string direction) : gameData(data) {

    this->gameData->resourceManager.loadTexture("koopa", PINK_SHEET_FILEPATH);
    koopa.setTexture(this->gameData->resourceManager.getTexture("koopa"));

    // TODO: Might have to tweak spawn locations
    if(direction == "down") { ;
        position.x = rand() % int(gameData->window.getSize().x - 50);
        position.y = 0.f;
    }

    if(direction == "up") {
        position.x = rand() % int(gameData->window.getSize().x - 50);
        position.y = int(gameData->window.getSize().y - 100);
    }

    if(direction == "right") {
        koopa.setTextureRect(sf::IntRect(50,200,50,50));
        position.x = 0.f;
        position.y = rand() % int(gameData->window.getSize().y - 50); // TODO: Randomize the starting positions and movement
    }

    if(direction == "left") {
        koopa.setTextureRect(sf::IntRect(50,200,50,50));
        position.x = int(gameData->window.getSize().x - 100);
        position.y = rand() % int(gameData->window.getSize().y - 50); // TODO: Randomize the starting positions and movement
    }

    koopa.setPosition(position);
}


Koopa::~Koopa() {}


void Koopa::draw() {
    gameData->window.draw(koopa);
}


void Koopa::animate(float secs) {}


sf::Sprite Koopa::getShape() {
    return koopa;
}


void Koopa::moveUp() {
    position.y -= velocity;
}


void Koopa::moveDown() {
    position.y += velocity;
}


void Koopa::moveLeft() {
    position.x -= velocity;
    koopa.setTextureRect(sf::IntRect(50,250,50,50));
}


void Koopa::moveRight() {
    position.x += velocity;
    koopa.setTextureRect(sf::IntRect(50,200,50,50));
}


void Koopa::setPosition(sf::Vector2f) {
    koopa.setPosition(position);
}


void Koopa::update(float secs) {
    koopa.setPosition(position);
}


sf::Vector2f Koopa::getPosition() {
    return position;
}
