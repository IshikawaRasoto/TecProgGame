#pragma once

#include <SFML/Graphics.hpp>

#include "Window.hpp"
#include "Managers/Collision.hpp"
#include "Entities/Characters/Players/Huntress.hpp"
#include "Lists/EntityList.hpp"


using namespace Entities::Characters;

#include "Lists/EntityList.hpp"

class Game{

public:

    Game();
    ~Game();

    sf::Time getElapsed();
    Window* getWindow();

    void update();
    void handleInput();
    void render();

    void restartClock();
private:
    sf::Clock clock;
    sf::Time elapsed;

    Lists::EntityList movingEntities;
    Lists::EntityList staticEntities;

    Players::Huntress player;
    Managers::GraphicsManager *graphicManager;
    Managers::CollisionManager collisionManager;
};