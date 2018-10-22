#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include "Player.hpp"


#include <cstring>

int main(int argc, char** argv)
{
  // create main window
  float windowWidth = 800.f;
  float windowHeight = 600.f;
  sf::RenderWindow App(sf::VideoMode(windowWidth, windowHeight,32), "COLLISION", sf::Style::Titlebar | sf::Style::Close);

  //create background image
  sf::Texture backdrop;
  if (!backdrop.loadFromFile("../resources/pixelSpace.png"))
  {
    return EXIT_FAILURE;
  }
  sf::Sprite background(backdrop);
/* Text. Font set up
sf::Font font;
if(!font.loadFromFile("../resources/Harry.ttf"))
{
  return EXIT_FAILURE;
}

// create intro text
sf::Text text;
text.setFont(font);
text.setCharacterSize(40);
text.setPosition(150.f, 150.f);
text.setFillColor(sf::Color::White);
text.setString("Harry Ponger \n Press 'spacebar' to play \n Use arrows");

sf::Text comp;
comp.setFont(font);
comp.setCharacterSize(25);
comp.setPosition(220.f, 30.f);
comp.setFillColor(sf::Color::White);
comp.setString("0");
*/

  //initate score to 0
  float compScore = 0;
  float playerScore = 0;

  //Time
  sf::Clock clock;
  sf::Clock compClock;
  const sf::Time compTime  = sf::seconds(0.1f);

  //Create spaceship
  Player spaceship(windowWidth/2, windowHeight/2);

  // in play boolean
  bool inPlay = false;

  // start main loop
  while(App.isOpen())
  {
    // process events
    sf::Event Event;
    while(App.pollEvent(Event))
    {
      // Exit
      if(Event.type == sf::Event::Closed)
        App.close();
      }
        float secs = clock.restart().asSeconds();

          //player spaceship keyboard commands.
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        { spaceship.moveDown(secs);}
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)|| sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        { spaceship.moveUp(secs);}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        { spaceship.moveLeft(secs);}
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        { spaceship.moveRight(secs);}
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        { App.close();}


    spaceship.update();

    clock.restart();
    // clear screen and fill with blue
    App.clear(sf::Color::Blue);

    //displays the game
    App.draw(background);
    App.draw(spaceship.getShape());

    App.display();
  }

  // Done.
  return 0;
}
