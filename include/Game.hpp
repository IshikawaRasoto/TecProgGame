#pragma once

#include <SFML/Graphics.hpp>

#include "Managers/Graphics.hpp"
#include "Managers/Input.hpp"
#include "Managers/Event.hpp"

#include "States/Level.hpp"
#include "Patterns/StateMachine.hpp"

class Game : public Patterns::StateMachine{

public:

    Game();
    ~Game();
    void execute();

private:

    sf::Time getElapsed();
    
    bool isDone();
    void update();

    void restartClock();

    sf::Clock clock;
    sf::Time elapsed;
    
    Managers::GraphicsManager *graphicManager;
    Managers::InputManager *inputManager;
    Managers::EventManager *eventManager;
};