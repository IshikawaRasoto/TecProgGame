#include "Entities/Objects/Obstacles/Wagon.hpp"
using namespace Entities::Objects::Obstacles;

Wagon::Wagon(sf::Vector2f position):
    Object(Type::Wagon, position, sf::Vector2f(WAGON_WIDTH, WAGON_HEIGHT))
{
    initializeSprite();
}

Wagon::~Wagon(){}

void Wagon::initializeSprite(){
    animator.initializeTexture(WAGON_DIR, {1,1});
}

void Wagon::update(float dt){
    if(!getIsShowing())
        return;
    speed.y += GRAVITY * dt;
    move({0, speed.y});
    animator.update(position);
}

void Wagon::collide(Entities::Entity* other, sf::Vector2f intersect){
    Type t = other->getType();
    switch(t){
        case Type::Pavement:
            moveOnCollision(other, intersect);
            break;
    }
}