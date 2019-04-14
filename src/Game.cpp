#include <iostream>
#include "Game.h"
#include "aiFunctions.h"
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

    if (name == "player") {
        std::cout << "Enter your name: ";
        std::getline (std::cin, entity.name);
        entity.defaultSpeed = 100;

        Weapon sword ("Sword", 5, 10);
        entity.weapon = sword;

        bodyPart head; head.name = "Head"; head.isVital = true; head.health = 10; head.maxHealth = 10;
        Armor headArmor (5, 5); head.armor = headArmor;
        entity.bodyParts.push_back (head);

        bodyPart torso; torso.name = "Torso"; torso.isVital = true; torso.health = 15; torso.maxHealth = 15;
        Armor chestArmor (7, 15); torso.armor = chestArmor;
        entity.bodyParts.push_back (torso);

        bodyPart legs; legs.name = "Legs"; legs.isVital = false; legs.health = 10; legs.maxHealth = 10;
        Armor legArmor (3, 5); legs.armor = legArmor;
        entity.bodyParts.push_back (legs);
    }
    if (name == "slime") {
        entity.name = "Slime";

        entity.defaultSpeed = 60;

        Weapon goop ("Goop", 5, 5);
        entity.weapon = goop;

        bodyPart slime; slime.name = "Slime"; slime.isVital = true; slime.health = 20; slime.maxHealth = 20;
        entity.bodyParts.push_back (slime);

        entity.AI = aiFunctions::slime;
    }
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

        entity.AI = aiFunctions::bandit_one;
    }
    if (name == "dragon") {
        entity.name = "Dragon";

        entity.defaultSpeed = 60;

        Weapon claws ("Claws", 6, 5);

        bodyPart head; head.name = "Head"; head.isVital = true; head.health = 22; head.maxHealth = 22;
        Armor headArmor (5, 5); head.armor = headArmor;
        entity.bodyParts.push_back (head);

        bodyPart body; body.name = "Body"; body.isVital = true; body.health = 30; body.maxHealth = 30;
        Armor bodyArmor (35, 15); body.armor = bodyArmor;
        entity.bodyParts.push_back (body);

        bodyPart legs; legs.name = "Legs"; legs.isVital = false; legs.health = 15; legs.maxHealth = 15;
        Armor legArmor (5, 5); legs.armor = legArmor;
        entity.bodyParts.push_back (legs);

        bodyPart tail; tail.name = "Tail"; tail.isVital = false; tail.health = 10; tail.maxHealth = 10;
        Armor tailArmor (1, 5); tail.armor = tailArmor;
        entity.bodyParts.push_back (tail);

    }

    return entity;
}

void Game::battle (Entity &player, std::vector <Entity> &enemies) {
    while (player.isAlive() && factionHasAliveMembers (enemies)) {
        displayPlayerStats (player);
        displayPlayerStats (enemies [0]);
        player.updateStats ();
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
                int bodyPartTarget = -1;

                std::cout << "Target which body part?" << std::endl;
                for (unsigned int i = 0; i < player.bodyParts.size (); i++) {
                    std::cout << "[" << i+1 << "] - " << player.bodyParts [i].name << std::endl;
                }
                while (bodyPartTarget < 1 || bodyPartTarget > player.bodyParts.size ()) { std::cin >> bodyPartTarget; } bodyPartTarget--;

                skillFunctions::parry (player, enemies [0], player.bodyParts [bodyPartTarget]);
            } break;
            case 2: {
                int bodyPartTarget = -1;

                std::cout << "Target which body part?" << std::endl;
                for (unsigned int i = 0; i < player.bodyParts.size (); i++) {
                    std::cout << "[" << i+1 << "] - " << player.bodyParts [i].name << std::endl;
                }
                while (bodyPartTarget < 1 || bodyPartTarget > player.bodyParts.size ()) { std::cin >> bodyPartTarget; } bodyPartTarget--;

                skillFunctions::guard (player, enemies [0], player.bodyParts [bodyPartTarget]);
            } break;
        }

        for (unsigned int i = 0; i < enemies.size (); i++) {
            enemies [i].updateStats ();
            enemies [i].AI (enemies [i], player);
        }

    }
}

bool Game::factionHasAliveMembers (std::vector <Entity> faction) {

    for (unsigned int i = 0; i < faction.size (); i++) {
        if (faction [i].isAlive () == false) { return false; }
    }

    return true;
}

void Game::displayPlayerStats (Entity &player) {
    std::cout << player.name << " (" << player.status << ")" << std::endl;
    for (unsigned int i = 0; i < player.bodyParts.size (); i++) {
        std::cout << " - " << player.bodyParts [i].name << " - HP " << player.bodyParts [i].health << " - ARMOR " << player.bodyParts [i].armor.armor << std::endl;
    }
}
