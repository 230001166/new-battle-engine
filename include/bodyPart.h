#ifndef BODYPART_H
#define BODYPART_H
#include <string>
#include "Armor.h"
#include "onDestructionFunctions.h"

class Entity;

class bodyPart
{
    public:
        bodyPart() {}
        virtual ~bodyPart() {}

        std::string name;

        int health = 12;
        int maxHealth = 12;

        Armor armor;

        bool isVital = false;

        void (*onDestruction)(Entity &parent) = onDestructionFunctions::doNothing;

};

#endif // BODYPART_H
