#ifndef ENTITY_H
#define ENTITY_H
#include <vector>
#include "bodyPart.h"
#include "Weapon.h"

class Entity
{
    public:
        Entity() {}
        virtual ~Entity() {}

        std::string name;

        std::string status = "normal";
        int statusTurnsLeft = 0;

        Weapon weapon;

        std::vector <bodyPart> bodyParts;

        int defaultSpeed = 100;
        int actualSpeed = 100;

        bool isParrying = false;
        bool isGuarding = false;
        std::string partGuarding = "";

        bool isAlive () {
            for (unsigned int i = 0; i < bodyParts.size (); i++) {
                if (bodyParts [i].health < 0 && bodyParts [i].isVital == true) {
                    return false;
                }
            }

            return true;
        }

        void updateActualSpeed () {
            actualSpeed = defaultSpeed;

            actualSpeed -= weapon.weight;

            for (unsigned int i = 0; i < bodyParts.size (); i++) {
                if (bodyParts [i].armor.armor > 0) {
                    actualSpeed -= bodyParts [i].armor.weight;
                }
            }
        }

        void updateStatus () {
            if (statusTurnsLeft == 0) {
                status = "normal";
            } else {
                statusTurnsLeft--;
            }
        }

        void updateStats () {
            updateActualSpeed ();
            updateStatus ();
            isParrying = false;
            isGuarding = false;
            partGuarding = "";
        }

        void (*AI)(Entity &parent, Entity &target);

};

#endif // ENTITY_H
