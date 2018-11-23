/**
  * Filename: State.hpp
  *
  * Base state (a.k.a. screen) class that other states will inherit from.
**/

#ifndef STATE_HPP
#define STATE_HPP


class State {

  public:
    virtual void init();

    virtual void handleEvents() = 0;
    virtual void update() = 0;
    virtual void draw(float dt) = 0;

    virtual void pause();
    virtual void resume();

  private:

};


#endif
