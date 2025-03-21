#ifndef BOX_H
#define BOX_H

class Box {
private:
    double xMin, xMax, yMin, yMax;

public:
    Box(double xMin, double xMax, double yMin, double yMax);

    double getXMin() const;
    double getXMax() const;
    double getYMin() const;
    double getYMax() const;

    bool contains(double x, double y) const;
    bool intersects(const Box& other) const;
};

#endif // BOX_H