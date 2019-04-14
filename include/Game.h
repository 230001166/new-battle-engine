#ifndef GAME_H
#define GAME_H
#include "Entity.h"

class Game
{
    public:
        Game();
        virtual ~Game();

        Entity createEntityFromName (std::string name);
    protected:

    private:
};

#endif // GAME_H
