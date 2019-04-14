#ifndef ARMOR_H
#define ARMOR_H


class Armor
{
    public:
        Armor() {}
        Armor (int ARMOR, int WEIGHT) { armor = ARMOR; maxArmor = armor; weight = WEIGHT; }
        virtual ~Armor() {}

        int armor = 5;
        int maxArmor = 5;

        int weight = 10;
};

#endif // ARMOR_H
