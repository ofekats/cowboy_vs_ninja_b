#pragma once
#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
    public:
        Cowboy(string name, Point poi);
        void shoot(Character *player);
        bool hasboolets();
        void reload();

        //virtual
        string print() override;

        //get
        int getNumOfBullets();
        //set
        void setNumOfBullets(int num);

        void subNumOfBullets(int num);

    private:
        int _num_of_bullets;
    };
}