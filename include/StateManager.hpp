/**
  * Filename: StateManager.hpp
  *
  * Manages the different states (a.k.a. Screens) of the game.
**/

#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

#include <memory>
#include <stack>
#include "State.hpp"

typedef std::unique_ptr<State> StateRef; // smart pointer that points at a state


class StateManager {

  public:
    /**
      * Constructor and Destructor.
    **/
    StateManager();
    ~StateManager();

    /**
      * Sets isPushing to true. Sets isReplacing to the given parameter.
      * Prepares the newState to be moved.
    **/
    void pushState(StateRef newState, bool isReplacing = true);

    /**
      * Sets isPopping to true.
    **/
    void popState();

    /**
      * Updates the state stack:
      *   If isPopping is true, pops current state off the stack.
      *   If isPushing is true, pushes a state onto the stack.
      *   If isReplacing is true, pops current state then pushes a new state.
    **/
    void updateStates();

    /**
      * Returns the state at the top of the stack.
    **/
    StateRef &getActiveState();


  private:
    std::stack<StateRef> statesStack;   // Stack of the states
    StateRef newState;                  // newest state

    // booleans to let the StateManager know what to do
    bool isPushing;
    bool isReplacing;
    bool isPopping;

};

#endif
