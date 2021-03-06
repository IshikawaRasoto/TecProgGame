#include "Game.hpp"

#include "Levels/FirstLevel.hpp"
#include "Levels/SecondLevel.hpp"

#include "Menus/MainMenu.hpp"
#include "Menus/GameOver.hpp"
#include "Menus/Pause.hpp"
#include "Menus/Leaderboard.hpp"
#include "Menus/NewGame.hpp"
#include "Menus/YouWin.hpp"

#include <iostream>

Game::Game(): 
    graphicManager(Managers::GraphicsManager::getInstance()),
    eventManager(Managers::EventManager::getInstance()),
    inputManager(Managers::InputManager::getInstance()),
    StateMachine(),
    deltaTime(0.f)
{

    states[Patterns::StateId::FirstLevel] = new Levels::FirstLevel(this, true);
    states[Patterns::StateId::SecondLevel] = new Levels::SecondLevel(this, true);
    states[Patterns::StateId::MainMenu] = new Menus::MainMenu(this);
    states[Patterns::StateId::GameOver] = new Menus::GameOver(this);
    states[Patterns::StateId::Pause] = new Menus::Pause(this);
    states[Patterns::StateId::Leaderboard] = new Menus::Leaderboard(this);
    states[Patterns::StateId::NewGame] = new Menus::NewGame(this);
    states[Patterns::StateId::YouWin] = new Menus::YouWin(this);

    currentState = Patterns::StateId::MainMenu;
    currentLevel = nullptr;

    eventManager->subscribe("pressed", inputManager);
    eventManager->subscribe("released", inputManager);
    eventManager->subscribe("closed", graphicManager);
    eventManager->subscribe("resize", graphicManager);
}   

Game::~Game(){}

bool Game::isDone(){
    return graphicManager->isDone();
}

void Game::setCurrentLevel(StateId levelStateId){
    currentLevel = static_cast<Levels::Level*>(states[levelStateId]);
    currentLevelId = levelStateId;
}

Levels::Level* Game::getCurrentLevel(){
    return currentLevel;
}

StateId Game::getCurrentLevelId(){
    return currentLevelId;
}

void Game::execute(){
    while(!isDone()){
        update();
    }
}

void Game::update(){

    deltaTime = clock.restart().asSeconds();

    eventManager->pollEvents();
    updateCurrentState(deltaTime);
}

void Game::changeCurrentState(const StateId state){
    //Carregamos os dados da leaderboard novamente apenas se houver um gameOver ou youWin.
    if(lastState == StateId::GameOver || lastState == StateId::YouWin){
        states[StateId::Leaderboard]->reset();
    }

    if(state == StateId::MainMenu && currentLevel){
        currentLevel->reset();   
    }

    lastState = currentState;
    currentState = state;
}