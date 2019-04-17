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

        void loop ();
    private:
        bool factionHasAliveMembers (std::vector <Entity> faction);

        void displayCombatantStats (Entity &player, std::vector <Entity> &enemies);

        void displayPlayerStats (Entity &player);

        void inputPlayerTarget (Entity &player, std::vector <Entity> &enemies);

        int getGuardTargetIndex (Entity &player);

};

#endif // GAME_H
