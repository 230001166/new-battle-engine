#ifndef BODYPART_H
#define BODYPART_H
#include <string>
#include "Armor.h"

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

        void (*onDestruction)(Entity &parent);

};

#endif // BODYPART_H
