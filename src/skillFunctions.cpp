#include <iostream>
#include "skillFunctions.h"

void skillFunctions::do_nothing (Entity &user, Entity &target) {
    std::cout << user.name << " did nothing!" << std::endl;

}

