#pragma once
#include "Point.hpp"
#include <string>

using namespace std;

//can't create an object of Character type
namespace ariel
{
    class Character
    {
    public:
        Character(string name, Point poi, int hit=0);

        //virtual
        virtual ~Character() = default;
        virtual string print() =0; //pure virtual

        bool isAlive();
        double distance(Character *player);
        void hit(int num);
        
        //get
        string getName();
        Point getLocation();
        int getHitPoints();
        bool getIsLeader();
        bool getInTeam();
        //set
        void setName(string new_name);
        void setLocation(Point new_loc);
        void setHitPoints(int new_hit);
        void setIsLeader(bool isLeader);
        void setInTeam(bool isinteam);

        void subHitPoints(int sub_hit);

    private:
        Point _location;
        int _hit_points;
        string _name;
        bool is_leader;
        bool in_team;
    };
}