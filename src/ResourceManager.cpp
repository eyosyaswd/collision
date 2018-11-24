/**
  * Filename = ResourceManager.cpp
**/

#include <iostream>
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
    std::cout << "Error occued while loading font: " << fileName << std::endl;
  } else {
    this->fontsMap[fontName] = font;
  }
}


sf::Font &ResourceManager::getFont(std::string fontName) {
  return this->fontsMap.at(fontName);
}
