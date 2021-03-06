#include "Ent/Ent.hpp"

Ent::Ent():
    animator(),
    t(Empty)
{
    position = sf::Vector2f(0.0f, 0.0f);
    size = sf::Vector2f(0.0f, 0.0f);
}

Ent::Ent(Type t, sf::Vector2f position, sf::Vector2f size):
    animator(size),
    t(t),
    position(position),
    size(size)
{}

Ent::~Ent(){}

const sf::Vector2f Ent::getPosition() const{return position;}
const Type Ent::getType() const{return t;}
const sf::Vector2f Ent::getSize() const {return size;}
const bool Ent::getIsShowing() const {return showing;}

void Ent::setPosition(sf::Vector2f position){
    this->position = position;
}

void Ent::setIsShowing(const bool showing){
    this->showing = showing;
}

void Ent::moveBody(const sf::Vector2f v){
    position = sf::Vector2f(position.x + v.x, position.y + v.y);
}

void Ent::render(){
    animator.update(position);
    animator.render();
}

void Ent::update(const float dt){}