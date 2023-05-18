#include "Cowboy.hpp"
#include "Character.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace ariel;

Cowboy::Cowboy(string name, Point poi)
    : Character(name, poi, 110), _num_of_bullets(6)
{
}

// this func can throw an exception
void Cowboy::shoot(Character *player)
{
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
    if (this->hasboolets())
    {
        this->subNumOfBullets(1); //one less bullet
        player->subHitPoints(10); //-10 to player
    }
}

bool Cowboy::hasboolets()
{
    if(this->getNumOfBullets() > 0)
    {
        return true;
    }
    return false;
}

// this func can throw an exception
void Cowboy::reload()
{
    if(!this->isAlive())
    {
        throw runtime_error("a dead Character can't reload"); // throw an exception
    }
    this->setNumOfBullets(6);
}

// virtual
// virtual Cowboy::~Cowboy(){}

string Cowboy::print()
{
    string str;
    if (this->isAlive())
    {
        str = "(C) name: " + this->getName() + " , hit points: " + to_string(this->getHitPoints()) + " , location: " + this->getLocation().print();
    }
    else
    {
        str = "(C) name: (" + this->getName() + ") , location: " + this->getLocation().print();
    }
    return str;
}

// get
int Cowboy::getNumOfBullets(){
    return this->_num_of_bullets;
}
// set
void Cowboy::setNumOfBullets(int num){
    if(num > 0)
    {
        this->_num_of_bullets = num;
    }
}

void Cowboy::subNumOfBullets(int num){
    if(num > 0)
    {
        this->_num_of_bullets -= num;
    }
}
