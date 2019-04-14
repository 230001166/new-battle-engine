#ifndef SKILLFUNCTIONS_H
#define SKILLFUNCTIONS_H
#include "Entity.h"

namespace skillFunctions
{
    void do_nothing (Entity &user, Entity &enemy, bodyPart &target);

    void attack (Entity &user, Entity &enemy, bodyPart &target);
};

#endif // SKILLFUNCTIONS_H
