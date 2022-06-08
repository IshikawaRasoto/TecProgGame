#include "Game.hpp"

#include "States/FirstLevel.hpp"
#include "States/MainMenu.hpp"

#include <iostream>

Game::Game(): 
    graphicManager(Managers::GraphicsManager::getInstance()),
    eventManager(Managers::EventManager::getInstance()),
    inputManager(Managers::InputManager::getInstance()),
    StateMachine(),
    deltaTime(0.f)
{

    states[Patterns::StateId::FirstLevel] = new States::FirstLevel(this);
    states[Patterns::StateId::MainMenu] = new States::MainMenuState(this);

    currentState = Patterns::StateId::MainMenu;

    eventManager->subscribe("pressed", inputManager);
    eventManager->subscribe("released", inputManager);
    eventManager->subscribe("closed", graphicManager);
    eventManager->subscribe("resize", graphicManager);
}   

Game::~Game(){}

bool Game::isDone(){
    return graphicManager->isDone();
}

/*sf::Time Game::getElapsed(){
    return elapsed;
}*/

void Game::execute(){
    while(!isDone()){
        update();
        //restartClock();
    }
}

void Game::update(){
    //float frametime = 1.f / 60.f;

    //if(elapsed.asSeconds() < frametime) return;

    deltaTime = clock.restart().asSeconds();

    eventManager->pollEvents();
    updateCurrentState(deltaTime);

    //elapsed -= sf::seconds(frametime);
}

/*void Game::restartClock(){
    elapsed += clock.restart();
}*/
