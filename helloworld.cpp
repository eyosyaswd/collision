#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include "Player.hpp"
#include <SFML/Audio.hpp>


#include <cstring>
#include <iostream>
using namespace std;


int main(int argc, char** argv)
{
  // create main window
  float windowWidth = 800.f;
  float windowHeight = 600.f;
  sf::RenderWindow App(sf::VideoMode(windowWidth, windowHeight,32), "COLLISION", sf::Style::Titlebar | sf::Style::Close);
  
  //instantiate bullet shape
  sf::CircleShape bullet(7);
  bullet.setPosition(-100,-100);
  
  //create toggle string/indicator for mouse wheel selection
  std::string togglestring = "primary";
  sf::CircleShape weapontoggle(20);
  weapontoggle.setPosition(30,500);
  
  //resets bullet trajecory
  float newshot = 0.0f;

  //set up default laser sound
  sf::SoundBuffer defaultgun;
  if(!defaultgun.loadFromFile("../resources/laser.wav"))
  {
      return EXIT_FAILURE;
  }
  
  sf::Sound defaultgunsound;
  defaultgunsound.setBuffer(defaultgun);
  //
  
  

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
        
        //manages 360 degree shooting
        if (Event.type == sf::Event::MouseButtonPressed)
        {
          
        bullet.setPosition(spaceship.position.x,spaceship.position.y);
      
        //atan2 vector formula found using tutorials
        sf::Vector2f mousePosition = App.mapPixelToCoords(sf::Mouse::getPosition(App));
               float cleanshot = atan2(sf::Mouse::getPosition(App).y - bullet.getPosition().y, 
                                 sf::Mouse::getPosition(App).x - bullet.getPosition().x);
         newshot = cleanshot; 
        //play sound
         
        //plays gun sound upon shooting a bullet 
        defaultgunsound.play();
        
        }
        
        
        //Mouse wheel toggles between weapons, for now just switches the bullet size/color
        if(Event.type == sf::Event::MouseWheelMoved){
                if (togglestring == "primary"){
                        weapontoggle.setFillColor(sf::Color::Yellow);
                        togglestring = "secondary";
                        bullet.setRadius(20);
                        bullet.setFillColor(sf::Color::Yellow);
                }
                    
                else{
                    togglestring = "primary";
                    weapontoggle.setFillColor(sf::Color::White);
                    bullet.setRadius(7);
                    bullet.setFillColor(sf::Color::White);
                }
            
        }
      
      
      
      
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
        

        
        
        
        
     
        
    //moves the bullet using accepted trajectory correction (used online tutorials)    
    bullet.move(cos(newshot) * 0.5f, 0);
    bullet.move(0, sin(newshot) * 0.5f);

    spaceship.update();

    clock.restart();
    // clear screen and fill with blue
    App.clear(sf::Color::Blue);

    //displays the game
   
    App.draw(background);
    App.draw(spaceship.getShape());
    App.draw(bullet);
    App.draw(weapontoggle);
    App.display();
  }

  // Done.
  return 0;
}
