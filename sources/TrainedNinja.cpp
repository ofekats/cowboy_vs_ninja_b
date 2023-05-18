#include "TrainedNinja.hpp"
#include "Character.hpp"
#include "Ninja.hpp"

using namespace std;
using namespace ariel;

TrainedNinja::TrainedNinja(string name, Point poi)
: Ninja(name ,poi, 120, 12){
}

string TrainedNinja::print()
{
    string str;
    if (this->isAlive())
    {
        str = "(N<Trained>) name: " + this->getName() + " , hit points: " + to_string(this->getHitPoints()) + " , location: " + this->getLocation().print();
    }
    else
    {
        str = "(N<Trained>) name : (" + this->getName() + ") , location: " + this->getLocation().print();
    }
    return str;
}