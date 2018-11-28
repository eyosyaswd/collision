/**
  * Filename: ResourceManager.hpp
  *
  * Manges the resources/assets of the game.
**/

#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class ResourceManager {

  public:
    ResourceManager();
    ~ResourceManager();

    /**
      * Loads a texture.
    **/
    void loadTexture(std::string textureName, std::string fileName);

    /**
      * Returns a reference to a texture.
    **/
    sf::Texture &getTexture(std::string textureName);


    /**
      * Loads a font.
    **/
    void loadFont(std::string fontName, std::string fileName);

    /**
      * Returns a reference to a font.
    **/
    sf::Font &getFont(std::string fontName);

    /**
      * Loads music.
    **/
    void loadMusic(std::string fileName);


private:
    std::map<std::string, sf::Texture> texturesMap;  // map of textures
    std::map<std::string, sf::Font> fontsMap;  //map of fonts
    std::map<char,int> mymap;

};


#endif
