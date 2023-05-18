#pragma once
#include <string>

using namespace std;

namespace ariel
{
    class Point
    {
    public:
        Point(double x_poi = 0.0, double y_poi = 0.0);
        double distance(Point diff);
        string print();
        static Point moveTowards(Point src, Point dst, double dis_got);

        //get
        double getX();
        double getY();
        //set
        void setX(double num_x);
        void setY(double num_y);
    private:
        double _x_point;
        double _y_point;
    };
}