#include "YoungNinja.hpp"
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"

using namespace std;
using namespace ariel;

YoungNinja::YoungNinja(string name, Point poi)
: Ninja(name ,poi, 100, 14){
}

string YoungNinja::print()
{
    string str;
    if (this->isAlive())
    {
        str = "(N<Young>) name: " + this->getName() + " , hit points: " + to_string(this->getHitPoints()) + " , location: " + this->getLocation().print();
    }
    else
    {
        str = "(N<Young>) name: (" + this->getName() + ") , location: " + this->getLocation().print();
    }
    return str;
}