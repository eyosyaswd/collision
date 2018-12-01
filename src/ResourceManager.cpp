/**
  * Filename: ResourceManager.cpp
**/

#include <iostream>
<<<<<<< HEAD
#include "ResourceManager.hpp"
=======
#include <SFML/Audio.hpp>
>>>>>>> b632f3edbba2380383382c6b35e4ddbc7ea40726

#include "ResourceManager.hpp"


ResourceManager::ResourceManager() {}


ResourceManager::~ResourceManager() {}


void ResourceManager::loadTexture(std::string textureName, std::string fileName) {
  sf::Texture texture;

  if (!texture.loadFromFile(fileName)) {
    std::cout << "Error occued while loading texture: " << fileName << std::endl;
  } else {
    this->texturesMap[textureName] = texture; // TODO: Keeps causing seg fault
  }
}


sf::Texture &ResourceManager::getTexture(std::string textureName) {
  return this->texturesMap.at(textureName);
}

void ResourceManager::loadFont(std::string fontName, std::string fileName) {
  sf::Font font;
  if (!font.loadFromFile(fileName)) {
    std::cout << "Error occured while loading font: " << fileName << std::endl;
  } else {
    this->fontsMap[fontName] = font;
  }
}


sf::Font &ResourceManager::getFont(std::string fontName) {
  return this->fontsMap.at(fontName);
}
<<<<<<< HEAD
=======

//initiates the collision theme when switched to th the menu screen state

void ResourceManager::loadMusic(std::string fileName) {
  sf::Music music;
  if (!music.openFromFile(fileName))
    std::cout << "Error occured while loading music: " << fileName << std::endl;
  else {

    std::cout << "Playing: " << fileName << std::endl;
    music.setLoop(true);
    music.play();
  }
}
>>>>>>> b632f3edbba2380383382c6b35e4ddbc7ea40726
