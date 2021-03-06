#pragma once

#include <map>

#include "State.hpp"

namespace Patterns{

class StateMachine{
protected:

    StateId currentState;
    StateId lastState;

    std::map<StateId, State*> states;
public:

    StateMachine();
    virtual ~StateMachine();

    StateId getCurrentState();
    StateId getLastState();
    
    virtual void changeCurrentState(const StateId state);
    void updateCurrentState(const float dt);
    void renderCurrentState();
};

};