#ifndef WEAPON_H
#define WEAPON_H


class Weapon
{
    public:
        Weapon () {}
        Weapon (std::string NAME, int ATTACK, int WEIGHT) { name = NAME; attack = ATTACK; weight = WEIGHT; }
        virtual ~Weapon() {}

        std::string name = "Light Blade";

        int attack = 7;

        int weight = 13;
};

#endif // WEAPON_H
