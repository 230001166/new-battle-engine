#ifndef GAME_H
#define GAME_H
#include "Entity.h"

class Game
{
    public:
        Game();
        virtual ~Game();

        Entity createEntityFromName (std::string name);

        void battle (Entity &player, std::vector <Entity> &enemies);

    private:
        bool factionHasAliveMembers (std::vector <Entity> faction);

        void displayPlayerStats (Entity &player);
};

#endif // GAME_H
