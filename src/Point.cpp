#include "Point.h"
#include <cmath>
Point::Point(double x, double y) : x(x), y(y) {}

double Point::get_x(){
    return x;
}

double Point::get_y(){
    return y;
}

int Point::distance_from_center(Point center){
    return sqrt(pow((this->x-center.x ),2) + pow((this->y-center.y ),2));
}

bool Point::operator!=(const Point& other) const {
    return (x != other.x || y != other.y);
}

bool Point::operator==(const Point& other) const {
    return (x == other.x && y == other.y);
}
