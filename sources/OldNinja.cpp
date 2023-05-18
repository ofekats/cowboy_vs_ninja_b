#include "OldNinja.hpp"
#include "Character.hpp"
#include "Ninja.hpp"

using namespace std;
using namespace ariel;

OldNinja::OldNinja(string name, Point poi)
: Ninja(name ,poi, 150, 8){
}

string OldNinja::print()
{
    string str;
    if (this->isAlive())
    {
        str = "(N<Old>) name: " + this->getName() + " , hit points: " + to_string(this->getHitPoints()) + " , location: " + this->getLocation().print();
    }
    else
    {
        str = "(N<Old>) name: (" + this->getName() + ") , location: " + this->getLocation().print();
    }
    return str;
}