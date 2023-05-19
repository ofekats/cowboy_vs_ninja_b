#include "Team2.hpp"
#include <stdexcept>
#include <climits>
#include <iostream>

using namespace ariel;

// this func can throw an exception
Team2::Team2(Character *leader)
    : Team(leader)
{
}

Character *Team2::choose_closes_to_this_leader(Team *team)
{
    int min_dis = INT_MAX;
    Character *new_leaderVictim = NULL;
    for (int i = 0; i < team->getSize(); ++i)
    {
        if (team->getTeam()[(size_t)i]->isAlive() && team->getTeam()[(size_t)i] != this->getLeader()) // if this teammate alive and not the leader
        {
            // calculate the distance between dead leader and this teammate
            double new_dis = this->getLeader()->getLocation().distance(team->getTeam()[(size_t)i]->getLocation());
            if (new_dis < min_dis)
            {
                min_dis = new_dis;
                new_leaderVictim = team->getTeam()[(size_t)i];
            }
        }
    }
    return new_leaderVictim;
}

// this func can throw an exception
void Team2::attack(Team *enemy_team)
{
    if(enemy_team == NULL)
    {
        throw invalid_argument("NULL ptr to team"); // throw an exception
    }
    if(enemy_team->stillAlive() <= 0)
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
    for (int i = 0; i < this->getSize(); ++i)
    {
        if (dynamic_cast<Cowboy *>(this->getTeam()[(size_t)i]) != NULL) // cowboy first
        {
            if (this->getTeam()[(size_t)i]->isAlive()) // if alive
            {
                Cowboy *cowboy = dynamic_cast<Cowboy *>(this->getTeam()[(size_t)i]);
                //if has bullets shoot else reload
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
        else if (dynamic_cast<Ninja *>(this->getTeam()[(size_t)i]) != NULL) // ninja second
        {
            if (this->getTeam()[(size_t)i]->isAlive()) // if alive
            {
                Ninja *ninja = dynamic_cast<Ninja *>(this->getTeam()[(size_t)i]);
                //if victim close slash else move closer to victim
                if (ninja->distance(new_victim) <= 1)
                {
                    ninja->slash(new_victim);
                }
                else
                {
                    ninja->move(new_victim);
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

int Team2::stillAlive()
{
    int count = 0;
    for (int i = 0; i < this->getSize(); ++i)
    {
        if (this->getTeam()[(size_t)i]->isAlive())
        {
            count++;
        }
    }
    return count;
}

void Team2::print()
{
    for (int i = 0; i < this->getSize(); ++i)
    {

        cout << this->getTeam()[(size_t)i]->print() << endl;
    }
}