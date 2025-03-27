#ifndef POINT_H
#define POINT_H

class Point {
    private:
        double x;
        double y;
    
    public:
        Point(double x = 0.0, double y = 0.0);
        double get_x();
        double get_y();
};

#endif // POINT_H
