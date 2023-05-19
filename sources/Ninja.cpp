#include "Ninja.hpp"
#include "Character.hpp"
#include <stdexcept>

using namespace std;
using namespace ariel;

Ninja::Ninja(string name, Point poi, int hit, int speed)
: Character(name, poi, hit), _speed(speed){
}

// this func can throw an exception
void Ninja::move(Character *player){
    if(!this->isAlive())
    {
        throw runtime_error("a dead Character can't move"); // throw an exception
    }
    Point new_loc = Point::moveTowards(this->getLocation(), player->getLocation(), this->_speed);
    this->setLocation(new_loc);
}

// this func can throw an exception
void Ninja::slash(Character *player){
    if(!this->isAlive())
    {
        throw runtime_error("a dead Character can't attack"); // throw an exception
    }
    if(!player->isAlive())
    {
        throw runtime_error("can't attack a dead Character"); // throw an exception
    }
    if(this == player)
    {
        throw runtime_error("can't attack himself"); // throw an exception
    }
    if((this->getLocation().distance(player->getLocation()) < 1))
    {
        player->subHitPoints(40);
    }
}
