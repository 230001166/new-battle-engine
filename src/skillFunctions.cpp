#include <iostream>
#include "skillFunctions.h"

void skillFunctions::do_nothing (Entity &user, Entity &enemy, bodyPart &target) {
    std::cout << user.name << " did nothing!" << std::endl;

}

void skillFunctions::attack (Entity &user, Entity &enemy, bodyPart &target) {
    std::cout << user.name << " attacks " << enemy.name << "!" << std::endl;

    int baseDamage = user.weapon.attack, healthDamage = 0;

    if (enemy.isParrying && target.name == enemy.partGuarding) {
        std::cout << enemy.name << " parried the attack!" << std::endl;
        user.status = "vulnerable";
        user.statusTurnsLeft = 1;
        enemy.isParrying = false;
    } else if (enemy.isParrying && target.name != enemy.partGuarding) {
        std::cout << enemy.name << " was caught off guard!" << std::endl;
        enemy.status = "vulnerable";
        enemy.statusTurnsLeft = 1;
        enemy.isParrying = false;
    } else {
        if (enemy.isGuarding && target.name == enemy.partGuarding) { baseDamage = 0; std::cout << enemy.name << " blocked the attack!" << std::endl; }

        if (enemy.status == "vulnerable") { baseDamage *= 1.5; }

        if (target.armor.armor > 0) {
            if (baseDamage > target.armor.armor) {
                healthDamage = baseDamage - target.armor.armor;
                target.armor.armor = 0;
                std::cout << enemy.name << "'s " << target.name << " armor was broken!" << std::endl;
            } else {
                target.armor.armor -= baseDamage;
            }
        } else {
            healthDamage = baseDamage;
        }

        target.health -= healthDamage; if (healthDamage > 0) { std::cout << enemy.name << "'s " << target.name << " took " << healthDamage << " damage!" << std::endl; }
    }

}

void skillFunctions::parry (Entity &user, Entity &enemy, bodyPart &target) {
    user.partGuarding = target.name;
    user.isParrying = true;
    std::cout << user.name << " is ready to parry an attack!" << std::endl;
}

void skillFunctions::guard (Entity &user, Entity &enemy, bodyPart &target) {
    user.partGuarding = target.name;
    user.isGuarding = true;
    std::cout << user.name << " is ready to block an attack!" << std::endl;
}
