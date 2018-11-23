/**
  * Filename: StateManager.cpp
  *
  *
**/

#include "StateManager.hpp"


StateManager::StateManager() {}

StateManager::~StateManager() {}

void StateManager::pushState(StateRef newState, bool isReplacing) {
  this->isPushing = true;
  this->isReplacing = isReplacing;
  this->newState = std::move(newState);
}

void StateManager::popState() {
  this->isPopping = true;
}

void StateManager::updateStates() {
  if (this->isPopping && !this->statesStack.empty()) {
    this->statesStack.pop();
    if(!this->statesStack.empty()) {
      this->statesStack.top()->resume();
    }
    this->isPopping = false;
  }

  if (this->isPushing) {
    if (!this->statesStack.empty()) {
      if (this->isReplacing) {
        this->statesStack.pop();
      } else {
        this->statesStack.top()->pause();
      }
    }
    this->statesStack.push(std::move(this->newState));
    this->statesStack.top()->init();
    this->isPushing = false;
  }
}

StateRef &StateManager::getActiveState() {
  return this->statesStack.top();
}
