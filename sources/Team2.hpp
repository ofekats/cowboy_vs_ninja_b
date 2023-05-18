#pragma once
#include "Team.hpp"

namespace ariel
{
    class Team2 : public Team
    {
    public:
        Team2(Character * leader);
        Character * choose_closes_to_this_leader(Team * team);
        //virtual
        virtual void attack(Team *enemy_team) override;
        virtual int stillAlive() override;
        virtual void print() override;

    };
}