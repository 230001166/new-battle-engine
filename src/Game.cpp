#include "Game.h"

Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
}

Entity Game::createEntityFromName (std::string name) {
    Entity entity;

    if (name == "bandit-1") {
        entity.name = "Bandit";

        entity.defaultSpeed = 125;

        Weapon dagger ("Dagger", 3, 7);
        entity.weapon = dagger;

        bodyPart head; head.name = "Head"; head.isVital = true; head.health = 11; head.maxHealth = 11;
        Armor headArmor (6, 4); head.armor = headArmor;
        entity.bodyParts.push_back (head);

        bodyPart torso; torso.name = "Torso"; torso.isVital = true; torso.health = 19; torso.maxHealth = 19;
        Armor chestArmor (9, 8); torso.armor = chestArmor;
        entity.bodyParts.push_back (torso);

        bodyPart legs; legs.name = "Legs"; legs.isVital = false; legs.health = 9; legs.maxHealth = 9;
        Armor legArmor (6, 7); legs.armor = legArmor;
        entity.bodyParts.push_back (legs);
    }

    return entity;
}
