#ifndef BODYPART_H
#define BODYPART_H
#include <string>

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
};

#endif // BODYPART_H
