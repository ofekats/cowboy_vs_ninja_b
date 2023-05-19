#pragma once
#include "Team.hpp"

namespace ariel
{
    class SmartTeam : public Team
    {
        public:
            SmartTeam(Character *leader);
            // virtual
            void attack(Team *enemy_team) override;
            int stillAlive() override;
            void print() override;
    };
    //choose enemy the same as team
    //choose new leader the same team
    //attack- go as added - cowboy the same
    //                    - ninja will checks if someone from enemy team close - if so will slash him
    //                                                                           else will get close to leader
}