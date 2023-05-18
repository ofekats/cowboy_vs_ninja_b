#include "Point.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>


using namespace ariel;
using namespace std;

Point::Point(double x_poi, double y_poi)
    : _x_point(x_poi), _y_point(y_poi)
{
}

double Point::distance(Point diff)
{
    // d = √((x2 - x1)² + (y2 - y1)²)
    double x2_x1 = diff.getX() - this->_x_point;
    double y2_y1 = diff.getY() - this->_y_point;
    double dis = pow(x2_x1, 2) + pow(y2_y1, 2);
    return sqrt(dis);
}

string Point::print()
{
    string s = "(" + to_string(this->_x_point) + "," + to_string(this->_y_point) + ")";
    return s;

}

// this func can throw an exception
Point Point::moveTowards(Point src, Point dst, double dis_got)
{
    if(dis_got < 0)
    {
        throw invalid_argument("distance can't be less than 0"); // throw an exception
    }
    //the dest point in a good distance
    double dis_src_dst = src.distance(dst);
    if(dis_src_dst <= dis_got)
    {
        return dst;
    }
    //need to calculate better point
    //src = (x1,y1), dst = (x2,y2)
    // x = x1 + ((x2 - x1) * dis_got / dis_src_dst)
    // y = y1 + ((y2 - y1) * dis_got / dis_src_dst)
    double new_dis = dis_got / dis_src_dst;
    double newX = src.getX() + ((dst.getX() - src.getX()) * new_dis);
    double newY = src.getY() + ((dst.getY() - src.getY()) * new_dis);
    return Point(newX, newY);
}

// get
double Point::getX()
{
    return this->_x_point;
}
double Point::getY()
{
    return this->_y_point;
}

// set
void Point::setX(double num_x)
{
    this->_x_point = num_x;
}

void Point::setY(double num_y)
{
    this->_y_point = num_y;
}