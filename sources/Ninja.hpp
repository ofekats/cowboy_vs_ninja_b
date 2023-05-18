#pragma once
#include "Character.hpp"

//can't create an object of Ninja type
namespace ariel
{
    class Ninja: public Character
    {
    public:
        Ninja(string name, Point poi, int hit, int speed);
        void move(Character *player);
        void slash(Character *player);

        // virtual
        virtual ~Ninja() = default;
        virtual string print() override = 0; // pure virtual

    private:
        int _speed;
    };
}