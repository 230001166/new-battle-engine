#include <iostream>
#include "onDestructionFunctions.h"
#include "Entity.h"

void onDestructionFunctions::legs (Entity &parent) {
    parent.defaultSpeed /= 2;
}

void onDestructionFunctions::chimeraEye (Entity &parent) {
    parent.status = "vulnerable"; parent.statusTurnsLeft = 99;
}

void onDestructionFunctions::chimeraArms (Entity &parent) {
    parent.weapon.attack *= 0.70;
}

void onDestructionFunctions::doNothing (Entity &parent) { }
