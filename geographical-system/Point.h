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
        int distance_from_center(Point center);
        // != operator
        bool operator!=(const Point& other) const;
};

#endif // POINT_H
