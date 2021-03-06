#include "Entities/FireBall.hpp"
using namespace Entities;

FireBall::FireBall(sf::Vector2f position):
    Entity(Type::FireBall, position, {FIREBALL_WIDTH, FIREBALL_HEIGHT})
{
    initializeSprite();
    setIsShowing(false);
}

FireBall::~FireBall(){}

void FireBall::initializeSprite(){
    animator.initializeTexture(FIREBALL_DIR, {7, 2});
}

void FireBall::render(){
    animator.render();
}

void FireBall::update(float dt){
    if(!getIsShowing())
        return;
    //MUDAR PARA ALGUM CALCULO DE ATRITO COM O AR
    if(getFacingLeft()){
        speed = sf::Vector2f(speed.x + AIR_RESISTANCE*dt, speed.y + (GRAVITY-AIR_RESISTANCE) * dt);
        if(speed.x >-10)
            speed.x = -10;
    }else{
        speed = sf::Vector2f(speed.x - AIR_RESISTANCE*dt, speed.y + (GRAVITY-AIR_RESISTANCE) * dt);
        if(speed.x < 10)
            speed.x = 10;
    }
    
    if(speed.y > 6)
        speed.y = 6;

    move({speed.x * dt , speed.y * dt});
    animator.update(position, 0, 6, dt, getFacingLeft(), 0.3);
}

void FireBall::collide(Entity *other, sf::Vector2f intersect){
    Type type = other->getType();

    switch(type){
        case Type::Pavement:
            setIsShowing(false);
            break;
        case Type::Box:
            setIsShowing(false);
            break;
        case Type::Barrel:
            setIsShowing(false);
            break;
        case Type::Gravestone:
            setIsShowing(false);
            break;
        case Type::Ground:
            setIsShowing(false);
            break;
        case Type::MiniGround:
            setIsShowing(false);
            break;
        case Type::Player:
            setIsShowing(false);
            (static_cast<Characters::Character*>(other))->receiveDMG(FIREBALL_DMG);
            break;
    }
}

void FireBall::shoot(sf::Vector2f position, sf::Vector2f sp){
    setSpeed(sp);
    setPosition(position);
    setIsShowing(true);
    if(speed.x > 0)
        setFacingLeft(false);
    else
        setFacingLeft(true);
}