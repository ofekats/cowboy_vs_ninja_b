#pragma once
#include "Team.hpp"

namespace ariel
{
    class Team2 : public Team
    {
    public:
        Team2(Character *leader);
        // virtual
        Character *choose_closes_to_this_leader(Team *team) override;
        void attack(Team *enemy_team) override;
        int stillAlive() override;
        void print() override;
    };
}