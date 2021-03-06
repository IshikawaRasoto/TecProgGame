#include "Entities/Characters/Enemies/Enemy.hpp"

using namespace Entities::Characters::Enemies;

Enemy::Enemy(Type t, sf::Vector2f position, sf::Vector2f size, int hp, int dmg, Characters::Player* p1, Characters::Player* p2):
    Character(t, position, size, hp, dmg),
    pP1(p1),
    pP2(p2),
    atkCD(0.0),
    timeFromAtk(0.0),
    dx(0.0)
{}

Enemy::~Enemy(){
    pP1 = nullptr;
    pP2 = nullptr;
}


void Enemy::setPlayer1(Entities::Characters::Player* player){
    this->pP1 = player;
}

void Enemy::setPlayer2(Entities::Characters::Player* player){
    this->pP2 = player;
}

Entities::Characters::Player* Enemy::getNearestPlayer(){
    int x1, x2;
    if(!pP2)
        return pP1;
    x1 = abs(pP1->getPosition().x - position.x);
    x2 = abs(pP2->getPosition().x - position.x);
    if(x1 <= x2 && pP1->getHP()>0 || pP2->getHP()<=0)
        return pP1;
    else if(x1>x2 && pP2->getHP()>0 || pP1->getHP()<=0)
        return pP2;
    return nullptr;
}

void Enemy::tryAttack(const int dmg){
    if((getNearestPlayer()->getPosition().x - position.x) >= 0 && !getFacingLeft())
        getNearestPlayer()->receiveDMG(dmg);
    else if((getNearestPlayer()->getPosition().x - position.x) <= 0 && getFacingLeft())
        getNearestPlayer()->receiveDMG(dmg);
    setIsAttacking(true);
    timeFromAtk = 0.0; //Utilizado na animacao
    atkCD = 0.0;
}

void Enemy::collide(Entity* other, sf::Vector2f intersect){
    Type type = other->getType();
    //std::cout<<"Collision Enemy"<<type<<std::endl;

    switch (type){
        case Type::Pavement:
            moveOnCollision(other, intersect);
            break;
        case Type::Box:
            moveOnCollision(other, intersect);
            break;
        case Type::Barrel:
            moveOnCollision(other, intersect);
            break;
        case Type::Ground:
            moveOnCollision(other, intersect);
            break;
        case Type::MiniGround:
            moveOnCollision(other, intersect);
            break;
        case Type::Gravestone:
            moveOnCollision(other, intersect);
            break;
        case Type::Thorns:
            receiveDMG(hp);
            break;
    }
}