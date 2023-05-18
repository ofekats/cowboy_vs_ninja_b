#pragma once
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"

namespace ariel
{
    class Team
    {
    public:
        Team(Character * leader);
        ~Team() = default;
        Character * choose_closes_to_this_leader(Team * team);
        void add(Character *player);
        //virtual
        virtual void attack(Team *enemy_team);
        virtual int stillAlive();
        virtual void print();

        //get
        Character** getTeam();
        Character * getLeader();
        int getSize();
        //set
        void setLeader(Character * new_leader);
        void setSize(int num);

        void addSize(int num);

    private:
        Character *team[10];
        Character * _leader;
        int size;
    };
}