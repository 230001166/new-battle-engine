#include <iostream>
#include "Game.h"
#include "skillFunctions.h"

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

        Weapon dagger ("Dagger", 5, 7);
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

void Game::battle (Entity &player, std::vector <Entity> &enemies) {
    while (player.isAlive() && factionHasAliveMembers (enemies)) {
        displayPlayerStats (player);
        displayPlayerStats (enemies [0]);
        std::cout << "[1] Attack \n[2] Parry\n[3] Guard" << std::endl;
        int choice = -1;

        while (choice < 1 || choice > 3) { std::cin >> choice; } choice--;

        switch (choice) {
            case 0: {
                int enemyTarget = -1, bodyPartTarget = -1;
                std::cout << "Target which enemy?" << std::endl;
                for (unsigned int i = 0; i < enemies.size (); i++) {
                    std::cout << "[" << i+1 << "] - " << enemies [i].name << std::endl;
                }
                while (enemyTarget < 1 || enemyTarget > enemies.size ()) { std::cin >> enemyTarget; } enemyTarget--;

                std::cout << "Target which body part?" << std::endl;
                for (unsigned int i = 0; i < enemies [enemyTarget].bodyParts.size (); i++) {
                    std::cout << "[" << i+1 << "] - " << enemies [enemyTarget].bodyParts [i].name << std::endl;
                }
                while (bodyPartTarget < 1 || bodyPartTarget > enemies.size ()) { std::cin >> bodyPartTarget; } bodyPartTarget--;

                skillFunctions::attack (player, enemies [enemyTarget], enemies [enemyTarget].bodyParts [bodyPartTarget]);
            } break;
            case 1: {

            } break;
            case 2: {

            } break;
        }

    }
}

bool Game::factionHasAliveMembers (std::vector <Entity> faction) {

    for (unsigned int i = 0; i < faction.size (); i++) {
        if (!faction [i].isAlive ()) { return false; }
    }

    return true;
}

void Game::displayPlayerStats (Entity &player) {
    std::cout << player.name << std::endl;
    for (unsigned int i = 0; i < player.bodyParts.size (); i++) {
        std::cout << " - " << player.bodyParts [i].name << " - HP " << player.bodyParts [i].health << " - ARMOR " << player.bodyParts [i].armor.armor << std::endl;
    }
}
