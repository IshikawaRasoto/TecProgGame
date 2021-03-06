#pragma once

#include "Entities/Entity.hpp"



#define MAX_SPEED_Y 300

namespace Entities{
    namespace Characters{

       enum class Direction{
            Idle = -1,
            Left,
            Right
        };

        class Character : public Entities::Entity{
            protected:
                int hp;
                int damage;
                Direction dirX;
                Direction dirY;
                bool isAttacking;

            public:
                Character(Type t, sf::Vector2f position, sf::Vector2f size, int hp, int dmg);
                virtual ~Character();

                const int getHP() const;
                const int getDamage() const;
                const bool getIsAttacking() const;

                void setIsAttacking(const bool atk = false);
                void receiveDMG(const int dmg);

                // virtual Snapshots::EntitySnapshot* save();
            protected:
                virtual void initializeSprite() = 0;      
        };
    }
}