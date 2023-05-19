#pragma once
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <array>

using namespace std;
const int MAX_TEAM_SIZE = 10;

namespace ariel
{
    class Team
    {
    public:
        Team(Character *leader);

        // Declare special member functions as deleted
        Team(const Team &) = delete;            // Copy constructor
        Team &operator=(const Team &) = delete; // Copy assignment operator
        Team(Team &&) = delete;                 // Move constructor
        Team &operator=(Team &&) = delete;      // Move assignment operator
        
        Character *choose_closes_to_this_leader(Team *team);
        void add(Character *player);
        // virtual
        virtual ~Team();
        virtual void attack(Team *enemy_team);
        virtual int stillAlive();
        virtual void print();

        // get
        array<Character*, MAX_TEAM_SIZE>& getTeam();
        Character *getLeader();
        int getSize();
        // set
        void setLeader(Character *new_leader);
        void setSize(int num);

        void addSize(int num);

    private:
        array<Character*, MAX_TEAM_SIZE> team;
        Character *_leader;
        int size;
    };
}