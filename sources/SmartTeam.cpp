#include "SmartTeam.hpp"
#include <stdexcept>
#include <iostream>

using namespace ariel;

SmartTeam::SmartTeam(Character *leader)
    : Team(leader)
{
}

// virtual
void SmartTeam::attack(Team *enemy_team)
{
    if (enemy_team == NULL)
    {
        throw invalid_argument("NULL ptr to team"); // throw an exception
    }
    if (enemy_team->stillAlive() <= 0)
    {
        throw runtime_error("can't attack dead team"); // throw an exception
    }
    if (!(this->getLeader())->isAlive()) // if the leader of our team is dead
    {
        Character *new_leader = this->choose_closes_to_this_leader(this);
        if (new_leader != NULL)
        {
            this->setLeader(new_leader);
        }
        else
        {
            return;
        }
    }
    Character *new_victim = this->choose_closes_to_this_leader(enemy_team);
    if (new_victim == NULL)
    {
        return;
    }

    // attack
    for (size_t i = 0; i < this->getSize(); ++i)
    {
        if (dynamic_cast<Cowboy *>(this->getTeam()[i]) != NULL) // cowboy first
        {
            if (this->getTeam()[i]->isAlive()) // if alive
            {
                Cowboy *cowboy = dynamic_cast<Cowboy *>(this->getTeam()[i]);
                // if has bullets shoot else reload
                if (cowboy->getNumOfBullets() > 0)
                {
                    cowboy->shoot(new_victim);
                }
                else
                {
                    cowboy->reload();
                }
            }
        }
        else if (dynamic_cast<Ninja *>(this->getTeam()[i]) != NULL) // ninja second
        {
            if (this->getTeam()[i]->isAlive()) // if alive
            {
                Ninja *ninja = dynamic_cast<Ninja *>(this->getTeam()[i]);
                // instead of- if victim close slash else move closer to victim
                // smartTeam do - slash if any of the enemy is close else move toward our leader
                Character *closes_to_ninja = NULL;
                int slash = 0;
                for (size_t j = 0; j < enemy_team->getSize(); ++j)
                {
                    closes_to_ninja = enemy_team->getTeam()[j];
                    if (closes_to_ninja->isAlive())
                    {
                        if (this->getTeam()[i]->distance(closes_to_ninja) <= 1)
                        {
                            ninja->slash(closes_to_ninja);
                            slash = 1;
                            break;
                        }
                    }
                }
                if (!slash)
                {
                    ninja->move(this->getLeader());
                }
            }
        }
        if (!new_victim->isAlive())
        {
            new_victim = this->choose_closes_to_this_leader(enemy_team);
            if (new_victim == NULL)
            {
                return;
            }
        }
    }
}

int SmartTeam::stillAlive()
{
    int count = 0;
    for (size_t i = 0; i < this->getSize(); ++i)
    {
        if (this->getTeam()[i]->isAlive())
        {
            count++;
        }
    }
    return count;
}
void SmartTeam::print()
{
    for (size_t i = 0; i < this->getSize(); ++i)
    {

        cout << this->getTeam()[i]->print() << endl;
    }
}