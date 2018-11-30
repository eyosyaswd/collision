/*


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include "Player.hpp"
#include "Enemy.hpp"
#include <SFML/Audio.hpp>


#include <cstring>
#include <iostream>
using namespace std;


int main(int argc, char** argv)
{
  // create main window
  float windowWidth = 800.f;
  float windowHeight = 600.f;
  bool shieldfollow = false;
  bool cangethit = true;

  sf::RenderWindow App(sf::VideoMode(windowWidth, windowHeight,32), "COLLISION", sf::Style::Titlebar | sf::Style::Close);

  //instantiate bullet shape
  sf::CircleShape bullet(7);
  bullet.setPosition(-100,-100);
  
  //Back Bullet
  sf::CircleShape bullet2(7);
  bullet2.setPosition(-100,-100);
  
    
  //PowerUp Timer
  sf::Time powertime;
  sf::Time  elapsedpowertime;
  sf::Clock powerclock;


  //initiates the collision theme when game starts
  sf::Music music;
  if (!music.openFromFile("../res/sounds/confrontation.wav"))
      return -1; // error

      music.setLoop(true);
      music.play();
  
  sf::CircleShape shieldpower(20);
  shieldpower.setPosition(-1100,-1100);
  
  sf::CircleShape heartpower(20);
  heartpower.setPosition(-1100,-1100);
  heartpower.setFillColor(sf::Color::Red);
  
  sf::CircleShape bigpower(20);
  bigpower.setPosition(-1100,-1100);
  bigpower.setFillColor(sf::Color::Yellow);
  bool bigstatus = false;
  
  sf::CircleShape piercepower(20);
  piercepower.setPosition(-1100,-1100);
  piercepower.setFillColor(sf::Color::Green);
  
  sf::CircleShape backpower(20);
  backpower.setPosition(-1100,-1100);
  backpower.setFillColor(sf::Color::Blue);
  int doublecount = 0;
  bool doublestatus = false;
  bool toggledouble = false;
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

  //make hearts, temporary

  sf::Texture heart;
  if(!heart.loadFromFile("../res/images/heart.png"))
  {
    return EXIT_FAILURE;
  }
 
 
  sf::Sprite heart1sprite;
  heart1sprite.setTexture(heart);
  heart1sprite.setPosition(20,50);
  heart1sprite.setScale(sf::Vector2f(0.1f, 0.1f));

  sf::Sprite heart2sprite;
  heart2sprite.setTexture(heart);
  heart2sprite.setPosition(80,50);
  heart2sprite.setScale(sf::Vector2f(0.1f, 0.1f));

  sf::Sprite heart3sprite;
  heart3sprite.setTexture(heart);
  heart3sprite.setPosition(140,50);
  heart3sprite.setScale(sf::Vector2f(0.1f, 0.1f));
  
//test shield following
  sf::CircleShape shield(50);
  shield.setPosition(-400,-400);
  
  //collision immunity
  sf::Time immunity = sf::seconds(5.0f);

  
  
  
  
  








  //create background image
  sf::Texture backdrop;
  if (!backdrop.loadFromFile("../res/images/pixelSpace.png"))
  {
    return EXIT_FAILURE;
  }
  sf::Sprite background(backdrop);





  //Time
  sf::Clock clock;
  sf::Clock compClock;
  const sf::Time compTime  = sf::seconds(0.1f);

  //Create spaceship
  Player spaceship(windowWidth/2, windowHeight/2);

 


  // Create enemy spaceship
  Enemy enemy(1.0, 0.5);


  // in play boolean
  bool inPlay = false;

  // start main loop
  while(App.isOpen())
  {
    
      
    if (shieldpower.getGlobalBounds().intersects(spaceship.getPosition())){
                shield.setPosition(spaceship.position.x - 35,spaceship.position.y - 25);
                shield.setFillColor(sf::Color(255,255,255,128));
                shieldpower.setPosition(-500,-500);
                shieldfollow = true;
                
    }
    
    if (shieldfollow == true){
        shield.setPosition(spaceship.position.x - 35,spaceship.position.y - 25);
    }
    

    

    
    if ((enemy.getPosition().intersects(spaceship.getPosition()) ) == false){
                cangethit = true;
    }
    
    if(backpower.getGlobalBounds().intersects(spaceship.getPosition())){
            doublestatus = true;
            doublecount = 20;
    }

    
    
    
    
    

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

        if(bullet.getPosition().x < 0 || bullet.getPosition().x > 800 || bullet.getPosition().y < 0 || bullet.getPosition().y > 600 && (bullet2.getPosition().x < 0 || bullet2.getPosition().x > 800 || bullet2.getPosition().y < 0 || bullet2.getPosition().y > 600)){
        bullet.setPosition(spaceship.position.x,spaceship.position.y);
        
        if(doublestatus == true && doublecount > 0 && togglestring == "secondary"){
            bullet2.setPosition(spaceship.position.x-10,spaceship.position.y-10);
            doublecount = doublecount - 1;
        }

        //atan2 vector formula found using tutorials
        sf::Vector2f mousePosition = App.mapPixelToCoords(sf::Mouse::getPosition(App));
               float cleanshot = atan2(sf::Mouse::getPosition(App).y - bullet.getPosition().y,
                                 sf::Mouse::getPosition(App).x - bullet.getPosition().x);
         newshot = cleanshot;
        //play sound

        //plays gun sound upon shooting a bullet
        defaultgunsound.play();
        }

        }


        //Mouse wheel toggles between weapons, for now just switches the bullet size/color
        if(Event.type == sf::Event::MouseWheelMoved){
                if (togglestring == "primary"){
                        
                        if(bigstatus == true){
                        togglestring = "secondary";
                        weapontoggle.setFillColor(sf::Color::Yellow);
                        bullet.setRadius(20);
                        bullet.setFillColor(sf::Color::Yellow);
                        }
                        if(doublestatus == true){
                        togglestring = "secondary";
                        weapontoggle.setFillColor(sf::Color::Blue);
                        bullet.setFillColor(sf::Color::Blue);
                        toggledouble = true;
                        }
                            
                    }

                else{
                    togglestring = "primary";
                    weapontoggle.setFillColor(sf::Color::White);
                    bullet.setRadius(7);
                    bullet.setFillColor(sf::Color::White);
                }

        }
        
        if (enemy.getPosition().intersects(spaceship.getPosition()) && shieldfollow == true && cangethit == true){
                    shield.setPosition(-480,-480);
                    shieldfollow = false;
                    cangethit = false;
 
        }
        
        if (enemy.getPosition().intersects(spaceship.getPosition()) && shieldfollow == false && cangethit == true){
                    if(heart3sprite.getPosition().x > 0){
                        heart3sprite.setPosition(-400,-400);
                    }
                    
                    else if(heart3sprite.getPosition().x < 0 && heart2sprite.getPosition().x > 0){
                            heart2sprite.setPosition(-800,-800);
                    }
                    
                    else{
                            App.close();
                    }
                    cangethit = false;
        }
        
        if (heartpower.getGlobalBounds().intersects(spaceship.getPosition())){
            if(heart2sprite.getPosition().x < 0){
                    heart2sprite.setPosition(80,50);
                    heartpower.setPosition(-300,-300);
            }
            else{
                    heart3sprite.setPosition(140,50);
                    heartpower.setPosition(-300,-300);
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
        
        elapsedpowertime += powerclock.getElapsedTime();
        powertime = powerclock.getElapsedTime();
        powerclock.restart();
        
        if (elapsedpowertime.asSeconds() > 5)
        {
          
        //clears screen of any remaining powerups    
        shieldpower.setPosition(-1000,-1000);
        heartpower.setPosition(-1100,-1100);
        bigpower.setPosition(-1100,-1100);
        piercepower.setPosition(-1100,-1100);
        backpower.setPosition(-1100,-1100);
            
        //randomly selects which powerup will be displayed, and where it will be placed    
        int randompower = rand() % 5;
        int randompowerlocation_x = rand() % 700;
        int randompower_location_y = rand() % 500;
        
        if(randompower == 4){
                shieldpower.setPosition(randompowerlocation_x,randompower_location_y);
        }
        
        if(randompower == 0){
                heartpower.setPosition(randompowerlocation_x,randompower_location_y);
        }
        
        if(randompower == 2){
                piercepower.setPosition(randompowerlocation_x,randompower_location_y);
        }
        
        if(randompower == 3){
                bigpower.setPosition(randompowerlocation_x,randompower_location_y);
        }
        
        if(randompower == 1){
                backpower.setPosition(randompowerlocation_x,randompower_location_y);
        }
        
        elapsedpowertime = sf::milliseconds(0);
        }
        





    //moves the bullet using accepted trajectory correction (used online tutorials)
    if(doublecount > 0 && doublestatus == true && togglestring == "secondary"){
    
        bullet2.move(-cos(newshot) * 0.5f, 0);
        bullet2.move(0, -sin(newshot) * 0.5f);
        bullet2.setFillColor(sf::Color::Blue);

    }
    
        if(doublecount <= 0){ 
        bullet2.setPosition(-3000,-3000);
        bullet.setFillColor(sf::Color::White);
        weapontoggle.setFillColor(sf::Color::White);
        togglestring  = "primary";
        }
    

    
    bullet.move(cos(newshot) * 0.5f, 0);
    bullet.move(0, sin(newshot) * 0.5f);
    

        


    spaceship.update();

    clock.restart();
    // clear screen and fill with blue
    App.clear(sf::Color::Blue);

    //displays the game

    App.draw(background);
    App.draw(spaceship.getShape());
    App.draw(enemy.getShape());
    App.draw(bullet);
    App.draw(bullet2);
    App.draw(weapontoggle);
    App.draw(heart1sprite);
    App.draw(heart2sprite);
    App.draw(heart3sprite);
    App.draw(shield);
    App.draw(shieldpower);
    App.draw(heartpower);
    
    App.draw(bigpower);
    App.draw(backpower);
    App.draw(piercepower);
    


    App.display();
  }

  // Done.
  return 0;
}

*/
