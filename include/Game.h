#ifndef GAME_H
#define GAME_H
#include "Entity.h"

class Game
{
    public:
        Game();
        virtual ~Game();

        Entity createEntityFromName (std::string name);

        void battle (std::vector <Entity> &combatants);

        void loop ();

    private:
        bool factionHasAliveMembers (std::vector <Entity> combatants, std::string faction);

        void displayCombatantStats (std::vector <Entity> &combatants);

        void displayPlayerStats (Entity &player);

        void inputPlayerTarget (Entity &player, std::vector <Entity> &combatants);

        int getGuardTargetIndex (Entity &player);

};

#endif // GAME_H
