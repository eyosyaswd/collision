/**
  * Filename: State.hpp
  *
  * Base state (a.k.a. screen) class that other states will inherit from.
**/

#ifndef STATE_HPP
#define STATE_HPP


class State {

  public:
    /**
      * Initiallizes the state.
    **/
    virtual void init() = 0;

    /**
      * Handles inputs (events).
    **/
    virtual void handleEvents() = 0;

    /**
      * Updates the game.
    **/
    virtual void update(float dt) = 0;

    /**
      * Draws the game onto the screen.
    **/
    virtual void draw(float dt) = 0;


    /**
      * Pauses the state.
    **/
    virtual void pause() {}

    /**
      * Resumes the state.
    **/
    virtual void resume() {}

  private:

};


#endif
