#include <iostream>
#include "aiFunctions.h"
#include "skillFunctions.h"
#include "utilityFunctions.h"

void aiFunctions::bandit_one (Entity &user, Entity &target) {
    enum targetPriorities { head = 1, torso = 3, legs = 2}; /// Prioritizing targets

    const int ATTACK_CHANCE = 70, PARRY_CHANCE = 20, GUARD_CHANCE = 10;

    int randomNumber = utilityFunctions::random (1, 100);

    if (randomNumber <= ATTACK_CHANCE) {
        randomNumber = utilityFunctions::random (1, targetPriorities::head + targetPriorities::torso + targetPriorities::legs);
        if (randomNumber <= targetPriorities::head) {
            skillFunctions::attack (user, target, target.bodyParts [0]);
        } else if (randomNumber <= targetPriorities::head + targetPriorities::torso) {
            skillFunctions::attack (user, target, target.bodyParts [1]);
        } else {
            if (target.bodyParts [2].health <= 0) {
                skillFunctions::attack (user, target, target.bodyParts [utilityFunctions::random (0, 1)]);
            } else {
                skillFunctions::attack (user, target, target.bodyParts [2]);
            }
        }
    } else if (randomNumber <= PARRY_CHANCE+ATTACK_CHANCE) {
        randomNumber = utilityFunctions::random (1, targetPriorities::head + targetPriorities::torso + targetPriorities::legs);

        if (randomNumber <= targetPriorities::head) {
            skillFunctions::parry (user, user.bodyParts [0]);
        } else if (randomNumber <= targetPriorities::head + targetPriorities::torso) {
            skillFunctions::parry (user, user.bodyParts [1]);
        } else {
            skillFunctions::parry (user, user.bodyParts [2]);
        }
    } else {
        randomNumber = utilityFunctions::random (1, targetPriorities::head + targetPriorities::torso + targetPriorities::legs);

        if (randomNumber <= targetPriorities::head) {
            skillFunctions::guard (user, user.bodyParts [0]);
        } else if (randomNumber <= targetPriorities::head + targetPriorities::torso) {
            skillFunctions::guard (user, user.bodyParts [1]);
        } else {
            skillFunctions::guard (user, user.bodyParts [2]);
        }
    }
}

void aiFunctions::bandit_two (Entity &user, Entity &target) {
    enum targetPriorities { head = 1, torso = 1, legs = 1}; /// Prioritizing targets

    const int ATTACK_CHANCE = 50, PARRY_CHANCE = 20, GUARD_CHANCE = 30;

    int randomNumber = utilityFunctions::random (1, 100);

    if (randomNumber <= ATTACK_CHANCE) {
        randomNumber = utilityFunctions::random (1, targetPriorities::head + targetPriorities::torso + targetPriorities::legs);

        if (randomNumber <= targetPriorities::head) {
            skillFunctions::attack (user, target, target.bodyParts [0]);
        } else if (randomNumber <= targetPriorities::head + targetPriorities::torso) {
            skillFunctions::attack (user, target, target.bodyParts [1]);
        } else {
            if (target.bodyParts [2].health <= 0) {
                skillFunctions::attack (user, target, target.bodyParts [utilityFunctions::random (0, 1)]);
            } else {
                skillFunctions::attack (user, target, target.bodyParts [2]);
            }
        }
    } else if (randomNumber <= PARRY_CHANCE+ATTACK_CHANCE) {
        randomNumber = utilityFunctions::random (1, targetPriorities::head + targetPriorities::torso + targetPriorities::legs);

        if (randomNumber <= targetPriorities::head) {
            skillFunctions::parry (user, user.bodyParts [0]);
        } else if (randomNumber <= targetPriorities::head + targetPriorities::torso) {
            skillFunctions::parry (user, user.bodyParts [1]);
        } else {
            skillFunctions::parry (user, user.bodyParts [2]);
        }
    } else {
        randomNumber = utilityFunctions::random (1, targetPriorities::head + targetPriorities::torso + targetPriorities::legs);

        if (randomNumber <= targetPriorities::head) {
            skillFunctions::guard (user, user.bodyParts [0]);
        } else if (randomNumber <= targetPriorities::head + targetPriorities::torso) {
            skillFunctions::guard (user, user.bodyParts [1]);
        } else {
            skillFunctions::guard (user, user.bodyParts [2]);
        }
    }
}

void aiFunctions::slime (Entity &user, Entity &target) {
    enum targetPriorities { head = 1, torso = 3, legs = 2}; /// Prioritizing targets

    const int ATTACK_CHANCE = 60, PARRY_CHANCE = 40, GUARD_CHANCE = 0;

    int randomNumber = utilityFunctions::random (1, 100);

    if (randomNumber <= ATTACK_CHANCE) {
        randomNumber = utilityFunctions::random (1, targetPriorities::head + targetPriorities::torso + targetPriorities::legs);

        if (randomNumber <= targetPriorities::head) {
            skillFunctions::attack (user, target, target.bodyParts [0]);
        } else if (randomNumber <= targetPriorities::head + targetPriorities::torso) {
            skillFunctions::attack (user, target, target.bodyParts [1]);
        } else {
            if (target.bodyParts [2].health <= 0) {
                skillFunctions::attack (user, target, target.bodyParts [utilityFunctions::random (0, 1)]);
            } else {
                skillFunctions::attack (user, target, target.bodyParts [2]);
            }
        }
    } else if (randomNumber <= PARRY_CHANCE+ATTACK_CHANCE) {
        skillFunctions::parry (user, user.bodyParts [0]);
    }
}

void aiFunctions::rat (Entity &user, Entity &target) {
    enum targetPriorities { head = 1, torso = 2, legs = 3}; /// Prioritizing targets

    const int ATTACK_CHANCE = 90, PARRY_CHANCE = 10, GUARD_CHANCE = 0;

    int randomNumber = utilityFunctions::random (1, 100);

    if (randomNumber <= ATTACK_CHANCE) {
        randomNumber = utilityFunctions::random (1, targetPriorities::head + targetPriorities::torso + targetPriorities::legs);

        if (randomNumber <= targetPriorities::head) {
            skillFunctions::attack (user, target, target.bodyParts [0]);
        } else if (randomNumber <= targetPriorities::head + targetPriorities::torso) {
            skillFunctions::attack (user, target, target.bodyParts [1]);
        } else {
            if (target.bodyParts [2].health <= 0) {
                skillFunctions::attack (user, target, target.bodyParts [utilityFunctions::random (0, 1)]);
            } else {
                skillFunctions::attack (user, target, target.bodyParts [2]);
            }
        }
    } else if (randomNumber <= PARRY_CHANCE+ATTACK_CHANCE) {
        skillFunctions::parry (user, user.bodyParts [0]);
    }
}
