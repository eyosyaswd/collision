#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Menu.hpp"
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
  if(!defaultgun.loadFromFile("../res/sounds/laser.wav"))
  {
      return EXIT_FAILURE;
  }

  sf::Sound defaultgunsound;
  defaultgunsound.setBuffer(defaultgun);
  //



  //create background image
  sf::Texture backdrop;
  if (!backdrop.loadFromFile("../res/images/pixelSpace.png"))
  {
    return EXIT_FAILURE;
  }
  sf::Sprite background(backdrop);
/* Text. Font set up
sf::Font font;
if(!font.loadFromFile("../res/fonts/Harry.ttf"))
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

  //Menu
  Menu menu(App.getSize().x, App.getSize().y);

  //Create spaceship
  Player spaceship(windowWidth/2, windowHeight/2);

  // Create enemy spaceship
  Enemy enemy(1.0, 0.5);

  // in play boolean
  bool inPlay = false;

  // start main loop
  while(App.isOpen())
  {
    // process events
    sf::Event Event;
    while(App.pollEvent(Event))
    {
      switch (Event.type)
			{
			case sf::Event::KeyReleased:
        switch (Event.key.code)
				{
				case sf::Keyboard::Up:
					menu.moveUp();
					break;

				case sf::Keyboard::Down:
					menu.moveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.getPressedItem())
					{
					case 0:
            inPlay = true;
            clock.restart();
						break;
					case 1:
						std::cout << "Option button has been pressed" << std::endl;
						break;
					case 2:
						App.close();
						break;
					}

					break;
				}

				break;
			case sf::Event::Closed:
				App.close();
        break;
      }





if (inPlay)
{
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


        //enemy starts moving randomly
        enemy.move(secs);






    //moves the bullet using accepted trajectory correction (used online tutorials)
    bullet.move(cos(newshot) * 0.5f, 0);
    bullet.move(0, sin(newshot) * 0.5f);
}

    spaceship.update();

    clock.restart();
    // clear screen and fill with blue
    App.clear(sf::Color::Blue);

    //displays the game
    if(inPlay){
    App.draw(background);
    App.draw(spaceship.getShape());
    App.draw(enemy.getShape());
    App.draw(bullet);
    App.draw(weapontoggle);

    }

    if (!inPlay){
    menu.draw(App);
    }

    App.display();

  }

  // Done.
  return 0;
}
