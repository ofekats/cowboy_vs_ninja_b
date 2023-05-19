#include "Team.hpp"
#include <stdexcept>
#include <climits>
#include <iostream>

using namespace ariel;

// this func can throw an exception
Team::Team(Character *leader)
    : size(1), _leader(leader), team{leader} // team[0] = leader
{
    if (leader->getIsLeader())
    {
        throw runtime_error("leader is already in a different team"); // throw an exception
    }
    for (int i = 1; i < 10; ++i)
    {
        team[(size_t)i] = NULL;
    }
    leader->setIsLeader(true);
}

Team::~Team(){
    for(int i=0; i<this->size; ++i)
    {
        this->team[(size_t)i]->setIsLeader(false);
        this->team[(size_t)i]->setInTeam(false);
        delete this->team[(size_t)i];
    }
}

Character *Team::choose_closes_to_this_leader(Team *team)
{
    int min_dis = INT_MAX;
    Character *new_leaderVictim = NULL;
    for (int j = 0; j < 2; ++j)
    {
        int check_this = 0;
        for (int i = 0; i < team->getSize(); ++i)
        {
            if ((j == 0) && dynamic_cast<Cowboy *>(team->getTeam()[(size_t)i]) != NULL) // cowboy first
            {
                check_this = 1;
            }
            else if ((j == 1) && dynamic_cast<Ninja *>(team->getTeam()[(size_t)i]) != NULL) // ninja second
            {
                check_this = 1;
            }
            if (check_this && team->getTeam()[(size_t)i]->isAlive() && team->getTeam()[(size_t)i] != this->_leader) // if this teammate alive and not the leader
            {
                // calculate the distance between dead leader and this teammate
                double new_dis = this->_leader->getLocation().distance(team->getTeam()[(size_t)i]->getLocation());
                if (new_dis < min_dis)
                {
                    min_dis = new_dis;
                    new_leaderVictim = team->getTeam()[(size_t)i];
                }
            }
            check_this = 0;
        }
    }
    return new_leaderVictim;
}

// this func can throw an exception
void Team::add(Character *player)
{
    if (this->size == 10)
    {
        throw runtime_error("too many Characters in this team"); // throw an exception
    }
    if (player->getIsLeader())
    {
        throw runtime_error("player is already in a different team"); // throw an exception
    }
    if (player->getInTeam())
    {
        throw runtime_error("player is already in a different team"); // throw an exception
    }
    player->setInTeam(true);
    team[(size_t)size] = player;
    this->addSize(1);
}

// this func can throw an exception
void Team::attack(Team *enemy_team)
{
    if(enemy_team == NULL)
    {
        throw invalid_argument("NULL ptr to team"); // throw an exception
    }
    if(enemy_team->stillAlive() <= 0)
    {
        throw runtime_error("can't attack dead team"); // throw an exception
    }
    if (!(this->_leader)->isAlive()) // if the leader of our team is dead
    {
        Character *new_leader = this->choose_closes_to_this_leader(this);
        if (new_leader != NULL)
        {
            this->_leader->setIsLeader(false);
            this->_leader = new_leader;
            this->_leader->setIsLeader(true);
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
    for (int i = 0; i < this->size; ++i)
    {
        if (dynamic_cast<Cowboy *>(team[(size_t)i]) != NULL) // cowboy first
        {
            if (team[(size_t)i]->isAlive()) // if alive
            {
                Cowboy *cowboy = dynamic_cast<Cowboy *>(team[(size_t)i]);
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
        if (!new_victim->isAlive())
        {
            new_victim = this->choose_closes_to_this_leader(enemy_team);
            if (new_victim == NULL)
            {
                return;
            }
        }
    }
    for (int i = 0; i < this->size; ++i)
    {
        if (dynamic_cast<Ninja *>(team[(size_t)i]) != NULL) // ninja second
        {
            if (team[(size_t)i]->isAlive()) // if alive
            {
                Ninja *ninja = dynamic_cast<Ninja *>(team[(size_t)i]);
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

int Team::stillAlive()
{
    int count = 0;
    for (int j = 0; j < 2; ++j)
    {
        int check_this = 0;
        for (int i = 0; i < this->size; ++i)
        {
            if ((j == 0) && dynamic_cast<Cowboy *>(this->team[(size_t)i]) != NULL) // cowboy first
            {
                check_this = 1;
            }
            else if ((j == 1) && dynamic_cast<Ninja *>(this->team[(size_t)i]) != NULL) // ninja second
            {
                check_this = 1;
            }
            if (check_this)
            {
                if (team[(size_t)i]->isAlive())
                {
                    count++;
                }
            }
            check_this = 0;
        }
    }
    return count;
}

void Team::print()
{
    for (int j = 0; j < 2; ++j)
    {
        int check_this = 0;
        for (int i = 0; i < this->size; ++i)
        {
            if ((j == 0) && dynamic_cast<Cowboy *>(this->team[(size_t)i]) != NULL) // cowboy first
            {
                check_this = 1;
            }
            else if ((j == 1) && dynamic_cast<Ninja *>(this->team[(size_t)i]) != NULL) // ninja second
            {
                check_this = 1;
            }
            if (check_this)
            {
                cout << team[(size_t)i]->print() << endl;
            }
            check_this = 0;
        }
    }
}

// get
array<Character*, MAX_TEAM_SIZE>& Team::getTeam()
{
    return (this->team);
}

Character *Team::getLeader()
{
    return this->_leader;
}

int Team::getSize()
{
    return this->size;
}

// set
void Team::setLeader(Character *new_leader)
{
    this->_leader = new_leader;
}

void Team::setSize(int num)
{
    if (num >= 0 && num <= 10)
    {
        this->size = num;
    }
}

void Team::addSize(int num)
{
    if ((this->size + num) >= 0 && (this->size + num) <= 10)
    {
        this->size += num;
    }
}