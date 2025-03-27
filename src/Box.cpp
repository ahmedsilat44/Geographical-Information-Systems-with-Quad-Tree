#include "Box.h"

Box::Box(Point center, double width, double height): center(center), height (height), width (width) {}

bool Box::contains_point(Point point){
    bool result = (west <= point.get_x() && point.get_x() <= east) &&
                  (north <= point.get_y() && point.get_y() <= south);

    return result;
}

Point Box::get_center(){
    return center;
}

double Box::get_width(){
    return width;
}

double Box::get_height(){
    return height;
}
