#ifndef ENTITY_H
#define ENTITY_H
#include <vector>
#include "bodyPart.h"
#include "Status.h"
#include "Weapon.h"

class Entity
{
    public:
        Entity() {}
        virtual ~Entity() {}

        std::string name;

        Status status;

        Weapon weapon;

        std::vector <bodyPart> bodyParts;

        bool isAlive () {
            for (unsigned int i = 0; i < bodyParts.size (); i++) {
                if (bodyParts [i].health < 0 && bodyParts [i].isVital) {
                    return false;
                }
            }

            return true;
        }
};

#endif // ENTITY_H
