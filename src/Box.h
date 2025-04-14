#ifndef BOX_H
#define BOX_H

#include "Point.h" 

class Box {
private:
    Point center;
    double width, height;
    
    

public:
    Box(Point center, double width, double height);
    bool contains_point(Point point);
    Point get_center();
    double get_height();
    double get_width();
    bool intersects(Box range);
    double west = center.get_x() - width;
    double east = center.get_x() + width;
    double north = center.get_y() - height; //y increases in the down direction hence the "- height"
    double south = center.get_y() + height;
};

#endif // BOX_H
