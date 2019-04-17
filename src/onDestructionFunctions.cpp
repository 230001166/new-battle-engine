#include <iostream>
#include "onDestructionFunctions.h"
#include "Entity.h"

void onDestructionFunctions::legs (Entity &parent) {
    parent.defaultSpeed /= 2;
}

void onDestructionFunctions::doNothing (Entity &parent) { }
