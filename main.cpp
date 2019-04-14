#include <iostream>
#include "Game.h"

int main()
{
    Game game;

    Entity bandit = game.createEntityFromName ("bandit-1");
    bandit.updateActualSpeed ();

    std::cout << bandit.name << std::endl;
    for (unsigned int i = 0; i < bandit.bodyParts.size (); i++) {
        std::cout << bandit.bodyParts [i].name << std::endl;
        std::cout << bandit.bodyParts [i].health << std::endl;
        std::cout << bandit.bodyParts [i].armor.armor << std::endl;
    }
    std::cout << bandit.actualSpeed << " / " << bandit.defaultSpeed << std::endl;

    std::vector <Entity> enemies; enemies.push_back (bandit);
    bandit.name = "steve";
    game.battle (bandit, enemies);
    return 0;
}
