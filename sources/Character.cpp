#include "Character.hpp"
#include <stdexcept>

using namespace ariel;

Character::Character(string name, Point poi, int hit)
    : _name(name), _location(poi), _hit_points(hit), is_leader(false)
{
}

bool Character::isAlive()
{
    // is alive when _hit_points > 0
    if (this->_hit_points > 0)
    {
        return true;
    }
    return false;
}

double Character::distance(Character *player)
{
    //use Point distance func
    return this->_location.distance(player->getLocation());
}

// this func can throw an exception
void Character::hit(int num)
{
    if (num < 0)
    {
        throw invalid_argument("hit can't be less than 0"); // throw an exception
    }
    this->subHitPoints(num);
}

// get
Point Character::getLocation()
{
    return this->_location;
}

int Character::getHitPoints()
{
    return this->_hit_points;
}

bool Character::getIsLeader()
{
    return this->is_leader;
}

bool Character::getInTeam()
{
    return this->in_team;
}

string Character::getName()
{
    return this->_name;
}

// set
void Character::setName(string new_name)
{
    this->_name = new_name;
}
void Character::setLocation(Point new_loc)
{
    this->_location = new_loc;
}
void Character::setHitPoints(int new_hit)
{
    this->_hit_points = new_hit;
}
void Character::setIsLeader(bool isLeader)
{
    this->is_leader = isLeader;
}
void Character::setInTeam(bool isinteam)
{
    this->in_team = isinteam;
}

void Character::subHitPoints(int sub_hit)
{
    if (sub_hit > 0)
    {
        this->_hit_points -= sub_hit;
    }
}
