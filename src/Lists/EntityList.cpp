#include "Lists/EntityList.hpp"

using namespace Lists;

EntityList::EntityList(){}

EntityList::~EntityList(){}

bool EntityList::addEntity(Entities::Entity *entity){

    if(!entity){
        return false;
    }

    list.add(entity);

    return true;
}


bool EntityList::addEntity(std::vector<Entities::Entity*> entities){
    for(auto entity : entities){
        if(!entity){
            return false;
        }

        list.add(entity);
    }

    return true;
}

bool EntityList::removeEntity(Entities::Entity *entity){
    return false;
}

void EntityList::updateAll(float dt){
    for(int i = 0; i < list.getSize(); i++){
        if(list[i]->getIsShowing()) list[i]->update(dt);
    }
}

void EntityList::renderAll(){
    for(int i = 0; i < list.getSize(); i++){
        if(list[i]->getIsShowing()) list[i]->render();
    }
}

void EntityList::clearAll(){
    list.clearAll();
}

Entities::Entity* EntityList::operator[](unsigned int index){
    return list[index];
}

const int EntityList::getSize(){
    return list.getSize();
}