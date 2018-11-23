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

typedef std::unique_ptr<State> StateRef;

class StateManager {
  
  public:
    StateManager();
    ~StateManager();

    void pushState(StateRef newState, bool isReplacing = true);
    void popState();

    void updateStates();

    StateRef &getActiveState();

  private:
    std::stack<StateRef> statesStack;
    StateRef newState;

    bool isPushing;
    bool isReplacing;
    bool isPopping;

};

#endif
