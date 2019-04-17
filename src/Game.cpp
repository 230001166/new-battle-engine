#include <iostream>
#include "Game.h"
#include "aiFunctions.h"
#include "skillFunctions.h"
#include "utilityFunctions.h"

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

        Weapon sword ("Sword", 6, 10);
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

        entity.faction = "player";
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
    if (name == "rat") {
        entity.name = "Rat";

        entity.defaultSpeed = 80;

        Weapon fangs ("Fangs", 2, 1);
        entity.weapon = fangs;

        bodyPart body; body.name = "body"; body.isVital = true; body.health = 8; body.maxHealth = 8;
        Armor bodyArmor (0, 0); body.armor = bodyArmor;
        entity.bodyParts.push_back (body);

        entity.AI = aiFunctions::rat;
    }
    if (name == "bandit-1") {
        entity.name = "Bandit";

        entity.defaultSpeed = 85;

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
    if (name == "bandit-2") {
        entity.name = "Bandit";

        entity.defaultSpeed = 140;

        Weapon sickle ("Sickle", 6, 5);
        entity.weapon = sickle;

        bodyPart head; head.name = "Head"; head.isVital = true; head.health = 7; head.maxHealth = 7;
        Armor headArmor (3, 4); head.armor = headArmor;
        entity.bodyParts.push_back (head);

        bodyPart torso; torso.name = "Torso"; torso.isVital = true; torso.health = 10; torso.maxHealth = 10;
        Armor chestArmor (5, 4); torso.armor = chestArmor;
        entity.bodyParts.push_back (torso);

        bodyPart legs; legs.name = "Legs"; legs.isVital = false; legs.health = 9; legs.maxHealth = 9;
        Armor legArmor (1, 1); legs.armor = legArmor;
        entity.bodyParts.push_back (legs);

        entity.AI = aiFunctions::bandit_two;
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

void Game::battle (std::vector <Entity> &combatants) {
    while (factionHasAliveMembers (combatants, "player") && factionHasAliveMembers (combatants, "enemy")) {
        displayCombatantStats (combatants);
        for (unsigned int i = 0; i < combatants.size (); i++) {
            if (combatants [i].isAlive () && combatants [i].faction == "player") {
                combatants [i].updateStats ();
                std::cout << "[1] Attack \n[2] Parry\n[3] Guard" << std::endl;
                int choice = -1;

                while (choice < 1 || choice > 3) { std::cin >> choice; } choice--;

                switch (choice) {
                    case 0: {
                        inputPlayerTarget (combatants [i], combatants);
                    } break;
                    case 1: {
                        int bodyPartTarget = getGuardTargetIndex (combatants [i]);
                        skillFunctions::parry (combatants [i], combatants [i], combatants [i].bodyParts [bodyPartTarget]);
                    } break;
                    case 2: {
                        int bodyPartTarget = getGuardTargetIndex (combatants [i]);
                        skillFunctions::guard (combatants [i], combatants [i], combatants [i].bodyParts [bodyPartTarget]);
                    } break;
                }
            }
            if (combatants [i].isAlive () && combatants [i].faction == "enemy") {
                combatants [i].updateStats ();
                combatants [i].AI (combatants [i], combatants [0]);
            }
        }

    }
}

void Game::inputPlayerTarget (Entity &player, std::vector <Entity> &combatants) {
    int enemyTarget = -1, bodyPartTarget = -1;
    std::vector <int> validTargetIndices;

    for (unsigned int i = 0; i < combatants.size (); i++) {
        if (combatants [i].isAlive () && combatants [i].faction == "enemy") {
            validTargetIndices.push_back (i);
        }
    }

    std::cout << "Target which enemy?" << std::endl;
    for (unsigned int i = 0; i < validTargetIndices.size (); i++) {
        if (combatants [validTargetIndices [i]].isAlive ()) {
            std::cout << "[" << i+1 << "] - " << combatants [validTargetIndices [i]].name << std::endl;
        }
    }
    while (enemyTarget < 1 || enemyTarget > validTargetIndices.size ()) { std::cin >> enemyTarget; } enemyTarget--;
    enemyTarget = validTargetIndices [enemyTarget];

    validTargetIndices.clear ();

    for (unsigned int i = 0; i < combatants [enemyTarget].bodyParts.size (); i++) {
        if (combatants [enemyTarget].bodyParts [i].health > 0) {
            validTargetIndices.push_back (i);
        }
    }
    std::cout << "Target which body part?" << std::endl;
    for (unsigned int i = 0; i < validTargetIndices.size (); i++) {
        std::cout << "[" << i+1 << "] - " << combatants [enemyTarget].bodyParts [validTargetIndices [i]].name << std::endl;
    }
    while (bodyPartTarget < 1 || bodyPartTarget > validTargetIndices.size ()) { std::cin >> bodyPartTarget; } bodyPartTarget--;
    bodyPartTarget = validTargetIndices [bodyPartTarget];

    skillFunctions::attack (player, combatants [enemyTarget], combatants [enemyTarget].bodyParts [bodyPartTarget]);
}

int Game::getGuardTargetIndex (Entity &player) {
    int bodyPartTarget = -1;
    std::vector <int> validTargetIndices;

    for (unsigned int i = 0; i < player.bodyParts.size (); i++) {
        if (player.bodyParts [i].health > 0) {
            validTargetIndices.push_back (i);
        }
    }

    std::cout << "Target which body part?" << std::endl;
    for (unsigned int i = 0; i < validTargetIndices.size (); i++) {
        std::cout << "[" << i+1 << "] - " << player.bodyParts [validTargetIndices [i]].name << std::endl;
    }
    while (bodyPartTarget < 1 || bodyPartTarget > validTargetIndices.size ()) { std::cin >> bodyPartTarget; } bodyPartTarget--;
    bodyPartTarget = validTargetIndices [bodyPartTarget];

    return bodyPartTarget;
}

bool Game::factionHasAliveMembers (std::vector <Entity> combatants, std::string faction) {
    bool factionMemberIsAlive = false;
    for (unsigned int i = 0; i < combatants.size (); i++) {
        if (combatants [i].isAlive () && combatants [i].faction == faction) { factionMemberIsAlive = true; }
    }

    return factionMemberIsAlive;
}

void Game::displayCombatantStats (std::vector <Entity> &combatants) {
    for (unsigned int i = 0; i < combatants.size (); i++) {
        if (combatants [i].isAlive () && combatants [i].faction == "player") {
            std::cout << "PLAYER ";
            displayPlayerStats (combatants [i]);
        }
        if (combatants [i].isAlive () && combatants [i].faction == "enemy") {
            std::cout << "ENEMY ";
            displayPlayerStats (combatants [i]);
        }
    }
}

void Game::displayPlayerStats (Entity &player) {
    std::cout << player.name << " (" << player.status << ")" << std::endl;
    for (unsigned int i = 0; i < player.bodyParts.size (); i++) {
        std::cout << " - " << player.bodyParts [i].name << " - HP " << player.bodyParts [i].health << " - ARMOR " << player.bodyParts [i].armor.armor << std::endl;
    }
}

void Game::loop () {
    Entity player = createEntityFromName ("player");
    while (player.isAlive ()) {
        const int NUMBER_OF_ENEMIES = 5;
        std::string enemyNames [NUMBER_OF_ENEMIES] = {"slime","bandit-1","bandit-2","dragon","rat"};
        Entity enemy;

        enemy = createEntityFromName ("rat");
        enemy.updateActualSpeed ();

        std::vector <Entity> combatants;
        combatants.push_back (player);
        combatants.push_back (enemy);
        combatants.push_back (enemy);
        enemy = createEntityFromName ("bandit-1"); combatants.push_back (enemy);

        battle (combatants);
    }

}
